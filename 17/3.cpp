#include <iostream>

using namespace std;

bool substr(const char* a, const char* b){
    int count = 0;
    int i = 0; int j = 0;
    while(*(b + j)!='\0'){
        j++;
    }
    int len = j;
    j = 0;
    while(*(a + i + len - 1)!='\0'){
        while(*(b + j)!='\0'){
            if(*(a+i+j) == *(b+j))
                count++;
            j++;
        }
        if (j == count)
            return true;
        count = 0;
        j = 0;
        i++;
    }
    return false;
}

int main() {
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";
    std::cout << substr(a,b) << " " << substr(a,c);
}
