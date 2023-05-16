#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool isCorrectNumber(string number) {
    if (number.length() != 12 || number.substr(0, 2) != "+7")
        return false;
    else {
        for (int i = 2; i < 12; ++i) {
            if (number[i] > '9' || number[i] < '0')
                return false;
        }
    }
    return true;
}

class Record{

private:
    string number;
    string name;

public:
    string getNumber(){
        return number;
    }

    string getName() {
        return name;
    }

    void setNumber(const string& new_number) {
        if (isCorrectNumber(new_number)){
            number = new_number;
        }
    }



    void setName(string new_name) {
        Record::name = std::move(new_name);
    }




};

class Phone{


public:

    vector<Record> records;

    void addRecord(){
        auto* record = new Record();
        string str;
        cout << "Enter name:" << endl;
        cin >> str;
        record->setName(str);
        cout << "Enter number:" << endl;
        cin >> str;
        if (isCorrectNumber(str)){
            record->setNumber(str);
            records.push_back(*record);
        } else
            cerr << "Invalid number!\nRecord not added" << endl;

        cout << "Record successfully added" << endl;
    };

    void callNumber(const string& number){
        int k = 0;
        for (Record record : records) {
            if (record.getNumber() == number){
                cout << "CALL " << record.getNumber() << endl;
                k++;
                break;
            }
        }
        if (k==0)
            cerr << "Invalid number!" << endl;
    }

    void callName(const string& name){
        int k = 0;
        for (Record record : records) {
            if (record.getName() == name){
                cout << "CALL " << record.getNumber() << endl;
                k++;
                break;
            }
        }
        if (k==0)
            cerr << "Invalid name!" << endl;
    }

    void smsNumber(const string& number){
        int k =0;
        for (Record record : records) {
            if (record.getNumber() == number){
                cout << "Enter sms:" << endl;
                string sms;
                getline(cin, sms);
                getline(cin, sms);
                cout << "SMS(" << sms << ") sent successfully" << endl;
                k++;
                break;
            }
        }
        if (k==0)
            cerr << "Invalid number!" << endl;
    }

    void smsName(const string& name){
        int k =0;
        for (Record record : records) {
            if (record.getName() == name){
                string sms;
                cout << "Enter sms:" << endl;
                getline(cin, sms);
                getline(cin, sms);
                cout << "SMS(" << sms << ") sent successfully" << endl;
                k++;
                break;
            }
        }
        if (k==0)
            cerr << "Invalid name!" << endl;
    }

};

int main(){
    auto* phone = new Phone();
    string command;
    while(command != "exit"){
        cout << "Enter the command:" << endl;
        cin >> command;
        if (command == "add"){
            phone->addRecord();
        } else if (command == "call"){
            cout << "Enter name or number:" << endl;
            cin >> command;
            if (isCorrectNumber(command))
                phone->callNumber(command);
            else
                phone->callName(command);
        } else if (command == "sms"){
            cout << "Enter name or number:" << endl;
            cin >> command;
            if (isCorrectNumber(command))
                phone->smsNumber(command);
            else
                phone->smsName(command);
        } else if (command != "exit")
            cout << "Unknown command" << endl;
    }
    cout << "End" << endl;
    delete phone;
}
