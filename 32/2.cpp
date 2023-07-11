#include <iostream>
#include <fstream>
#include <map>
#include "nlohmann/json.hpp"

using namespace std;

//struct film{
//    string title;
//    string country;
//    string date;
//    string company;
//    string scriptWriter;
//    string director;
//    string producer;
//    map<string, string> actors;
//};

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
    ifstream films("films.json");
    nlohmann::json Films;
    films >> Films;
    cout << "Enter the name(surname) of the actor you want to find:" << endl;
    string name;
    cin >> name;
    for (const auto& film : Films) {
        nlohmann::json roles = film["Actors"];
        cout << roles.contains(name) << endl;
        roles.c
//        cout << actors;
//        auto role = actors.find(name);
//        if(role != actors.end()){
//            std::cout << std::boolalpha;
//            cout << film["Title"] << ": " << *role << endl;
//        }
    }
}
