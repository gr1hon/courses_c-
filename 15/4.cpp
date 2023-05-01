#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec = {-100, 1, 3, 6, 10};
    vector<int> answer(vec.size());
    int countP = -1;
    int countN = -1;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] >= 0 && vec[i-1] < 0){
            countN = i - 1;
            countP = i;
            break;
        }
    }
    if (countP == -1 && vec[0] < 0){
        for (int i = 0; i < vec.size(); ++i) {
            answer[i] = vec[vec.size()-1-i];
        }
    } else if (countN == -1){
        for (int i = 0; i < vec.size(); ++i) {
            answer[i] = vec[i];
        }
    } else{
        for (int i = 0; i < vec.size(); ++i) {
            if(countP == vec.size() || vec[countP] > -vec[countN] && countN >= 0){
                answer[i] = vec[countN];
                countN--;
            } else {
                answer[i] = vec[countP];
                countP++;
            }
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        cout << answer[i] << " ";
    }
}
