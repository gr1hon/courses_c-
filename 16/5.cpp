#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum switches{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int main() {
    int switches_state = 0;
    int time;
    int temperatureInside;
    int temperatureOutside;
    bool move;
    bool lights;
    int colorTemperature;
    for (int i = 0; i < 48; ++i) {
        time = i % 24;
        if (time < 10){
            cout << "time: 0" << time << ":00\nEnter the parameters - temperature outside, temperature inside, "
                                         "is there movement outside, is the light on in the house:\n";
        }else{
            cout << "time: " << time << ":00\nEnter the parameters - temperature outside, temperature inside, "
                                        "is there movement outside, is the light on in the house:\n";
        }
        string output;
        string moveOutside;
        string lightsInside;
        int past_switches_state = switches_state;
        int dif;
//        cin >> output;
//        stringstream stream(output);
//        stream >> temperatureOutside >> temperatureInside >> moveOutside >> lightsInside;
//Не знаю, как распарсить через пробелы, с cin вроде работает.
        cin >> temperatureOutside >> temperatureInside >> moveOutside >> lightsInside;
        if (moveOutside == "yes"){
            move = true;
        } else if (moveOutside == "no"){
            move = false;
        } else{
            cerr << "Invalid parameter: move outside\n";
            return 0;
        }

        if (lightsInside == "on"){
            lights = true;
            switches_state |= LIGHTS_INSIDE;
        } else if (lightsInside == "off"){
            lights = false;
            switches_state &= ~LIGHTS_INSIDE;
        } else{
            cerr << "Invalid parameter: lights inside\n";
            return 0;
        }

        if (temperatureOutside < 0){
            switches_state |= WATER_PIPE_HEATING;
        } else if (temperatureOutside > 5){
            switches_state &= ~WATER_PIPE_HEATING;
        }

        if(time > 16 || time < 5 && move){
            switches_state |= LIGHTS_OUTSIDE;
        } else switches_state &= ~LIGHTS_OUTSIDE;

        if (temperatureInside < 22){
            switches_state |= HEATERS;
        } else if (temperatureInside >=25){
            switches_state &= ~HEATERS;
        }

        if (temperatureInside >= 30){
            switches_state |= CONDITIONER;
        } else if (temperatureInside <= 25){
            switches_state &= ~CONDITIONER;
        }
        if (lights){
            if (time == 0){
                colorTemperature = 5000;
            } else if (time > 20){
                colorTemperature = 2700;
            } else{
                switch (time) {
                    case 16:
                        colorTemperature = 5000;
                        break;
                    case 17:
                        colorTemperature = 4425;
                        break;
                    case 18:
                        colorTemperature = 3850;
                        break;
                    case 19:
                        colorTemperature = 3275;
                        break;
                    case 20:
                        colorTemperature = 2700;
                        break;
                    default:
                        colorTemperature = 5000;
                        break;
                }
            }
        }

        dif = past_switches_state ^ switches_state;
        if(lights){
            cout << "Lights inside: on (" << colorTemperature <<  "K)\n";
        }else if (dif & 1){
            cout << "Lights inside: off\n";
        }

        if (dif & 2){
            if(switches_state & LIGHTS_OUTSIDE){
                cout << "Lights outside: on\n";
            }else cout << "Lights outside: off\n";
        }
        if (dif & 4){
            if(switches_state & HEATERS){
                cout << "Heaters: on\n";
            }else cout << "Heaters: off\n";
        }
        if (dif & 8){
            if(switches_state & WATER_PIPE_HEATING){
                cout << "Water pipe heating: on\n";
            }else cout << "Water pipe heating: off\n";
        }
        if (dif & 16){
            if(switches_state & CONDITIONER){
                cout << "Conditioner: on\n";
            }else cout << "Conditioner: off\n";
        }
    }
}
