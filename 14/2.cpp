#include <iostream>

using namespace std;

void printTable(char board[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
        cout << "\n";
    }
}

bool correctTurn(bool places[3][3], int x, int y){
    if(x > 0 && x < 4 && y > 0 && y < 4 && !places[x-1][y-1]){
        return true;
    } else return false;
}

int checkWin(char board[3][3]){
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        if (board[0][0] == 'X'){
            return 1;
        } else if (board[0][0] == 'O'){
            return 2;
        }
    }
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
        if (board[1][0] == 'X'){
            return 1;
        } else if (board[1][0] == 'O'){
            return 2;
        }
    }
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2]){
        if (board[2][0] == 'X'){
            return 1;
        } else if (board[2][0] == 'O'){
            return 2;
        }
    }
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        if (board[0][0] == 'X'){
            return 1;
        } else if (board[0][0] == 'O'){
            return 2;
        }
    }
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        if (board[0][1] == 'X'){
            return 1;
        } else if (board[0][1] == 'O'){
            return 2;
        }
    }
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2]){
        if (board[0][2] == 'X'){
            return 1;
        } else if (board[0][2] == 'O'){
            return 2;
        }
    }
    return 0;
}

int main() {
    char board[3][3] {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
    bool places[3][3] {{false, false, false}, {false, false, false}, {false, false, false}};
    char player_name = 'X';
    for (int i = 0; i < 9; ++i) {
        printTable(board);
        int x = 0, y = 0;
        cout << "Player " << i % 2 + 1 << ", Your turn! Enter cell coordinates from 1 to 3\n";
        do{
            cin >> x >> y;
            if(!correctTurn(places, x, y)){
                cout << "Invalid turn. Please try again!\n";
            }
        } while(!correctTurn(places, x, y));
        board[x-1][y-1] = player_name;
        if (player_name == 'X')
            player_name = 'O';
        else
            player_name = 'X';
        places[x-1][y-1] = true;
        if(checkWin(board) == 1 || checkWin(board) == 2){
            printTable(board);
            cout << "Player " << i % 2 + 1 << " win!\n";
            return 0;
        } else if(i == 8){
            printTable(board);
            cout << "Draw!\n";
            return 0;
        }
    }
}
