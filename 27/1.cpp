#include <iostream>
#include <vector>

using namespace std;

class Branch{

private:
    string elfName {};
    Branch* parent = nullptr;
    vector<Branch*> children;
    int childNumber = 0;

public:
    Branch* getChildren(int i){
        return this->children[i];
    }

    string getElfName(){
        return elfName;
    }

    void setElfName(string elfName) {
        this->elfName = elfName;
    }

    void addChild(){
        auto* branch = new Branch();
        branch->parent = this;
        branch->childNumber = children.size();
        children.push_back(branch);
    }

    bool isThereElf(string name){
        if (!this->elfName.empty() && this->elfName == name){
            return true;
        } else{
            for (int i = 0; i < this->children.size(); ++i) {
                cout << "* ";
                this->children[i]->isThereElf(name);
            }
        }
    }

    int bigBranchNumber(string in_elfName){
        if (this->elfName == in_elfName){
            if (parent->parent == nullptr) return childNumber;
            return parent->childNumber;
        } else{
            for (int i = 0; i < children.size(); ++i) {
                children[i]->bigBranchNumber(in_elfName);
            }
        }
    }

    int neighbors(){
        int count = -1;
        if (!this->elfName.empty())
            count++;
        for (int i = 0; i < children.size(); ++i) {
            if (!children[i]->elfName.empty()){
                count++;
            }
        }
        return count;
    }

};

int max(vector<int> vec){
    int ans = vec[0];
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > ans)
            ans = vec[i];
    }
    return ans;
}

void initialization(vector<Branch>& branches){
    for (int i = 0; i < 1; ++i) { // 5
        auto* branch = new Branch();
        int b1 = 1; //  rand() %3 + 3
        for (int j = 0; j < b1; ++j) {
            branch->addChild();
            cout << "Enter the name of the elf on " << i+1 << " tree, " <<  j + 1 << " big branch:" << endl;
            string name;
            cin >> name;
            if (name != "None"){
                branch->getChildren(j)->setElfName(name);
            }
            int b2 = 3; // rand() % 2 + 2
            for (int k = 0; k < b2; ++k) {
                branch->getChildren(j)->addChild();
                cout << "Enter the name of the elf on " << i+1 << " tree, " << j + 1 << " big branch, "
                    << k + 1 << " small branch:" << endl;
                cin >> name;
                if (name != "None"){
                    branch->getChildren(j)->getChildren(k)->setElfName(name);
                }
            }
        }
        branches.push_back(*branch);
    }
}

int main() {
    srand(time(nullptr));
    vector<Branch> trees;
    initialization(trees);
    string name;
    cout << "Enter the name of the elf you want to find:" << endl;
    cin >> name;
    vector<int> neighbors;
    for (int i = 0; i < trees.size(); ++i) {
        cout << trees[i].isThereElf(name) << endl;
//        if (trees[i].isThereElf(name))
//            neighbors.push_back(trees[i].getChildren(trees[i].bigBranchNumber(name))->neighbors());
//        else
//            cout << "The elf with the name " << name << " was not found" << endl;
    }
//    int ans = max(neighbors);
//    cout << "Elf " << name << " has " << ans << " neighbors" << endl;
}
