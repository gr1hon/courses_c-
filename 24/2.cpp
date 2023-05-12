#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

struct friends{
    string name;
    int year;
    int month;
    int day;
};

int main() {
    vector<friends> my_friends;
    string name;
    time_t t = time(nullptr);
    cout << "Enter name:" << endl;
    cin >> name;
    while(name != "end"){
        friends new_friend;
        new_friend.name = name;
        tm birthday = *localtime(&t);
        cout << "Enter " << new_friend.name << "'s birthday:" << endl;
        cin >> get_time(&birthday, "%Y.%m.%d");
        new_friend.year = birthday.tm_year + 1900;
        new_friend.month = birthday.tm_mon + 1;
        new_friend.day = birthday.tm_mday;
        my_friends.push_back(new_friend);
        cout << "Enter name:" << endl;
        cin >> name;
    }
    if (my_friends.size() > 0){
        tm* local = ::localtime(&t);
        friends next_birthday;
        for (friends fr: my_friends) {
            if (fr.month == local->tm_mon + 1){
                if (fr.day == local->tm_mday){
                    cout << "Today is " << fr.name << "'s birthday!" << endl;
                    //continue; По условию не совсем ясно, нужно ли в этом случае выводить ближайший др.
                } else{
                    if (fr.day > local->tm_mday && fr.day <= next_birthday.day){
                        if (fr.day == next_birthday.day)
                            next_birthday.name += ", " + fr.name;
                        else
                            next_birthday = fr;
                    }
                }
            } else if (fr.month > local->tm_mon + 1 && fr.month <= next_birthday.month){
                if (fr.day == next_birthday.day && fr.month == next_birthday.month)
                    next_birthday.name += ", " + fr.name;
                else if (fr.day < next_birthday.day && fr.month == next_birthday.month || fr.month < next_birthday.month){
                    next_birthday = fr;
                }
            }
        }
        if (next_birthday.name != ""){
            cout << "Next birthday: " << next_birthday.name << ": " << ((next_birthday.month > 9) ? to_string(next_birthday.month) : "0" +
            to_string(next_birthday.month)) << "." << ((next_birthday.day > 9) ? to_string(next_birthday.day) : "0" + to_string(next_birthday.day)) << endl;
        } else
            cout << "None of your friends have a birthday before the end of the year!" << endl;

    } else
        cout << "It looks like you have no friends :(((" << endl;
}
