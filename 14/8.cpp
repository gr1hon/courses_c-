//Для удобства я тестировал на полях, которые инициализированы вручную.
//(нужно менять переменную count - число занятых кораблями клеток)
//Также тестировал этап расстановки кораблей. Вроде бы, всё работает))
//При расстановке больших кораблей сначала указывается координаты одного конца(2 числа через пробел),
//потом координаты другого конца(еще 2 числа через пробел). Для удобства в консоль выводятся first/second coord.
//Также для удобства можно при стадии боя также показывать поля(строчки закомментированы).

#include <iostream>

using namespace std;

void initialization(bool field[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            field[i][j] = false;
        }
    }
}

bool isCorrect(bool field[10][10], int x1, int y1, int x2, int y2, int type){
    if(x1 > x2 || y1 > y2 ||
        x1 < 0 || x1 > 9 ||
        x2 < 0 || x2 > 9 ||
        y1 < 0 || y1 > 9 ||
        y2 < 0 || y2 > 9 ||
            !(x2 - x1 == 0 && y2 - y1 == type - 1 || x2 - x1 == type - 1 && y2 - y1 == 0)){
        return false;
    } else {
        for (int i = x1; i < x2+1; ++i) {
            for (int j = y1; j < y2+1; ++j) {
                if(field[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
}

void putShip(bool field[10][10], int x1, int y1, int x2, int y2){
    for (int i = x1; i < x2+1; ++i) {
        for (int j = y1; j < y2+1; ++j) {
            field[i][j] = true;
        }
    }
}

bool shoot(bool field[10][10], int x, int y){
    if(field[x][y]){
        return true;
    } else return false;
}

void printField(bool field[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(field[i][j]){
                cout << "X ";
            } else {
                cout << "* ";
            }
        }
        cout << "\n";
    }
}

void putAllShips(bool field[10][10]){

    printField(field);
    int type = 1;
    cout << "Enter the coordinates of 4 ships 1*1:\n";
    int x1; int y1; int x2; int y2;
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << " ship:\n";
        bool correct;
        do{
            cin >> x1 >> y1;
            if(isCorrect(field, x1, y1, x1, y1, type)){
                cout << "Correct!\n";
                putShip(field, x1, y1, x1, y1);
                printField(field);
                correct = true;
            } else{
                cout << "Invalid input, please, try again:\n";
                correct = false;
            }
        } while(!correct);
    }
    cout << "\n";
    for (int j = 2; j < 5; ++j) {
        type = j;
        cout << "Enter the coordinates of " << 5 - type << " ships " << "1*"<< type << ":\n";
        for (int i = 0; i < 5 - type ; ++i) {
            cout << i + 1 << " ship:\n";
            bool correct;
            do{
                cout << "first coord:\n";
                cin >> x1 >> y1;
                cout << "second coord:\n";
                cin >> x2 >> y2;
                if(isCorrect(field, x1, y1, x2, y2, type)){
                    cout << "Correct!\n";
                    putShip(field, x1, y1, x2, y2);
                    printField(field);
                    correct = true;
                } else{
                    cout << "Invalid input, please, try again:\n";
                    correct = false;
                }
            } while(!correct);
        }
    }
}

int main() {
    bool field1[10][10];
    bool field2[10][10];
    initialization(field1);
    initialization(field2);
    cout << "Player1, please put your ships on the field:\n";
    putAllShips(field1);
    cout << "Player2, please put your ships on the field:\n";
    putAllShips(field2);
//    bool field1[10][10] = {{1,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0}, };
//    bool field2[10][10] = {{1,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0},
//                           {0,0,0,0,0,0,0,0,0,0}, };

    int count1 = 20;
    int count2 = 20;
    int turn = 1;
    while(count1 > 0 && count2 > 0){
        cout << "Player" << turn << ", your turn:\n";
        int x; int y;
        cin >> x >> y;
        if(turn % 2 == 1){
            if(shoot(field2, x, y)){
                cout << "Hit!\n";
                --count2;
                field2[x][y] = false;
            } else{
                cout << "Miss!\n";
            }
            //printField(field2);
        } else{
            if(shoot(field1, x, y)){
                cout << "Hit!\n";
                --count1;
                field1[x][y] = false;
            } else{
                cout << "Miss!\n";
            }
            //printField(field1);
        }
        turn = turn % 2 + 1;
    }
    if (count1 == 0){
        cout << "Player2 won!\nPlayer2 field:\n";
        printField(field2);
    } else{
        cout << "Player1 won!\nPlayer1 field:\n";
        printField(field1);
    }
}
