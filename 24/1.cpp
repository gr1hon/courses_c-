#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

struct task{
    string name = "unknown";
    time_t start_time{};
    time_t end_time{};
    bool ended = false;
};

int main() {
    vector<task> tasks;
    string command;
    while(command!="exit"){
        cout << "Enter the command(begin, end, status or exit):" << endl;
        cin >> command;
        task curr_task;
        if (command == "begin"){
            if (!tasks.empty() && !tasks[tasks.size()-1].ended){
                tasks[tasks.size()-1].ended = true;
                tasks[tasks.size()-1].end_time = ::time(nullptr);
                cout << "Task " << tasks[tasks.size()-1].name << " finished!" << endl;
            }
            task new_task;
            cout << "Enter the name of the task:" << endl;
            cin >> new_task.name;
            new_task.start_time = ::time(nullptr);
            tasks.push_back(new_task);
            cout << "Task " << tasks[tasks.size()-1].name << " started!" << endl;

        } else if (command == "end"){
            if (!tasks.empty() && !tasks[tasks.size()-1].ended){
                tasks[tasks.size()-1].ended = true;
                tasks[tasks.size()-1].end_time = ::time(nullptr);
                cout << "Task " << tasks[tasks.size()-1].name << " finished!" << endl;
            }


        } else if (command == "status"){
            for (const task& task : tasks) {
                if (task.ended){
                    double dif = ::difftime(task.end_time, task.start_time);
                    cout << task.name << ", time spent " << dif << " seconds" <<endl;
                } else
                    cout << "Current task: " << task.name << endl;
            }
        } else
            cout << "Unknown command!" << endl;
    }
}
