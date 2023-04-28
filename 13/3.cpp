#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> db(5);
    int x;
    int count = -1;
    bool over = false;
    while(true){
        cout << "input number:";
        cin >> x;
        if(x != -1){
            count++;
            if(count < 5){
                db[count] = x;
            } else {
                count = 0;
                db[0] = x;
                over = true;
            }
        } else{
            cout << "output:";
            if(over){
                for (int i = count + 1; i < 5; ++i) {
                    cout << db[i] << " ";
                }
                for (int i = 0; i <= count; ++i) {
                    cout << db[i] << " ";
                }
                cout << "\n";
            } else{
                for (int i = 0; i <= count; ++i) {
                    cout << db[i] << " ";
                }
                cout << "\n";
            }
        }
    }
}
