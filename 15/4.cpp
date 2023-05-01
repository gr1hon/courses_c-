#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec = {-100, -20, -10, 0};
    vector<int> positive;
    vector<int> negative;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] < 0){
            negative.push_back(vec[i]);
        } else positive.push_back(vec[i]);
    }

    int countP = 0;
    int countN = negative.size()-1;

    for (int i = 0; i < vec.size(); ++i) {
        if(positive[countP] > -negative[countN]){
            vec[i] = negative[countN];
            countN--;
        } else{
            vec[i] = positive[countP];
            countP++;
        }
    }

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
}
