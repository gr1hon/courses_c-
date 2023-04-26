#include <iostream>
#include <string>

//Проверяем, что количество символов до и после первого @ - корректно.
bool isPartsCorrect(std::string address){
    if(address.find('@') < 65 && address.find('@') > 0 && address.length() < 128) {
        return true;
    } else{
        return false;
    }
}

//Проверяем, что @ ровно одна.
bool isCountCorrect (std::string address){
    int count = 0;
    for(int i = 0; i < address.length(); i++){
        if(address[i] == '@'){
            count++;
            if (count > 1){
                return false;
            }
        }
    }
    if(count == 0){
        return false;
    }
    return true;
}

bool isFirstPartCorrect (std::string part){

    std::string variants = "!#$%&\'*+-/=?^_`{|}~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcedfghijklmnopqrstuvwxyz.";
    for(int i = 0; i < part.length(); i++){
        bool ans = false;
        for(int j = 0; j < variants.length(); j++){
            if(part[i] == variants[j]){
                ans = true;
                continue;
            }
        }
        if(!ans){
            return false;
        }
    }
    return true;
}

bool isSecondPartCorrect (std::string part){
    std::string variants = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcedfghijklmnopqrstuvwxyz-.";

    for(int i = 0; i < part.length(); i++){
        bool ans = false;
        for(int j = 0; j < variants.length(); j++){
            if(part[i] == variants[j]){
                ans = true;
                continue;
            }
        }
        if(!ans){
            return false;
        }
    }
    return true;
}

//Проверяем, что все символы допустимы, первый и последний - не точки, нет двух точек подряд.
bool isAllSymbolsCorrect (std::string address){
    if(address[0] == '.' || address[address.length()-1] == '.'){
        return false;
    }
    for (int i = 1; i < address.length()-1; i++){
        if(address[i] == '.' && address[i-1] =='.'){
            return false;
        }
    }
    std::string part1 = address.substr(0, address.find('@'));
    std::string part2 = address.substr(address.find('@')+1, address.length()-address.find('@'));
    if(isFirstPartCorrect(part1) && isSecondPartCorrect(part2)){
        return true;
    } else return false;
}

//Из предыдущих функций получаем ответ.
bool is_correct(std::string address){
    if(isPartsCorrect(address) && isAllSymbolsCorrect(address) && isCountCorrect(address)){
        return true;
    } else return false;
}



int main(){
    while(true){
        std::string address;
        std::cout << "email-address: ";
        std::getline(std::cin, address);
        if(is_correct(address)){
            std::cout << "Yes\n";
        } else{
            std::cout << "No\n";
        }
    }
}
