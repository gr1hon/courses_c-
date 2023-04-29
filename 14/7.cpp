//Есть несколько вопросов по задаче:
//Если судить по условию, мы берем срез, и смотрим на наличие блоков на уровне, который оказался ПОД срезом(по картинкам в примере это так).
//Тогда по условию не совсем понятно, что такое срез 0, это как бы уровень под первым блоком, я решил просто заполнить все нулями. 

#include <iostream>

using namespace std;

void initialization(bool a[5][5][10]){
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 10; ++k) {
                a[i][j][k] = false;
            }
        }
    }
}
int main() {
    int height; int slice;
    bool world[5][5][10];
    initialization(world);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << "Enter height of " << i+1 << "*" << j+1 << " block:";
            cin >> height;
            for (int k = 0; k < height; ++k) {
                world[i][j][k] = true;
            }
        }
    }
    cout << "Enter slice:";
    cin >> slice;
    if (slice < 0 || slice > 9){
        cout << "Invalid slice value!\n";
        return 0;
    }
    if (slice == 0){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << "0 ";
            }
            cout << "\n";
        }
    } else{
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (world[i][j][slice-1]){
                    cout << "1 ";
                } else{
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    }
}
