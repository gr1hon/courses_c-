#include <iostream>

using namespace std;

void print(bool a[12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j <12; ++j) {
            if(a[i][j]){
                cout << "o ";
            } else{
                cout << "x ";
            }

        }
        cout << "\n";
    }
}

void initialization(bool a[12][12]){
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j <12; ++j) {
            a[i][j] = true;
        }
    }
}

int main() {
    bool bubbles[12][12];
    initialization(bubbles);
    int count = 12*12;
    print(bubbles);
    while(count > 0){
        cout << "Enter 2 coordinates - opposite corners of area: ";
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        if (x1 < 1 || x1 > 12 ||
                x2 < 1 || x2 > 12 ||
                y1 < 1 || y1 > 12 ||
                y2 < 1 || y2 > 12){
            cout << "Invalid coordinates!\n";
            return 0;
        }
        for (int i = x1 - 1; i < x2; ++i) {
            for (int j = y1 - 1; j < y2; ++j) {
                if (bubbles[i][j]){
                    bubbles[i][j] = false;
                    cout << "Pop!\n";
                    count -= 1;
                }
            }
        }
        print(bubbles);
    }
}
