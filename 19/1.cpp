#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    file.open("..\\words.txt");
    string word;
    cout << "input word:\n";
    cin >> word;
    int count = 0;
    while(!file.eof()){
        string s;
        file >> s;
        if (s==word)
            count++;
    }
    file.close();
    cout << count;
}
