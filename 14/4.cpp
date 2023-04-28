#include <iostream>

using namespace std;

int main() {
    float a[4][4];
    float b[4];
    float c[4];
    float k = 0.f;
    cout << "Enter matrix:";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j];
        }
    }

    cout << "Enter vector:";
    for (int i = 0; i < 4; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            k += a[i][j] * b[j];
        }
        c[i] = k;
        k = 0.f;
    }
    cout << "Result: ";
    for (int i = 0; i < 4; ++i) {
        cout << c[i] << " ";
    }
}
