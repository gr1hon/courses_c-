#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

struct coords{
    int x = 0;
    int y = 0;
};

struct person{
    string name = "unknown";
    coords coords;
    bool alive = true;
    int health = rand() % 51 + 100;
    int armor = rand() % 51;
    int damage = rand() % 16 + 15;
};

struct cell{
    char state = '.';
    bool is_clear = true;
};

struct board{
    cell cell[20][20];
    int enemies_count{};
};

person add_enemy(string name){
    person new_person = {name};
    return new_person;
}

void put_person(person& person, board& board, int x, int y){
    person.coords.x = x;
    person.coords.y = y;
    board.cell[x][y].is_clear = false;
}

void delete_person(board& board, person& person){
    board.cell[person.coords.x][person.coords.y].state = '.';
    board.cell[person.coords.x][person.coords.y].is_clear = true;
    person.alive = false;
}

void print_board(board& board){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << board.cell[i][j].state << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void pve_fight(board& board, person& player, person& enemy){
    if (enemy.armor < player.damage){
        int k;
        (enemy.health - (player.damage - enemy.armor) > 0 ) ? k = enemy.health - (player.damage - enemy.armor) : k = enemy.health;
        cout << enemy.name << " took " << k << " damage" << endl;
        enemy.health -= (player.damage - enemy.armor);
        enemy.armor = 0;

    } else{
        int k;
        k = enemy.armor - player.damage;
        enemy.armor -= player.damage;
        cout << enemy.name << " armor took " << k << " damage" << endl;
    }

    if (enemy.health <= 0){
        delete_person(board, enemy);
        board.enemies_count--;
        cout << "You kill " << enemy.name << "!" << endl;
    }else{
        cout << enemy.name << " has " << enemy.health << " health" << endl;
    }
}

void evp_fight(person& enemy, person& player){
    if (player.armor < enemy.damage){
        int k;
        (enemy.health - (player.damage - enemy.armor) > 0 ) ? k = enemy.health - (player.damage - enemy.armor) : k = enemy.health;
        cout << enemy.name << " took " << k << " damage" << endl;
        cout << player.health << " " << player.armor << endl;
        player.health -= (enemy.damage - player.armor);
        player.armor = 0;
    } else{
        int k;
        k = enemy.armor - player.damage;
        enemy.armor -= player.damage;
        cout << enemy.name << " armor took " << k << " damage" << endl;
    }
    if (player.health <= 0){
        player.alive = false;
        cout << "You died!" << endl;
    }
}

void savegame(board& board, person& player, vector<person>& enemies, const string& path){
    ofstream file;
    file.open(path, ios::binary);
    if (file.is_open()){
        for (int i = 0; i < enemies.size(); ++i) {
            file.write((char*)&(enemies[i].coords.x), sizeof (enemies[i].coords.x));
            file.write((char*)&(enemies[i].coords.y), sizeof (enemies[i].coords.y));
            file.write((char*)&(enemies[i].armor), sizeof (enemies[i].armor));
            file.write((char*)&(enemies[i].alive), sizeof (enemies[i].alive));
            file.write((char*)&(enemies[i].health), sizeof (enemies[i].health));
            file.write((char*)&(enemies[i].name), sizeof (enemies[i].name));
            file.write((char*)&(enemies[i].damage), sizeof (enemies[i].damage));
        }
        file.write((char*)&(player.coords.x), sizeof (player.coords.x));
        file.write((char*)&(player.coords.y), sizeof (player.coords.y));
        file.write((char*)&(player.armor), sizeof (player.armor));
        file.write((char*)&(player.alive), sizeof (player.alive));
        file.write((char*)&(player.health), sizeof (player.health));
        file.write((char*)&(player.name), sizeof (player.name));
        file.write((char*)&(player.damage), sizeof (player.damage));
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                file.write((char*)&(board.cell[i][j].state), sizeof (board.cell[i][j].state));
                file.write((char*)&(board.cell[i][j].is_clear), sizeof (board.cell[i][j].is_clear));
            }
        }
        cout << "Game saved successfully!" << endl;
    } else
        cerr << "Open file error!" << endl;
}

void loadgame(board& board, person& player, vector<person>& enemies, const string& path){
    ifstream file;
    file.open(path, ios::binary);
    if (file.is_open()){
        for (int i = 0; i < enemies.size(); ++i) {
            file.read((char*)&(enemies[i].coords.x), sizeof (enemies[i].coords.x));
            file.read((char*)&(enemies[i].coords.y), sizeof (enemies[i].coords.y));
            file.read((char*)&(enemies[i].armor), sizeof (enemies[i].armor));
            file.read((char*)&(enemies[i].alive), sizeof (enemies[i].alive));
            file.read((char*)&(enemies[i].health), sizeof (enemies[i].health));
            file.read((char*)&(enemies[i].name), sizeof (enemies[i].name));
            file.read((char*)&(enemies[i].damage), sizeof (enemies[i].damage));
        }
        file.read((char*)&(player.coords.x), sizeof (player.coords.x));
        file.read((char*)&(player.coords.y), sizeof (player.coords.y));
        file.read((char*)&(player.armor), sizeof (player.armor));
        file.read((char*)&(player.alive), sizeof (player.alive));
        file.read((char*)&(player.health), sizeof (player.health));
        file.read((char*)&(player.name), sizeof (player.name));
        file.read((char*)&(player.damage), sizeof (player.damage));
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                file.read((char*)&(board.cell[i][j].state), sizeof (board.cell[i][j].state));
                file.read((char*)&(board.cell[i][j].is_clear), sizeof (board.cell[i][j].is_clear));
            }
        }
        cout << "Game loaded successfully!" << endl;
    } else
        cerr << "Open file error!" << endl;
}

void player_turn(board& board, vector<person>& enemies, person& player){
    char player_turn;
    cout << "Your turn (w, a, s, d, S(save) or L(load)):" << endl;
    cin >> player_turn;
    string path = "..\\savegame.bin";
    switch (player_turn) {
        case 'w':
            if (player.coords.x > 0){
                if (!board.cell[player.coords.x-1][player.coords.y].is_clear){
                    int x;
                    for (int i = 0; i < enemies.size(); ++i) {
                        if(enemies[i].coords.x == player.coords.x-1 && enemies[i].coords.y == player.coords.y){
                            x = i;
                            break;
                        }
                    }
                    person& current_enemy = enemies[x];
                    pve_fight(board, player, current_enemy);
                } else{
                    board.cell[player.coords.x][player.coords.y].state = '.';
                    board.cell[player.coords.x][player.coords.y].is_clear = true;
                    player.coords.x -= 1;
                    board.cell[player.coords.x][player.coords.y].state = 'P';
                    board.cell[player.coords.x][player.coords.y].is_clear = false;
                }
            }
            break;
        case 'a':
            if (player.coords.y > 0){
                if (!board.cell[player.coords.x][player.coords.y-1].is_clear){
                    int x;
                    for (int i = 0; i < enemies.size(); ++i) {
                        if(enemies[i].coords.x == player.coords.x && enemies[i].coords.y == player.coords.y-1){
                            x = i;
                            break;
                        }
                    }
                    person& current_enemy = enemies[x];
                    pve_fight(board, player, current_enemy);
                } else{
                    board.cell[player.coords.x][player.coords.y].state = '.';
                    board.cell[player.coords.x][player.coords.y].is_clear = true;
                    player.coords.y -= 1;
                    board.cell[player.coords.x][player.coords.y].state = 'P';
                    board.cell[player.coords.x][player.coords.y].is_clear = false;
                }
            }
            break;
        case 's':
            if (player.coords.x < 19){
                if (!board.cell[player.coords.x+1][player.coords.y].is_clear){
                    int x;
                    for (int i = 0; i < enemies.size(); ++i) {
                        if(enemies[i].coords.x == player.coords.x+1 && enemies[i].coords.y == player.coords.y){
                            x = i;
                            break;
                        }
                    }
                    person& current_enemy = enemies[x];
                    pve_fight(board, player, current_enemy);
                } else{
                    board.cell[player.coords.x][player.coords.y].state = '.';
                    board.cell[player.coords.x][player.coords.y].is_clear = true;
                    player.coords.x += 1;
                    board.cell[player.coords.x][player.coords.y].state = 'P';
                    board.cell[player.coords.x][player.coords.y].is_clear = false;
                }

            }
            break;
        case 'd':
            if (player.coords.y < 19){
                if (!board.cell[player.coords.x][player.coords.y+1].is_clear){
                    int x;
                    for (int i = 0; i < enemies.size(); ++i) {
                        if(enemies[i].coords.x == player.coords.x && enemies[i].coords.y == player.coords.y+1){
                            x = i;
                            break;
                        }
                    }
                    person& current_enemy = enemies[x];
                    pve_fight(board, player, current_enemy);
                } else{
                    board.cell[player.coords.x][player.coords.y].state = '.';
                    board.cell[player.coords.x][player.coords.y].is_clear = true;
                    player.coords.y += 1;
                    board.cell[player.coords.x][player.coords.y].state = 'P';
                    board.cell[player.coords.x][player.coords.y].is_clear = false;
                }
            }
            break;
        case 'S':
            savegame(board, player, enemies, path);
            break;
        case 'L':
            loadgame(board, player, enemies, path);
            break;
        default:
            cerr << "Invalid input!" << endl;
            break;
    }
}

void enemy_turn(board& board, person& enemy, person& player){
    int k = rand() % 2;
    switch (k) {
        case 0://'w'
            if (enemy.coords.x > 0) {
                if (!board.cell[enemy.coords.x-1][enemy.coords.y].is_clear) {

                    if (enemy.coords.x - 1 == player.coords.x  && enemy.coords.y == player.coords.y ) {
                        evp_fight(enemy, player);
                    }
                } else{
                    board.cell[enemy.coords.x][enemy.coords.y].state = '.';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = true;
                    enemy.coords.x -= 1;
                    board.cell[enemy.coords.x][enemy.coords.y].state = 'E';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = false;
                }

            }
            break;

        case 1://'a'
            if (enemy.coords.y > 0){
                if (!board.cell[enemy.coords.x][enemy.coords.y-1].is_clear){
                    if (enemy.coords.x == player.coords.x && enemy.coords.y - 1== player.coords.y){
                        evp_fight(enemy, player);
                    }
                } else{
                    board.cell[enemy.coords.x][enemy.coords.y].state = '.';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = true;
                    enemy.coords.y -= 1;
                    board.cell[enemy.coords.x][enemy.coords.y].state = 'E';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = false;
                }

            }
            break;
        case 2://'s'
            if (enemy.coords.x < 19){
                if (!board.cell[enemy.coords.x+1][enemy.coords.y].is_clear){
                    if (enemy.coords.x+1 == player.coords.x && enemy.coords.y == player.coords.y){
                        evp_fight(enemy, player);
                    }
                } else{
                    board.cell[enemy.coords.x][enemy.coords.y].state = '.';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = true;
                    enemy.coords.x += 1;
                    board.cell[enemy.coords.x][enemy.coords.y].state = 'E';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = false;
                }
            }
            break;
        case 3://'d'
            if (enemy.coords.y < 19){
                if (!board.cell[enemy.coords.x][enemy.coords.y+1].is_clear){
                    if (enemy.coords.x == player.coords.x && enemy.coords.y+1 == player.coords.y){
                        evp_fight(enemy, player);
                    }
                } else{
                    board.cell[enemy.coords.x][enemy.coords.y].state = '.';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = true;
                    enemy.coords.y += 1;
                    board.cell[enemy.coords.x][enemy.coords.y].state = 'E';
                    board.cell[enemy.coords.x][enemy.coords.y].is_clear = false;
                }

            }
            break;
    }
}


int main() {
    std::srand(std::time(nullptr));
    int x;
    int y;
    vector<person> enemies;
    for (int i = 0; i < 5; ++i) {
        string name = "Enemy #" + to_string(i);
        person new_enemy = add_enemy(name);
        enemies.push_back(new_enemy);
        cout << enemies[i].name << endl;
    }
    person player;
    cout << "Customizing your character's stats.\nEnter the character's name:" << endl;
    cin >> player.name;
    cout << "Enter the character's health:" << endl;
    cin >> player.health;
    cout << "Enter the character's armor:" << endl;
    cin >> player.armor;
    cout << "Enter the character's damage:" << endl;
    cin >> player.damage;
    cout << "Character customization is complete.\nThe game starts right now!" << endl;
    board board;

    board.enemies_count = enemies.size();
    cout << board.enemies_count << endl;
    for (int i = 0; i < enemies.size(); ++i) {
        do {
            x = ::rand() % 20;
            y = ::rand() % 20;
            if (board.cell[x][y].is_clear){
                put_person(enemies[i], board, x, y);
                board.cell[x][y].state = 'E';
            }
        } while (board.cell[x][y].is_clear);
        board.cell[enemies[i].coords.x][enemies[i].coords.y].state = 'E';
    }

    do {
        x = ::rand() % 20;
        y = ::rand() % 20;
        if (board.cell[x][y].is_clear){
            put_person(player, board, x, y);
            board.cell[x][y].state = 'P';
        }
    } while (board.cell[x][y].is_clear);

    while(board.enemies_count > 0 && player.health > 0){
        print_board(board);
        player_turn(board, enemies, player);
        for (int i = 0; i < enemies.size(); ++i) {
            if (enemies[i].alive){
                enemy_turn(board, enemies[i], player);
            }
        }
    }

    if (player.alive)
        cout << "You win!" << endl;
    else
        cout << "You lose!" << endl;
}
