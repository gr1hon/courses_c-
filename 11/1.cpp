#include <iostream>

std::string encrypt_caesar(std::string text, int k){
    std::string answer = text;
    while (k < 0){
        k+=26;
    }
    for(int i = 0; i < text.length(); i++){
        if (text[i] >= 'a' && text[i] <= 'z'){
            answer[i] = 'a' + ((text[i] - 'a' + k) % 26);
        } else if (text[i] >= 'A' && text[i] <= 'Z'){
            answer[i] = 'A' + ((text[i] - 'A' + k) % 26);
        }
    }
    return answer;
}

std::string decrypt_caesar(std::string text, int k){
    return encrypt_caesar(text, -k);
}
int main(){
    std::string text;
    int k;
    std::cout << "Введите текст: ";
    std::getline(std::cin,text);
    std::cout << "Введите смещение: ";
    std::cin >> k;
    std::cout << encrypt_caesar(text, k) << std::endl;
    std::cout << decrypt_caesar(text, k) << std::endl;
}
