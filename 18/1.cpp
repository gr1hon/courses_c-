#include <iostream>
#include <vector>

using namespace std;

void swapvec(vector<int>& a, int b[]){
    for (int i = 0; i < a.size(); ++i) {
        swap(a[i], b[i]);
    }
}

int main() {
    vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    swapvec(a,b);

    for(int i = 0; i < 4; ++i)
        std::cout << a[i];
    cout << endl;

    for(int i = 0; i < 4; ++i)
        std::cout << b[i];
}
