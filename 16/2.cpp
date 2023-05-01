#include <iostream>

using namespace std;

int main() {
    string intPart;
    string fracPart;
    double ans;
    cout << "Input integer and fractional parts of the number:\n";
    cin >> intPart;
    cin >> fracPart;
    string number = intPart + "." + fracPart;
    ans = stod(number);
    cout << "Your number: " << ans;
}
