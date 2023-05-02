#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string buffer;
    cout << "input expression:\n";
    cin >> buffer;
    stringstream buffer_stream(buffer);
    double x1; double x2; char operation;
    buffer_stream >> x1 >> operation >> x2;
    double answer;
    switch (operation) {
        case '+':
            answer = x1 + x2;
            cout << "Answer: " << answer << "\n";
            break;
        case '-':
            answer = x1 - x2;
            cout << "Answer: " << answer << "\n";
            break;
        case '*':
            answer = x1 * x2;
            cout << "Answer: " << answer << "\n";
            break;
        case '/':
            answer = x1 / x2;
            cout << "Answer: " << answer << "\n";
            break;
        default: cout << "Invalid expression\n";
        break;
    }
}
