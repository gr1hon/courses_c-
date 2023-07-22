#include <iostream>
#include <fstream>
#include <map>
#include "nlohmann/json.hpp"

using namespace std;

//С помощью initialization сначала вручную заносим данные о фильме 
//в файл films.json, потом уже в нём выполняем поиск
void initialization(nlohmann::json &Films){
    nlohmann::json NewFilm;
    string input;
    string title;

    cout << "title:" << endl;
    cin >> title;
    NewFilm["Title"] = title;

    cout << "country: " << endl;
    getline(cin, input);
    NewFilm["Country"] = input;

    cout << "date: " << endl;
    getline(cin, input);
    NewFilm["Date"] = input;

    cout << "company: " << endl;
    getline(cin, input);
    NewFilm["Company"] = input;

    cout << "scriptWriter: " << endl;
    getline(cin, input);
    NewFilm["Script writer"] = input;

    cout << "director: " << endl;
    getline(cin, input);
    NewFilm["Director"] = input;

    cout << "producer: " << endl;
    getline(cin, input);
    NewFilm["Producer"] = input;

    nlohmann::json Actors;
    string actor;
    string role;
    while(actor != "end"){
        pair<string, string> actors;
        cout << "the actor(or 'end'):" << endl;
        getline(cin, actor);
        if (actor != "end"){
            actors.first = actor;
            cout << "his(her) role:" << endl;
            getline(cin, role);
            actors.second = role;
            Actors[actor] = role;
        }
    }
    NewFilm["Actors"] = Actors;
    Films[title] = NewFilm;
}

int main(){
//    ofstream films("films.json");
//    nlohmann::json Films;
//    for (int i = 0; i < 5; ++i) {
//        initialization(Films);
//    }
//    films << Films;
    ifstream films("films.json");
    nlohmann::json Films;
    films >> Films;
    cout << "Enter the name(surname) of the actor you want to find:" << endl;
    string name;
    cin >> name;
    for (const auto& film : Films) {
        nlohmann::json roles = film["Actors"];
        for(auto it = roles.begin(); it != roles.end(); ++it){
            if (it.key().find(name) != string::npos){
                cout << film["Title"] << " : " << it.value() << endl;
            }
        }
    }
}
