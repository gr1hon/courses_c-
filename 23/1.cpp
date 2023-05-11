#include <iostream>

#define STR(s) #s
#define PRINT(num) std::cout << DAY##num
#define DAY1 STR(monday)
#define DAY2 STR(tuesday)
#define DAY3 STR(wednesday)
#define DAY4 STR(thursday)
#define DAY5 STR(friday)
#define DAY6 STR(saturday)
#define DAY7 STR(sunday)


using namespace std;

int main() {
    int day;
    cout << "Enter the number of the day:(1 to 7)" << endl;
    cin >> day;
    switch (day) {
        case 1:
            PRINT(1);
            break;
        case 2:
            PRINT(2);
            break;
        case 3:
            PRINT(3);
            break;
        case 4:
            PRINT(4);
            break;
        case 5:
            PRINT(5);
            break;
        case 6:
            PRINT(6);
            break;
        case 7:
            PRINT(7);
            break;
    }
}
