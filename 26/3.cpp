#include <iostream>
#include <vector>

using namespace std;

struct coords{
    int x = 0;
    int y = 0;


};

coords add(coords& coords1, coords& coords2){
    coords1.x += coords2.x;
    coords1.y += coords2.y;
    return coords1;
}

bool isCorrectCoords(coords point){
    return(point.x > 0 && point.x <= 80 && point.y >0 && point.y <=50);
}



class Window{

private:
    coords upperLeftCorner;
    int height = 0;
    int width = 0;

public:

    void move(){
        coords vector;
        cout << "Enter the coordinates of the displacement vector:" << endl;
        cin >> vector.x >> vector.y;
        add(vector, upperLeftCorner);
        if (isCorrectCoords(vector) && (vector.x + height) <=50 && (vector.y + width) <= 80){
            upperLeftCorner = vector;
            cout << "New upper left corner coordinations: (" << upperLeftCorner.x << ", " << upperLeftCorner.y << ")" << endl;
        }
        else
            cerr << "With the specified movement, the window will go off the screen!" << endl;
    }

    void resize(){
        cout << "Enter the window size (width and height):" << endl;
        int new_height; int new_width;
        cin >> new_width >> new_height;
        if (new_width > (80 - upperLeftCorner.x) || new_width <= 0){
            cerr << "Width must be > 0 and <= " << (80 - upperLeftCorner.x) << endl;
        } else if (new_height > (50 - upperLeftCorner.y) || new_height <= 0) {
            cerr << "Height must be > 0 and <= " << (50 - upperLeftCorner.y)<< endl;
        } else{
            height = new_height;
            width = new_width;
            cout << "New window sizes: " << width << "*" << height << endl;
        }
    }

    void display() const{
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 80; ++j) {
                if (j >= upperLeftCorner.x && ((width > 1 && j < (upperLeftCorner.x + width)) || (width == 1 && j < (upperLeftCorner.x + width))) &&
                    i >= upperLeftCorner.y && ((height > 1 && i < (upperLeftCorner.y + height)) || (height == 1 && i < (upperLeftCorner.y + height))))
                    cout << 1;
                else
                    cout << 0;
            }
            cout << endl;
        }
    }
};

int main(){
    string command;
    auto* window = new Window();
    while(command != "close"){
        cout << "Enter the command:" << endl;
        cin >> command;
        if (command == "move"){
            window->move();
        } else if (command == "resize"){
            window->resize();
        } else if (command == "display"){
            window->display();
        } else if (command != "close")
            cerr << "Invalid command!" << endl;
    }
}
