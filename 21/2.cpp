#include <iostream>
#include <vector>

using namespace std;

enum room_type{
    living,
    children,
    kitchen,
    bathroom,
    sleeping
};

struct room{
    float area = 0;
};

struct floor{
    float height{};
    room living;
    room children;
    room kitchen;
    room bathroom;
    room sleeping;
};

struct house{
    int floors{};
    float area{};
    bool bake{};
    floor floor1;
    floor floor2;
    floor floor3;
};

struct bath{
    float area = 0;
    bool bake = false;
};

struct building{
    float area = 0;
};

struct site{
    float area = 0;
    house house;
    building garage;
    building barn;
    bath bath;
};

void add_site(site& new_site){
    cout << "Enter site area:" << endl;
    cin >> new_site.area;

    //Баня
    string s;
    cout << "Is there a bath in the site?(yes or no):" << endl;
    cin >> s;
    if (s == "yes"){
        cout << "Enter the area of the bath:" << endl;
        float area;
        cin >> area;
        new_site.bath.area = area;
        cout << "Is there a bake in the bath?(yes or no):" << endl;
        cin >> s;
        if (s == "yes")
            new_site.bath.bake = true;
        else
            new_site.bath.bake = false;
    } else if (s != "no")
        cerr << "Invalid value!" << endl;

    //Гараж
    cout << "Is there a garage in the site?(yes or no):" << endl;
    cin >> s;
    if (s == "yes"){
        cout << "Enter the area of the garage:" << endl;
        float area;
        cin >> area;
        new_site.garage.area = area;
    }

    //Сарай
    cout << "Is there a barn in the site?(yes or no):" << endl;
    cin >> s;
    if (s == "yes"){
        cout << "Enter the area of the barn:" << endl;
        float area;
        cin >> area;
        new_site.barn.area = area;
    }

    cout << "Enter the number of floors in the house(1,2 or 3):" << endl;
    cin >> new_site.house.floors;
    cout << "Enter the height of the first floor:" << endl;
    cin >> new_site.house.floor1.height;
    if (new_site.house.floors > 1){
        cout << "Enter the height of the second floor:" << endl;
        cin >> new_site.house.floor2.height;
        if (new_site.house.floors > 2){
            cout << "Enter the height of the third floor:" << endl;
            cin >> new_site.house.floor3.height;
        }
    }

    //Дом, этажи и комнаты
    cout << "Enter the area of the house:" << endl;
    float area;
    cin >> area;
    new_site.house.area = area;
    int room = 0;
    while(room != -1){
        cout << "Enter the room on the first floor(0 - living, 1 - children, "
                "2 - kitchen, 3 - bathroom, 4 - sleeping, -1 - next stage)" << endl;
        cin >> room;
        switch (room) {
            case living:
                cout << "Enter the area of the living room:" << endl;
                cin >> new_site.house.floor1.living.area;
                break;
            case children:
                cout << "Enter the area of the children room:" << endl;
                cin >> new_site.house.floor1.children.area;
                break;
            case kitchen:
                cout << "Enter the area of the kitchen:" << endl;
                cin >> new_site.house.floor1.kitchen.area;
                break;
            case bathroom:
                cout << "Enter the area of the bathroom room:" << endl;
                cin >> new_site.house.floor1.bathroom.area;
                break;
            case sleeping:
                cout << "Enter the area of the sleeping room:" << endl;
                cin >> new_site.house.floor1.sleeping.area;
                break;
            default:
                break;
        }
    }
    if (new_site.house.floors > 1){
        room = 0;
        while(room != -1){
            cout << "Enter the room on the second floor(0 - living, 1 - children, "
                    "2 - kitchen, 3 - bathroom, 4 - sleeping, -1 - next stage)" << endl;
            cin >> room;
            switch (room) {
                case living:
                    cout << "Enter the area of the living room:" << endl;
                    cin >> new_site.house.floor2.living.area;
                    break;
                case children:
                    cout << "Enter the area of the children room:" << endl;
                    cin >> new_site.house.floor2.children.area;
                    break;
                case kitchen:
                    cout << "Enter the area of the kitchen:" << endl;
                    cin >> new_site.house.floor2.kitchen.area;
                    break;
                case bathroom:
                    cout << "Enter the area of the bathroom room:" << endl;
                    cin >> new_site.house.floor2.bathroom.area;
                    break;
                case sleeping:
                    cout << "Enter the area of the sleeping room:" << endl;
                    cin >> new_site.house.floor2.sleeping.area;
                    break;
                default:
                    break;
            }
        }
        if (new_site.house.floors > 2){
            room = 0;
            while(room != -1){
                cout << "Enter the room on the third floor(0 - living, 1 - children,"
                        "2 - kitchen, 3 - bathroom, 4 - sleeping, -1 - next stage)" << endl;
                cin >> room;
                switch (room) {
                    case living:
                        cout << "Enter the area of the living room:" << endl;
                        cin >> new_site.house.floor3.living.area;
                        break;
                    case children:
                        cout << "Enter the area of the children room:" << endl;
                        cin >> new_site.house.floor3.children.area;
                        break;
                    case kitchen:
                        cout << "Enter the area of the kitchen:" << endl;
                        cin >> new_site.house.floor3.kitchen.area;
                        break;
                    case bathroom:
                        cout << "Enter the area of the bathroom room:" << endl;
                        cin >> new_site.house.floor3.bathroom.area;
                        break;
                    case sleeping:
                        cout << "Enter the area of the sleeping room:" << endl;
                        cin >> new_site.house.floor3.sleeping.area;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    //Печка в доме
    cout << "Is there a bake in the house?(yes or no):" << endl;
    cin >> s;
    if (s == "yes")
        new_site.house.bake = true;
    else if (s == "no"){
        new_site.house.bake = false;
    } else
        cerr << "Invalid value!";


}
int main() {
    int sites_count;
    cout << "Enter the number of sites:" << endl;
    cin >> sites_count;
    vector<site> sites;
    for (int i = 0; i < sites_count; ++i) {
        site new_site;
        add_site(new_site);
        sites.push_back(new_site);
        cout << "Site added!" << endl;
    }
    cout << "All sites added!" << endl;
    float total_area = 0;
    float buildings_area = 0;
    for (int i = 0; i < sites.size(); ++i) {
        total_area += sites[i].area;
        buildings_area += sites[i].house.area;
        buildings_area += sites[i].bath.area;
        buildings_area += sites[i].barn.area;
        buildings_area += sites[i].garage.area;
    }
    cout << "Percentage of area occupied by buildings: " << buildings_area / total_area * 100 << "%" << endl;
}
