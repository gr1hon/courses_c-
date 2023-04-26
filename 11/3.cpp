#include <iostream>
#include <string>

std::string getAddressPart(std::string address, int k){
    std::string ans;
    int count = 0;
    for(int i = 0; i < address.length(); i++){
        if(address[i] == '.'){
            count++;
        } else if(count == k-1){
            ans += address[i];
        }
    }
    return ans;
}

bool isCorrectPart (std::string part){
    if(part == ""){
        return false;
    }
    for(int i = 0; i < part.length(); i++){
        if(part[i]<'0' || part[i] > '9'){
            return false;
        }
    }
    if(part.length() > 1 && part[0] == '0'){
        return false;
    }
    int x = std::stoi(part);
    if(x >= 0 && x < 256){
        return true;
    } else return false;
}
bool isCorrectIP(std::string address){
    int count = 0;
    for(int i = 0; i < address.length(); i++){
        if(address[i] == '.'){
            count++;
        }
    }
    if (count != 3){
        return false;
    }
    for (int i = 1; i < 5; ++i) {
        if(!isCorrectPart(getAddressPart(address, i))){
            return false;
        }
    }
    return true;
}
int main(){
    while(true){
        std::string ip;
        std::cout << "Input IP: ";
        std::cin >> ip;
        if(isCorrectIP(ip)){
            std::cout << "Valid\n";
        } else{
            std::cout << "Invalid\n";
        }
    }
}
