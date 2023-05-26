#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main() {
    string command;
    string address = "http://httpbin.org";
    cout << "Enter the command:" << endl;
    cin >> command;
    cpr::Response r;
    while (command != "exit"){
        if (command == "get"){
            r = cpr::Get(cpr::Url(address.append("/") .append(command)));
            cout << r.text << endl;
        } else if (command == "post"){
            r = cpr::Post(cpr::Url(address.append("/") .append(command)));
            cout << r.text << endl;
        } else if (command == "put"){
            r = cpr::Put(cpr::Url(address.append("/") .append(command)));
            cout << r.text << endl;
        } else if (command == "delete"){
            r = cpr::Delete(cpr::Url(address.append("/") .append(command)));
            cout << r.text << endl;
        } else if (command == "patch"){
            r = cpr::Patch(cpr::Url(address.append("/") .append(command)));
            cout << r.text << endl;
        }
        else
            cerr << "Invalid command!" << endl;
        cout << "Enter the command:" << endl;
        cin >> command;
        address = "http://httpbin.org";
    }
    cout << "End!" << endl;
}
