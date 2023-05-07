#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


int main() {
    srand(time(nullptr));
    ofstream file;
    int height;
    int width;

    cout << "Enter height and width:" << endl;
    cin >> height >> width;
    if (height <= 0){
        cerr << "Height must be >0!" << endl;
        return 0;
    }
    if (width <= 0){
        cerr << "Width must be >0!" << endl;
        return 0;
    }
    file.open("..\\pic.txt");
    if (file.is_open()){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int ch = rand() % 2;
                file << ch;
            }
            file << endl;
        }
    } else
        cout << "File open error";
    file.close();
}
