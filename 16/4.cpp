//В этой задаче не совсем понял условие. Если мы определяем ноту по битовой маске, то сочетания 123 и 321
// мы должны выводить одинаково - DOREMI? И ещё, получается, что нельзя использовать одну ноту дважды в одном числе(111)
//В моём понимании условия задачи число - это именно одновременное нажатие клавиш, а не последовательное.

#include <iostream>
#include <string>

using namespace std;

enum note{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    string answer;
    int melody[12];
    for (int i = 0; i < 2; ++i) {
        string output;
        cin >> output;
        for (int j = 0; j < output.length(); ++j) {
            string s{output[j]};
            melody[i] += (1 << (stoi(s)-1));
        }
    }
    for (int i = 0; i < 2; ++i) {
        if(melody[i] & DO){
            cout << "DO";
        }
        if(melody[i] & RE){
            cout << "RE";
        }
        if(melody[i] & MI){
            cout << "MI";
        }
        if(melody[i] & FA){
            cout << "FA";
        }
        if(melody[i] & SOL){
            cout << "SOL";
        }
        if(melody[i] & LA){
            cout << "LA";
        }
        if(melody[i] & SI){
            cout << "SI";
        }
        cout << " ";
    }
}
