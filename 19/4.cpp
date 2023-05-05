#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    string path;
    cout << "input file path:" << endl;
    cin >> path;
    file.open(path, ios::binary);
    string ext = path.substr(path.length()- 3);
    if (file.is_open()){
        if(ext == "png"){
            char buffer[1];
            file.read(buffer, 1);
            if (buffer[0] == (char) -119){
                char png[3];
                file.read(png, 3);
                if (png[0] == 'P' && png[1] == 'N' && png[2] == 'G')
                    cout << "correct file type" << endl;
            }
        } else
            cout << "incorrect file type" << endl;
    } else{
        cout << "Error open file!";
    }
    file.close();
}
