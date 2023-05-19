#include <iostream>
#include <vector>

using namespace std;

class Branch{

private:
    string elfName {};
    vector<Branch*> children;

public:
    Branch* getChildren(int i){
        return this->children[i];
    }

    string getElfName(){
        return elfName;
    }

    void setElfName(string in_elfName) {
        this->elfName = in_elfName;
    }

    void addChild(){
        auto* branch = new Branch();
        children.push_back(branch);
    }

    bool isThereElf(const string& in_elfName){
        for (int i = 0; i < this->children.size(); ++i) {
            if (this->children[i]->getElfName() == in_elfName)
                return true;
            for (int j = 0; j < this->children[i]->children.size(); ++j) {
                if (this->children[i]->children[j]->getElfName() == in_elfName)
                    return true;
            }
        }
        return false;
    }

    int bigBranchNumber(const string& in_elfName){
        for (int i = 0; i < this->children.size(); ++i) {
            if (this->children[i]->getElfName() == in_elfName)
                return i;
            for (int j = 0; j < this->children[i]->children.size(); ++j) {
                if (this->children[i]->children[j]->getElfName() == in_elfName)
                    return i;
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

void initialization(vector<Branch*>& branches){
    for (int i = 0; i < 2; ++i) { // 5, тестить долго
        auto* branch = new Branch();
        int b1 = rand() %3 + 3;
        for (int j = 0; j < b1; ++j) {
            branch->addChild();
            cout << "Enter the name of the elf on " << i+1 << " tree, " <<  j + 1 << " big branch:" << endl;
            string name;
            cin >> name;
            if (name != "None"){
                branch->getChildren(j)->setElfName(name);
            }
            int b2 = rand() % 2 + 2;
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
        branches.push_back(branch);
    }
}

int main() {
    srand(time(nullptr));
    vector<Branch*> trees;
    initialization(trees);
    string name;
    cout << "Enter the name of the elf you want to find:" << endl;
    cin >> name;
    vector<int> neighbors;
    for (int i = 0; i < trees.size(); ++i) {
        if (trees[i]->isThereElf(name)){
            cout << "Elf " << name << " has " <<trees[i]->getChildren(trees[i]->bigBranchNumber(name))->neighbors() <<  " neighbors" << endl;
            return 0;
        }
        delete trees[i];
    }
    cout << "The elf with the name " << name << " was not found" << endl;
}
