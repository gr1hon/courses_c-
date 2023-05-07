#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum room_type{
    living,
    children,
    kitchen,
    bathroom,
    sleeping
};

//enum building_type{
//    house,
//    garage,
//    barn,
//    bath
//};

struct room{
    int area = 0;
};

struct floor{
    int height;
    room living;
    room children;
    room kitchen;
    room bathroom;
    room sleeping;
};

struct house{
    int floors;
    int area = 0;
    bool bake = false;
    floor floor1;
    floor floor2;
    floor floor3;
};

struct bath{
    int area = 0;
    bool bake = false;
};

struct building{
    bool being = false;
    int area = 0;
};

struct site{
    int area = 0;
    house house;
    building garage;
    building barn;
    bath bath;
};

void add_site(site& new_site){
    cout << "Enter site area:" << endl;
    cin >> new_site.area;
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
    for (int i = 0; i < new_site.house.floors; ++i) {
        cout << "enter the area of the living room on the " << i << " floor "
                "(0 if there is no such room)";
        cin >> new_site.house.floor1.living.area;
    }

}
int main() {
//    int sites_count;
//    cout << "Enter the number of sites:" << endl;
//    cin >> sites_count;
//    vector<site> sites;
//    for (int i = 0; i < sites_count; ++i) {
//        site new_site;
//        add_site(new_site);
//        sites.push_back(new_site);
//    }
}
