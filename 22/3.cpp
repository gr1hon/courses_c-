#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram(string str1, string str2){
    if (str1.length() != str2.length())
        return false;

    map<int, int> f1;
    map<int, int> f2;

    for (char x: str1) {
        f1[x]++;
    }

    for (char y: str2) {
        f2[y]++;
    }

    return f1 == f2;
}

int main(){
    string str1; string str2;
    cout << "Enter first word" << endl;
    getline(cin, str1);
    cout << "Enter second word" << endl;
    getline(cin, str2);

    if (isAnagram(str1, str2))
        cout << "It is anagram";
    else
        cout << "Not an anagram";
}
