#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    file.open("table.txt");
    int maxMoney = 0;
    string maxMoneyOwner;
    int sum = 0;
    if (file.is_open()){
        while(!file.eof()){
            string name;
            string surname;
            int x;
            string date;
            file >> name >> surname >> x >> date;
            if (x > maxMoney){
                maxMoney = x;
                maxMoneyOwner = name;
                maxMoneyOwner += " ";
                maxMoneyOwner += surname;
            }
            sum += x;
        }
        cout << "Total number of issues " << sum << endl;
        cout << "The largest payout belongs to " << maxMoneyOwner << endl;
    } else{
        cout << "Error open file!";
    }
    file.close();
}
