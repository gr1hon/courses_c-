#include <iostream>

#define SPRING 1
//#define SUMMER 1
//#define AUTUMN 1
//#define WINTER 1

using namespace std;

#if SPRING
    int main(){
        cout << "Spring" << endl;
    }
#endif

#if SUMMER
int main(){
    cout << "Summer" << endl;
}
#endif

#if AUTUMN
int main(){
    cout << "Autumn" << endl;
}
#endif

#if WINTER
int main(){
    cout << "Winter" << endl;
}
#endif
