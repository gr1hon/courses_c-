#include <iostream>

using namespace std;

bool equals(int a[4][4], int b[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}

void toDioganal(int a[4][4]){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j){
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    int a[4][4]; int b[4][4];

    cout << "Enter first matrix:";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j];
        }
    }

    cout << "Enter second matrix:";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> b[i][j];
        }
    }

    if (equals(a,b)){
        toDioganal(a);
        cout << "Matrices are equal!\n";
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    } else{
        cout << "Matrices are not equal!\n";
    }
}
