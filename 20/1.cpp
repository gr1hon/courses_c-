#include <iostream>
#include <fstream>

using namespace std;

bool isCorrect(const string& date){
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));
    if (date[2] == '.' && date[5] == '.' && date.length() == 10){
        if (month < 0 || month > 12)
            return false;
        else if (month == 3){
            if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
                if(day > 29 || day < 0)
                    return false;
                else
                    return true;
            } else{
                if(day > 28 || day < 0)
                    return false;
                else
                    return true;
            }
        } else if (month % 2 == 1 && month < 8 || month % 2 == 0 && month > 7){
            if (day > 31 || day < 0)
                return false;
            else
                return true;
        } else {
            if (day > 30 || day < 0)
                return false;
            else
                return true;
        }
    } else
        return false;
}

int main() {
    ofstream file;
    file.open("..\\table.txt", ios::app);
    if (file.is_open()){
        string name;
        string surname;
        string date;
        int money;
        cout << "Enter name:" << endl;
        cin >> name;
        cout << "Enter surname:" << endl;
        cin >> surname;
        cout << "Enter date:" << endl;
        cin >> date;
        cout << "Enter money:" << endl;
        cin >> money;
        if (isCorrect(date) && money > 0 && name.length() > 0 && surname.length() > 0){
            file << name << " " << surname << " " << date << " " << money << endl;
            cout << "Correct!" << endl;
        } else
            cerr << "Invalid input!" << endl;
    } else
        cout << "File open error!" << endl;
    file.close();
}
