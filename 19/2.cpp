#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    string path;
    cout << "input file path:\n";
    cin >> path;
    file.open(path);
    if (file.is_open()){
        char buffer[10];
        while(!file.eof()){
            file.read(buffer, sizeof (buffer));
            if (file.gcount() == sizeof (buffer)){
                cout << buffer;
            } else{
                for (int i = 0; i < file.gcount(); ++i) {
                    cout << buffer[i];
                }
            }
        }
    } else{
        cout << "Error open file!";
    }
    file.close();
}
