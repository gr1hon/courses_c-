#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> vec = {2, 7, 11, 15};
    int res = 9;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[i] + vec[j] == res){
                cout << vec[i] << " " << vec[j];
                return 0;
            }
        }
    }
}
