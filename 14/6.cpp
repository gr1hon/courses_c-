#include <iostream>

using namespace std;

void print(int a[5][5]){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <5; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    int a[5][5];
    int number = 0;
    int count = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            a[i][4 * (i % 2) + j*count] = number;
            number += 1;
        }
        count = -count;
    }
    print(a);
}
