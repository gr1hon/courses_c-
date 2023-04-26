#include <iostream>
#include <string>

using namespace std;

//Получаем символ на поле по его координатам
char getCell(string str1, string str2, string str3, int x, int y){
    switch(x){
        case 1: return str1[y-1];
        case 2: return str2[y-1];
        case 3: return str3[y-1];
    }
}

//Считаем количество крестиков или ноликов на поле
int count (string str1, string str2, string str3, char ch){
    int count = 0;
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            if(getCell(str1, str2, str3, i, j) == ch){
                count++;
            }
        }
    }
    return count;
}

//Смотрим каждую из горизонталей, диагоналей и вертикалей на предмет выигрыша
char whoWon (string str1, string str2, string str3){
    int PetyaWon = 0;
    int VanyaWon = 0;
    
    //X..
    //.X.
    //..X
    if(getCell(str1, str2, str3, 1, 1) == getCell(str1, str2, str3, 2, 2) &&
       getCell(str1, str2, str3, 3, 3) == getCell(str1, str2, str3, 2, 2)){
        if(getCell(str1, str2, str3, 1, 1) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 1, 1) != '.'){
            VanyaWon++;
        }
    }
    
    //..X
    //.X.
    //X..
    if(getCell(str1, str2, str3, 1, 3) == getCell(str1, str2, str3, 2, 2) &&
       getCell(str1, str2, str3, 3, 1) == getCell(str1, str2, str3, 2, 2)){
        if(getCell(str1, str2, str3, 1, 3) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 1, 3) != '.'){
            VanyaWon++;
        }
    }
    
    //XXX
    //...
    //...
    if(getCell(str1, str2, str3, 1, 1) == getCell(str1, str2, str3, 1, 2) &&
       getCell(str1, str2, str3, 1, 2) == getCell(str1, str2, str3, 1, 3)){
        if(getCell(str1, str2, str3, 1, 1) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 1, 1) != '.'){
            VanyaWon++;
        }
    }
    
    //...
    //XXX
    //...
    if(getCell(str1, str2, str3, 2, 1) == getCell(str1, str2, str3, 2, 2) &&
       getCell(str1, str2, str3, 2, 2) == getCell(str1, str2, str3, 2, 3)){
        if(getCell(str1, str2, str3, 2, 2) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 2, 2) != '.'){
            VanyaWon++;
        }
    }
    
    //...
    //...
    //XXX
    if(getCell(str1, str2, str3, 3, 1) == getCell(str1, str2, str3, 3, 2) &&
       getCell(str1, str2, str3, 3, 2) == getCell(str1, str2, str3, 3, 3)){
        if(getCell(str1, str2, str3, 3, 1) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 3, 1) != '.'){
            VanyaWon++;
        }
    }
    
    //X..
    //X..
    //X..
    if(getCell(str1, str2, str3, 1, 1) == getCell(str1, str2, str3, 2, 1) &&
       getCell(str1, str2, str3, 2, 1) == getCell(str1, str2, str3, 3, 1)){
        if(getCell(str1, str2, str3, 1, 1) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 1, 1) != '.'){
            VanyaWon++;
        }
    }
    
    //.X.
    //.X.
    //.X.
    if(getCell(str1, str2, str3, 1, 2) == getCell(str1, str2, str3, 2, 2) &&
       getCell(str1, str2, str3, 2, 2) == getCell(str1, str2, str3, 3, 2)){
        if(getCell(str1, str2, str3, 2, 2) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 2, 2) != '.'){
            VanyaWon++;
        }
    }
    
    //..X
    //..X
    //..X
    if(getCell(str1, str2, str3, 1, 3) == getCell(str1, str2, str3, 2, 3) &&
       getCell(str1, str2, str3, 2, 3) == getCell(str1, str2, str3, 3, 3)){
        if(getCell(str1, str2, str3, 1, 3) == 'X'){
            PetyaWon++;
        } else if(getCell(str1, str2, str3, 1, 3) != '.'){
            VanyaWon++;
        }
    }
    
    //cout << "P: " << PetyaWon << ", V: " << VanyaWon << "\n";
    if(PetyaWon == 1 && VanyaWon == 1){
        return 'B';
    } else if (PetyaWon == 1 && VanyaWon == 0){
        return 'P';
    } else if (PetyaWon == 0 && VanyaWon == 1){
        return 'V';
    } else if (PetyaWon == 0 && VanyaWon == 0){
        return 'N';
    } else return 'I';
}

//Отвечает за все возможные критерии корректности игры
bool isBoardCorrect(string str1, string str2, string str3){
    //невалидные символы
    for(int i = 0; i < 3; i++){
        if(str1[i] != 'X' && str1[i] != 'O' && str1[i] != '.'){
            return false;
        }
    }
    for(int i = 0; i < 3; i++){
        if(str2[i] != 'X' && str2[i] != 'O' && str2[i] != '.'){
            return false;
        }
    }
    for(int i = 0; i < 3; i++){
        if(str3[i] != 'X' && str3[i] != 'O' && str3[i] != '.'){
            return false;
        }
    }
    //победили оба
    if(whoWon(str1, str2, str3) == 'B'){
        return false;
    }
    //победили нолики, а крестиков >=
    if (whoWon(str1, str2, str3) == 'V' && count(str1, str2, str3, 'X') > count(str1, str2, str3, 'O')){
        return false;
    }
    //победили крестики, а ноликов <
    if (whoWon(str1, str2, str3) == 'P' && count(str1, str2, str3, 'O') >= count(str1, str2, str3, 'X')){
        return false;
    }
    //победили по несколько раз
    if(whoWon(str1, str2, str3) == 'I'){
        return false;
    }
    if (count(str1, str2, str3, 'O') > count(str1, str2, str3, 'X')){
        return false;
    }
    return true;
}

void GameResult(string str1, string str2, string str3){
    if(!isBoardCorrect(str1, str2, str3)){
        cout << "Incorrect\n";
    } else if (whoWon(str1, str2, str3) == 'P'){
        cout << "Petya won.\n";
    } else if (whoWon(str1, str2, str3) == 'V'){
        cout << "Vanya won.\n";
    } else cout << "Nobody\n";


}
int main(){
    while(true){
        string str1;
        string str2;
        string str3;
        cout << "Enter tic-tac-toe board after game:\n";
        cin >> str1 >> str2 >> str3;
        GameResult(str1, str2, str3);
    }
}
