#include <iostream>
#include <fstream>
#include <map>
#include "nlohmann/json.hpp"

using namespace std;

struct film{
    string title;
    string country;
    string date;
    string company;
    string scriptWriter;
    string director;
    string producer;
    map<string, string> actors;
};

int main(){
    ofstream file("output.json");
    nlohmann::json Film;
    film new_film;

    cout << "title: " << endl;
    getline(cin, new_film.title);
    Film["Title"] = new_film.title;

    cout << "country: " << endl;
    getline(cin, new_film.company);
    Film["Country"] = new_film.country;

    cout << "date: " << endl;
    getline(cin, new_film.date);
    Film["Date"] = new_film.date;

    cout << "company: " << endl;
    getline(cin, new_film.company);
    Film["Company"] = new_film.company;

    cout << "scriptWriter: " << endl;
    getline(cin, new_film.scriptWriter);
    Film["Script writer"] = new_film.scriptWriter;

    cout << "director: " << endl;
    getline(cin, new_film.director);
    Film["Director"] = new_film.director;

    cout << "producer: " << endl;
    getline(cin, new_film.producer);
    Film["Producer"] = new_film.producer;

    string input;
    while(input != "end"){
        pair<string, string> actor;
        cout << "the actor(or 'end'):" << endl;
        getline(cin, input);
        if (input != "end"){
            actor.first = input;
            cout << "his(her) role:" << endl;
            getline(cin, input);
            actor.second = input;
            new_film.actors.insert(actor);
        }
    }
    file << Film;
}
