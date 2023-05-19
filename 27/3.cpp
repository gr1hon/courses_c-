#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Human{
private:
    string name;

public:
    void setName(const string &name) {
        Human::name = name;
    }
    const string &getName() const {
        return name;
    }

};

class Worker: public Human{
private:
    int workType{};
    bool isWorking = false;

public:
    int getWorkType() const {
        return workType;
    }

    void setWorkType(int work) {
        Worker::workType = work;
    }

    bool getIsWorking() const {
        return isWorking;
    }

    void setIsWorking(bool isWorking) {
        Worker::isWorking = isWorking;
    }
};

//class Manager: public Human{
//    int number{};
//
//};
//
//class Boss: public Human{
//
//};

class Team{

//    Manager manager;
    vector<Worker> workers;
    int lastWorkingWorker = 0;


public:
    int teamNumber;
    bool allWorkersInTeamIsWorking = false;
    void addWorker(Worker worker){
        workers.push_back(worker);
    }

    int tasksCount(int id){
        srand(id + teamNumber);
        return (rand() % this->workers.size()) + 1;
    }

    void printWorkType(int n){
        switch (n) {
            case 0:
                cout << "A" << endl;
                break;
            case 1:
                cout << "B" << endl;
                break;
            case 2:
                cout << "C" << endl;
                break;
        }
    }

    void addTasks(int k){
        if (!allWorkersInTeamIsWorking){
            cout << "Manager #" << teamNumber + 1 << " gave " << k << " subtasks to the workers in team#" << teamNumber + 1 << endl;
            for (int i = 0; i < k; ++i) {
                workers[lastWorkingWorker].setIsWorking(true);
                workers[lastWorkingWorker].setWorkType(rand() % 3);
                cout << workers[lastWorkingWorker].getName() << " is working on a task ";
                printWorkType(workers[lastWorkingWorker].getWorkType());
                lastWorkingWorker++;
                if (lastWorkingWorker == workers.size()){
                    allWorkersInTeamIsWorking = true;
                    break;
                }
            }
        }
    }

};

bool allWalkersIsWorking(vector<Team>& teams){
    for (int i = 0; i < teams.size(); ++i) {
        if (!teams[i].allWorkersInTeamIsWorking)
            return false;
    }
    return true;
}

int main() {
    //Здесь не совсем понял, для чего нужны менеджер и глава, но сделал для них классы на всякий случай
    cout << "Enter the number of teams:" << endl;
    int number;
    cin >> number;
    vector<Team> teams;
    for (int i = 0; i < number; ++i) {
        auto* team = new Team();
        team->teamNumber = i;
        cout << "Enter the number of workers in team#" << i+1 << ":" << endl;
        int workersNumber;
        cin >> workersNumber;
        for (int j = 0; j < workersNumber; ++j) {
            auto* worker = new Worker();
            worker->setName(to_string(j+1));
            team->addWorker(*worker);
            delete worker;
        }
        teams.push_back(*team);
        delete team;
    }
    while (!allWalkersIsWorking(teams)){
        cout << "Enter an integer identifier:" << endl;
        int id;
        cin >> id;
        for (int i = 0; i < teams.size(); ++i) {
            teams[i].addTasks(teams[i].tasksCount(id));
        }
    }
    cout << "Now all workers are working on tasks!" << endl;
}
