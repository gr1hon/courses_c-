#include <iostream>
#include <cpr/cpr.h>
#include <map>

using namespace std;


int main() {
    string address = "http://httpbin.org";
    map<string, string> arguments;
    string arg, val;
    while (arg != "get" && arg != "post"){
        cout << "Enter the argument:" << endl;
        cin >> arg;
        if (arg != "get" && arg !="post"){
            cout << "Enter the value of " << arg << ":" << endl;
            cin >> val;
            arguments.insert(pair<string, string> (arg, val));
        }
    }
    if (arg == "get"){
        address.append("/get?");
        map<string, string>::iterator it;
        for (it = arguments.begin(); it != arguments.end(); it++){
            address.append(it->first).append("=");
            address.append(it->second).append("&");
        }
        cpr::Response r = cpr::Get(cpr::Url(address));
        cout << r.text << endl;
    } else{
        address.append("/post");
        cpr::Payload payload{};
        map<string, string>::iterator it;
        for (it = arguments.begin(); it != arguments.end(); it++){
            payload.Add(cpr::Pair {it->first.c_str(), it->second.c_str()});
        }
        cpr::Response r = cpr::Post(cpr::Url(address),
                                    payload);
        cout << r.text << endl;
    }
}
