#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

mutex places_access;
vector<string> places;
vector<int> times;

void swim(int speed, string name){
    int time = 0;
    int distance = 0;
    while(distance < 100){
        if (distance + speed < 100){
            distance += speed;
        } else
            distance = 100;
        time++;
        cout << name << " is swimming on " << distance << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    places_access.lock();
    times.push_back(time);
    places.push_back(name);
    places_access.unlock();
}

int main() {
    int number = 6;
    vector<string> names(number);
    vector<int> speeds(number);

    for (int i = 0; i < number; ++i) {
        cout << "Enter the name of the " << i+1 << " swimmer:" << endl;
        cin >> names[i];
        cout << "Enter the " << names[i] << "'s speed:" << endl;
        cin >> speeds[i];
    }
    
    //В этом месте я пытался запихнуть объявление потоков в for, но тогда они выполняются по очереди,
    //А так как-то некрасиво, можно ли лучше?
    //И ещё, почему нельзя создать vector<thread> threads, и в нем хранить потоки?
    
    thread thread1(swim, speeds[0], names[0]);
    thread thread2(swim, speeds[1], names[1]);
    thread thread3(swim, speeds[2], names[2]);
    thread thread4(swim, speeds[3], names[3]);
    thread thread5(swim, speeds[4], names[4]);
    thread thread6(swim, speeds[5], names[5]);
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << " place: " << places[i] << " with time " << times[i] << " seconds" << endl;
    }
}
