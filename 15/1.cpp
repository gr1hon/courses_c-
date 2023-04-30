#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> sums(vec.size());
    sums[0] = vec[0];
    int max = sums[0];
    int min = sums[0];
    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 1; i < vec.size(); ++i) {
        sums[i] = sums[i-1] + vec[i];
        if(sums[i] > max){
            maxIndex = i;
            max = sums[i];
        }
    }
    for (int i = 0; i < maxIndex; ++i) {
        if (min >= sums[i]){
            min = sums[i];
            minIndex = i + 1;
        }
    }
    cout << minIndex << " " << maxIndex;
}
