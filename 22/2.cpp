#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> numbers;
    while(true){
        string command;
        cout << "Command:(surname or \"Next\")" << endl;
        cin >> command;
        if (command == "Next"){
            if(!numbers.empty()){
                cout << numbers.begin()->first << endl;
                if(numbers.begin()->second > 1){
                    numbers.begin()->second--;
                } else{
                    map<string, int>::iterator it  = numbers.begin();
                    numbers.erase(it);
                }
            } else{
                cerr << "The queue is empty!" << endl;
            }
        } else{
            pair<string, int> person(command, 1);
            if (numbers.count(person.first) > 0){
                numbers.find(person.first)->second++;
            } else
                numbers.insert(person);
        }
    }
}
