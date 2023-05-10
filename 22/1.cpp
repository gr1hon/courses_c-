#include <iostream>
#include <string>
#include <map>

using namespace std;

bool is_correct(string str){
    if (str.length() == 8 && str[2] == '-' && str[5] == '-'
        && str[0] <= '9' && str[0] >= '0'
        && str[1] <= '9' && str[1] >= '0'
        && str[3] <= '9' && str[3] >= '0'
        && str[4] <= '9' && str[4] >= '0'
        && str[6] <= '9' && str[6] >= '0'
        && str[7] <= '9' && str[7] >= '0'){
        return true;
    } else
        return false;
}
int main() {
    map<string, string> numbers;
    while(true){
        string query;
        cout << "Enter a query:" << endl;
        getline(cin, query);
        if (query[0]<= '9' && query[0] >= '0'){
            if (is_correct(query.substr(0,8)) && query.length()>=10){
                if (query[8] == ' ' && query[9] <= 'Z' && query[9] >= 'A'){
                    pair<string, string> record (query.substr(0,8), query.substr(9, query.length()-9));
                    numbers.insert(record);
                    cout << "Record added successfully!" << endl;
                } else
                    cout << "Invalid query!" << endl;
            } else if (is_correct(query)){
                map<string,string>::iterator it = numbers.find(query);
                cout << "Record found successfully: " << it->second << endl;
            } else
                cout << "Invalid query!" << endl;
        } else if (query[0] <= 'Z' && query[0] >= 'A'){
            for (map<string,string>::iterator it = numbers.begin();
                it != numbers.end(); it++) {
                if (it->second == query) {
                    cout << it->first << " ";
                }
            }
            cout << endl;
        } else
            cout << "Invalid query!" << endl;
    }
}
