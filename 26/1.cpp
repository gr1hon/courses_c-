#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Track{

public:
    int getDuration(){
        return duration;
    }

    tm *getCreationDate(){
        return creationDate;
    }
    string getName(){
        return name;
    };

    void setName(string new_name){
        Track::name = new_name;
    }
    void setDuration(int new_duration) {
        Track::duration = new_duration;
    }

    void setCreationDate(tm *new_creationDate) {
        Track::creationDate = new_creationDate;
    }
    bool equals(const Track& track){
        return (name == track.name &&
                creationDate == track.creationDate &&
                duration == track.duration);
    }

    void copyTrack(Track track){
        setName(track.getName());
        setDuration(track.getDuration());
        setCreationDate(track.creationDate);
    }

private:
    string name;
    int duration{};
    tm* creationDate{};
};



class PLayer{

public:
    vector<Track> tracks;
    
    void playTrack(string str){
        Track track = searchTrack(str);
        if(!track.equals(playingTrack) || isPaused){
            cout << "Name: " << track.getName() << endl;
            cout << "Duration: " << track.getDuration() << endl;
            cout << "Creation time: " << asctime(track.getCreationDate());
            playingTrack.copyTrack(track);
        }
    }

    void pauseTrack(){
        if (!playingTrack.getName().empty() && !isPaused){
            cout << playingTrack.getName() << " paused" << endl;
            isPaused = true;
        }
    }

    void nextTrack(){
        int k;
        do {
            k = ::rand() % tracks.size();
            if (!playingTrack.equals(tracks[k])){
                playingTrack.copyTrack(tracks[k]);
                cout << "Next track: " << playingTrack.getName() << endl;
                isPaused = true;
                playTrack(playingTrack.getName());
                isPaused = false;
                break;
            }
        } while(playingTrack.equals(tracks[k]));

    }
    
    void stopTrack(){
        if (!playingTrack.getName().empty() && !isStopped){
            cout << playingTrack.getName() << " stopped" << endl;
            isStopped = true;
        }
    }
    
private:
    Track searchTrack (string trackName){
        for (Track track : tracks) {
            if (track.getName() == trackName)
                return track;
        }
    }
    Track playingTrack;
    bool isPaused = false;
    bool isStopped = false;
};


int main() {
    srand(std::time(nullptr));
    string command;
    PLayer* player = new PLayer();

    Track* new_track = new Track();
    for (int i = 1; i <= 3; ++i) {
        new_track->setName(to_string(i));
        new_track->setDuration(10*i);
        time_t t = time(nullptr);
        tm* tm = localtime(&t);
        new_track->setCreationDate(tm);
        player->tracks.push_back(*new_track);
    }

    while (command != "exit"){
        cout << "Enter the command:" << endl;
        cin >> command;
        if (command == "play"){
            cout << "Enter the track name:" << endl;
            cin >> command;
            player->playTrack(command);
        } else if (command == "pause")
            player->pauseTrack();
        else if (command == "next")
            player->nextTrack();
        else if (command == "stop")
            player->stopTrack();
        else if (command != "exit")
            cout << "Unknown command!" << endl;
    }
    cout << "End" << endl;
    delete player;
    delete new_track;
}
