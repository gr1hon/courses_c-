#include <iostream>
#include <fstream>

using namespace std;

bool answer(int n){
    string question_path = "questions.txt";
    string answer_path = "answers.txt";
    ifstream question;
    question.open(question_path);
    if (question.is_open()){
        string s;
        string player_answer;
        for (int i = 1; i <= n; ++i) {
            getline(question, s);
        }
        cout << s << endl;
        cout << "Enter your answer(only one word!):" << endl;
        cin >> player_answer;
        ifstream answer;
        answer.open(answer_path);
        if (answer.is_open()){
            string true_answer;
            for (int i = 1; i <= n; ++i) {
                getline(answer, true_answer);
            }
            if (true_answer == player_answer){
                cout << "Correct answer!" << endl;
                return true;
            } else{
                cout << "Incorrect answer! Correct answer - " << true_answer << endl;
                return false;
            }

        } else
            cerr << "answer File open error!" << endl;
        answer.close();
    } else
        cerr << "question File open error!" << endl;
    question.close();
}

int main() {
    bool questions[13]{true, true, true, true, true, true,
                       true, true, true, true, true, true, true};
    int curr = 0;
    int player_points = 0;
    int spectators_points = 0;
    while(player_points < 6 && spectators_points < 6){
        int offset = 0;
        cout << "Enter offset:" << endl;
        cin >> offset;
        curr = (curr + offset) % 13;
        while (!questions[curr]){
            curr = (curr + 1) % 13;
        }
        if (answer(curr + 1))
            player_points++;
        else
            spectators_points++;
        questions[curr] = false;
    }
    if (player_points == 6){
        cout << "Player won!" << endl;
    } else
        cout << "Spectators won!" << endl;
}
