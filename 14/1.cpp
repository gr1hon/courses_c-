#include <iostream>

using namespace std;

int main() {

    int cutlery[2][6] = {{4,3,3,3,3,3}, {4,3,3,3,3,3}};
    int plates[2][6] = {{3,2,2,2,2,2}, {3,2,2,2,2,2}};
    int chairs[2][6] = {{1,1,1,1,1,1}, {1,1,1,1,1,1}};
    cout << "Столовые приборы в начале:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << cutlery[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Тарелки в начале:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << plates[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Стулья в начале:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << chairs[i][j] << " ";
        }
        cout << "\n";
    }
    chairs[0][4] += 1;
    cutlery[1][2] -= 1;
    cutlery[0][0] -= 1;
    cutlery[1][2] += 1;
    plates[0][0] -= 1;
    cout << "Столовые приборы в конце:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << cutlery[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Тарелки в конце:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << plates[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Стулья в конце:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << chairs[i][j] << " ";
        }
        cout << "\n";
    }
}
