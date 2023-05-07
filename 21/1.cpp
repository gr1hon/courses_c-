#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct record{
    string name;
    string surname;
    string date;
    int money = 0;
};

void list(string& path){
    ifstream file;
    file.open(path);
    if (file.is_open()){
        vector<record> records;
        while (!file.eof()){
            record next_record;
            file >> next_record.name >> next_record.surname >> next_record.date >> next_record.money;
            if (next_record.name != ""){
                records.push_back(next_record);
            }
        }
        for (int i = 0; i < records.size(); ++i) {
            cout << records[i].name  << " "
                << records[i].surname <<  " "
                << records[i].date <<  " "
                << records[i].money << endl;
        }
    } else
        cerr << "File open error!";
}

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
    string command;
    cout << R"(Enter command: "list" or "add")" << endl;
    cin >> command;
    string path = "..\\table.txt";
    if (command == "list"){
        list(path);
    } else if (command == "add"){
        ofstream file;
        file.open(path, ios::app);
        if (file.is_open()){
            record new_record;
            cout << "Enter name:" << endl;
            cin >> new_record.name;
            cout << "Enter surname:" << endl;
            cin >> new_record.surname;
            cout << "Enter date:" << endl;
            cin >> new_record.date;
            cout << "Enter money:" << endl;
            cin >> new_record.money;
            if (isCorrect(new_record.date) && new_record.money > 0 && new_record.name.length() > 0 && new_record.surname.length() > 0){
                file << new_record.name << " " << new_record.surname << " " << new_record.date << " " << new_record.money << endl;
                cout << "Correct!" << endl;
            } else
                cerr << "Invalid input!" << endl;
            file.close();
        } else
            cerr << "File open error!";
    } else
        cout << "Unknown command!" << endl;
}
