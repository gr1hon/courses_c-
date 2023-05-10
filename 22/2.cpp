#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> numbers;
    int i = 0;
    while(true){
        string command;
        cout << "Command:(surname or \"Next\")" << endl;
        cin >> command;
        if (command == "Next"){
            cout << numbers.begin()->first << endl;
            map<string, int>::iterator it  = numbers.begin();
            numbers.erase(it);
            i++;
        } else{
            pair<string, int> person(command, numbers.size());
            numbers.insert(person);
        }
    }
}
