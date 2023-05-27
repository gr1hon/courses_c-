#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main() {
    string address = "http://httpbin.org/html";
    cpr::Response r = cpr::Get(cpr::Url(address));
    int start = (int) r.text.find("<h1>") + 4;
    int end = (int) r.text.find("</h1>");
    cout << r.text.substr(start, end - start) << endl;
}
