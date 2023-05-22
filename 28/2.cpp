#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

mutex station_access;

void train(int time, const string& name){
    while(time > 0){
        time--;
        this_thread::sleep_for(chrono::seconds(1));
    }
    station_access.lock();
    cout << "Train " << name << " has arrived at the station" << endl;
    string command;
    cout << "For the departure of train " << name << ", enter 'depart'" << endl;
    do {
        cin >> command;
        if (command!="depart")
            cerr << "Invalid command, try again" << endl;
    } while (command!="depart");
    cout << "train " << name << " departs from this station" << endl;
    cout << "The station is free!" << endl;
    station_access.unlock();
}

int main() {
    vector<int> times(3);
    for (int i = 0; i < 3; ++i) {
        cout << "Enter the time travel time for " << i+1 << " train" << endl;
        cin >> times[i];
    }
    thread A(train, times[0], "A");
    thread B(train, times[1], "B");
    thread C(train, times[2], "C");
    A.join();
    B.join();
    C.join();
    cout << "All three trains have visited the station!" << endl;
}
