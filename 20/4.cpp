#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count_bills(){
    ofstream start;
    start.open("..\\bank.bin", ios::binary);
    start.close();
    ifstream bank;
    bank.open("..\\bank.bin", ios::binary);
    if (bank.is_open()){
        int count = 0;
        string bill;
        while(getline(bank, bill)){
            count++;
        }
        bank.close();
        return count;
    } else{
        cerr << "File open error!2" << endl;
        return -1;
    }

}

vector<int> bills(int money){
    vector<int> ans = {0,0,0,0,0,0};
    ans[5] = money / 5000;
    money %= 5000;
    ans[4] = money / 2000;
    money %= 2000;
    ans[3] = money / 1000;
    money %= 1000;
    ans[2] = money / 500;
    money %= 500;
    ans[1] = money / 200;
    money %= 200;
    ans[0] = money / 100;
    return ans;
}

void bank_filling(int n){
    srand(time(nullptr));
    int bills[6] = {100, 200, 500, 1000, 2000, 5000};
    ofstream bank;
    bank.open("..\\bank.bin", ios::app | ios::binary);
    if (bank.is_open()){
        for (int i = 0; i < n; ++i) {
            int bill_type = rand() % 6;
            bank.write((char*)&bills[bill_type], sizeof (bills[bill_type]));
        }
    } else
        cerr << "Input file open error!1" << endl;
    bank.close();
}

int bank_size(){
    ifstream bank;
    bank.open("..\\bank.bin", ios::app | ios::binary);
    string str;
    int size = 0;
    if (bank.is_open()){
        int bill;
        while(bank.read((char*)&bill, sizeof (bill))){
            size++;
        }
    } else
        cerr << "File open error!" << endl;
    return size;
}
int main() {
    char type;
    cout << R"(Enter "+" to replenish the account and "-" to withdraw money from the account)" << endl;
    cin >> type;
    if (type == '+'){
        if (count_bills()!=-1){
            bank_filling(1000-count_bills());
            cout << "Money has been successfully deposited!" << endl;
        }
        else
            return 0;

    } else{
        int bank_bills[1000];
        ifstream bank;
        int size = bank_size();
        bank.open("..\\bank.bin", ios::binary);
        if (bank.is_open()){
            int bill;
            for (int i = 0; i < size; ++i) {
                bank.read((char*)&bill, sizeof (bill));
                bank_bills[i] = bill;
            }
        } else
            cerr << "File open error!" << endl;
        bank.close();
        int money;
        cout << "How much money do you want to withdraw from the account?" << endl;
        cin >> money;
        if (money % 100 != 0){
            cerr << "Sum must be divisible by 100!" << endl;
            return 0;
        } else{
            int bills_count[6]{0,0,0,0,0,0};
            for (int i = 0; i < size; ++i) {
                switch (bank_bills[i]) {
                    case 100: bills_count[0]++;
                        break;
                    case 200: bills_count[1]++;
                        break;
                    case 500: bills_count[2]++;
                        break;
                    case 1000: bills_count[3]++;
                        break;
                    case 2000: bills_count[4]++;
                        break;
                    case 5000: bills_count[5]++;
                        break;
                }
            }
            vector<int> money_by_bills = bills(money);
            for (int i = 0; i < 6; ++i) {
                if (bills_count[i] < money_by_bills[i]) {
                    cout << "It is not possible to pay this amount!" << endl;
                    return 0;
                }
            }
            //Здесь есть одна проблема. Я выдаю деньги по алгоритму bills, т.е. 1000 может быть выдана только как 1000,
            //а не как 500+500 или 200*5. В принципе я понимаю, что можно проверять количество купюр, и если его не хватает
            //(в данном случае купюр 1000), то как бы искусственно из двух 500 формировать 1000. НО так нужно сделать ДЛЯ КАЖДОЙ ПАРЫ
            //купюр, поэтому я так делать не стал. Кажется смысл задачи не совсем в этом.
            int bills[6] {100,200,500,1000,2000,5000};
            for (int i = 0; i < 6; ++i) {
                int count = money_by_bills[i];
                for (int j = 0; j < size; ++j) {
                    if (count == 0)
                        break;
                    if (bank_bills[j] == bills[i]){
                        count--;
                        bank_bills[j] = 0;
                    }
                }
            }
            remove("..\\bank.bin");
            ofstream bank;
            bank.open("..\\bank.bin", ios::app | ios::binary);
            if (bank.is_open()){
                for (int i = 0; i < size; ++i) {
                    if (bank_bills[i] != 0){
                        bank.write((char*)&bank_bills[i], sizeof (bank_bills[i]));
                    }
                }
            } else
                cerr << "File open error!" << endl;
            bank.close();
            cout << "Money withdrawn successfully" << endl;
        }
    }
}
