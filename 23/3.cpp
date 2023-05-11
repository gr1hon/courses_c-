#include <iostream>
#include <vector>

#define FOR(x) \
int people; \
int count = 0; \
for (int i = 1; i <= x; i++){ \
    cout << "Enter the number of passengers in the " << i << " carriage" << endl;\
    cin >> people;\
    count += people;              \
    if (numbers(people))         \
        less.push_back(i);\
    else       \
        more.push_back(i);\
}

#define ANS(x, str) \
cout << "Carriage with " #str " than 20 people:" << endl; \
for (int i = 0; i < x; i++) \
    cout << str[i] << " "; \
cout << endl;

bool numbers(int x){
    return x <= 20;
}
using namespace std;

int main() {
    vector<int> more;
    vector<int> less;
    FOR(10)
    ANS(less.size(), less)
    ANS(more.size(), more)
    cout << count << endl;
}
