//
// Created by grigo on 14.11.2023.
//

#ifndef SEARCH_ENGINE_INVERTEDINDEX_H
#define SEARCH_ENGINE_INVERTEDINDEX_H

#include <vector>
#include <iostream>
#include <map>
#include "ConverterJSON.h"

struct Entry {
    size_t doc_id, count;
// Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const {
        return (doc_id == other.doc_id &&
                count == other.count);
    }
};

class InvertedIndex {
public:
    InvertedIndex() = default;
/**
* Обновить или заполнить базу документов, по которой будем совершать
поиск*
@param texts_input содержимое документов
*/
    void UpdateDocumentBase(std::vector<std::string> input_docs){
        docs = input_docs;
    }
/**
* Метод определяет количество вхождений слова word в загруженной базе
документов
* @param word слово, частоту вхождений которого необходимо определить
* @return возвращает подготовленный список с частотой слов
*/
    std::vector<Entry> GetWordCount(const std::string& word){
        //ищем word в freq_dictionary
        std::vector<Entry> wordCount;
        int documentId = 0;
        auto item = freq_dictionary.find(word);
        if (item != freq_dictionary.end()){
            return item->second;
        }
        //если не нашли, значит заново индексируем данные из файлов
        for (auto& str : docs){
            std::stringstream ss(str);
            std::string w;
            Entry entry{ (size_t) documentId, 0};
            while (ss >> w) {
                std::transform(w.begin(), w.end(), w.begin(),
                               [](unsigned char c){ return std::tolower(c); });
                if (!std::isalpha(w.at(w.size() - 1))){
                    w.resize(w.size() - 1);
                }
                if (word == w){
                    entry.count++;
                }
            }
            if (entry.count != 0){
                wordCount.push_back(entry);
            }
            documentId++;
        }
        //вставляем полученные данные в словарь для ускорения поиска в дальнейшем
        freq_dictionary.insert(std::pair<std::string, std::vector<Entry>> (word, wordCount));

        return wordCount;
    }


private:
    std::vector<std::string> docs; // список содержимого документов
    std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь
};
#endif //SEARCH_ENGINE_INVERTEDINDEX_H
