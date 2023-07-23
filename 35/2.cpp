#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>

using namespace std;

auto lambda = [](vector<int>& v){
    unordered_set<int> set;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (!set.count(*it)){
            set.insert(*it);
//            cout << "insert to set " << *it << endl;
        }

        else{
//            cout << "delete " << *it << endl;
            v.erase(it);
            it--;
        }

    }
    unique_ptr<std::vector<int>> ans = make_unique<vector<int>>(v);
    for (auto& x : *ans) {
        cout << x << endl;
    }
    return ans;
};

int main(){
    vector<int> v = {10,10,1,1,1,2,2,2,2,2,2,3,5,5,5};
    lambda(v);
}
