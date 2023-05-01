#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> vec){
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size()-i-1; ++j) {
            if (vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
    return vec;
}

int main(){
    vector<int> vec;
    int number = 0;
    while(number != -2){
        cin >> number;
        if (number != -1){
            vec.push_back(number);
        } else if (vec.size() < 5){
            cout << "Count of vec less than 5!\n";
        } else{
            vec = sort(vec);
            cout <<  vec[4] << "\n";
        }
    }
    cout << "End";
}
