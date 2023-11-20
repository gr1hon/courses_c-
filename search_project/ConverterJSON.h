//
// Created by grigo on 14.11.2023.
//

#ifndef SEARCH_ENGINE_CONVERTERJSON_H
#define SEARCH_ENGINE_CONVERTERJSON_H


#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class ConverterJSON {
public:
    ConverterJSON() = default;
/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
* в config.json
*/
    std::vector<std::string> GetTextDocuments(){
        std::ifstream file("..\\config.json");
        json configJSON = json::parse(file);
        std::vector<std::string> files = configJSON["files"];
        file.close();
        std::vector<std::string> ans;
        for(auto& s : files){
            std::ifstream f(s);
            if (f.is_open()){
                std::string str;
                std::string input;
                while(!f.eof()){
                    std::getline(f, str);
                    input.append(str);
                    input.append(" ");
                }
                f.close();
                ans.push_back(input);
//                std::cout << input << std::endl;
            } else {
                std::cout << "File " << s << " cannot be open!" << std::endl;
            }
        }
        return ans;
    }
/**
* Метод считывает поле max_responses для определения предельного
* количества ответов на один запрос
* @return
*/
    int GetResponsesLimit(){
        std::ifstream file("..\\config.json");
        json configJSON = json::parse(file);
        int limit = configJSON["config"]["max_responses"];
        file.close();
        return limit;
    }
/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
    std::vector<std::string> GetRequests(){
        std::ifstream file("..\\requests.json");
        json requestsJSON = json::parse(file);
        std::vector<std::string> ans = requestsJSON["requests"];
        file.close();
        return ans;
    }
/**
* Положить в файл answers.json результаты поисковых запросов
*/
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers){
        std::ofstream file("..\\answers.json");
        json answersJSON;
        json requests_answers;
        for (int i = 0; i < answers.size(); ++i) {
            std::string str = "request" + std::to_string(i + 1);
            json request_answer;
            if (!answers[i].empty()){
                request_answer["result"] = "true";
                json relevance;
                for (auto & j : answers[i]) {
                    json ans;
                    ans["doc_id"] = j.first;
                    ans["rank"] = round(j.second * 1000) / 1000;
                    relevance.push_back(ans);
                }
                request_answer["relevance"] = relevance;
            } else {
                request_answer["result"] = "false";
            }
            requests_answers[str] = request_answer;
        }
        answersJSON["answers"] = requests_answers;
        file << answersJSON;
        file.close();
    }
};


#endif //SEARCH_ENGINE_CONVERTERJSON_H
