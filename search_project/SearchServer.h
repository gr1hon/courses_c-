//
// Created by grigo on 14.11.2023.
//

#ifndef SEARCH_ENGINE_SEARCHSERVER_H
#define SEARCH_ENGINE_SEARCHSERVER_H

#include <set>
#include "InvertedIndex.h"
#include "ConverterJSON.h"
using namespace std;
struct RelativeIndex{
    size_t doc_id;
    float rank;
    bool operator ==(const RelativeIndex& other) const {
        return (doc_id == other.doc_id && rank == other.rank);
    }
};

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B, template<class,class,class...> class M, class... Args>
std::multimap<B,A> flip_map(const M<A,B,Args...> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(),
                   std::inserter(dst, dst.begin()),
                   flip_pair<A,B>);
    return dst;
}

class SearchServer {
public:
/**
* @param idx в конструктор класса передаётся ссылка на класс
InvertedIndex,
* чтобы SearchServer мог узнать частоту слов встречаемых в
запросе
*/
    SearchServer(InvertedIndex& idx) : _index(idx){ };
/**
* Метод обработки поисковых запросов
* @param queries_input поисковые запросы взятые из файла
requests.json
* @return возвращает отсортированный список релевантных ответов для
заданных запросов
*/
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input){
        std::vector<std::vector<RelativeIndex>> ans;
        auto converterJSON = new ConverterJSON();
        std::vector<std::string> docs = converterJSON->GetTextDocuments();
        for(const auto& str : queries_input){
            //разбиваем запрос на слова, считаем их количество
            std::map<std::string, int> words_stat;
            std::stringstream ss(str);
            std::string w;
            while(ss >> w){
                auto item = words_stat.find(w);
                if (item != words_stat.end()){
                    words_stat.at(w)++;
                } else{
                    words_stat.insert(std::pair<std::string, int>(w, 1));
                }
            }
            //сортируем по увеличению частоты встречаемости
            std::multimap<int, std::string> sorted_words = flip_map(words_stat);

            // считаем абсолютную релевантность каждого документа как сумму релевантности всех слов
            std::vector<int> frequencies;
            int max = 0;
            for (int i = 0; i < docs.size(); ++i) {
                int frequencies_sum = 0;
                for(auto & words_stat_it : words_stat){
                    std::vector<Entry> entry = _index.GetWordCount(words_stat_it.first);
                    for (auto e : entry) {
                        if (e.doc_id == i){
                            frequencies_sum += (int) e.count;
                        }
                    }
                }
                frequencies.push_back(frequencies_sum);
                if (frequencies_sum > max){
                    max = frequencies_sum;
                }
            }
            if (max == 0){
                std::vector<RelativeIndex> relative_index;
                ans.push_back(relative_index);
                continue;
            }

            //считаем относительную релевантность
            std::vector<float> relative_frequencies;
            for (auto x : frequencies) {
                relative_frequencies.push_back((float) x / (float) max);
            }
            std::vector<RelativeIndex> relative_index;
            for (int i = 0; i < docs.size(); ++i) {
                RelativeIndex r{(size_t) i ,relative_frequencies[i]};
                if (r.rank > 0){
                    relative_index.push_back(r);
                }
            }

            //сортируем выходные данные по убыванию относительной релевантности
            for (int i = 0; i < relative_index.size(); ++i) {
                for (int j = i; j < relative_index.size(); ++j) {
                    if (relative_index[j].rank > relative_index[i].rank){
                        swap(relative_index[j], relative_index[i]);
                    } else if(relative_index[j].rank == relative_index[i].rank &&
                            relative_index[j].doc_id < relative_index[i].doc_id){
                        swap(relative_index[j], relative_index[i]);
                    }
                }
            }

            //оставляем только первые несколько ответов в соответствии с полем max_responses
            int limit = converterJSON->GetResponsesLimit();
            if (relative_index.size() > limit){
                relative_index.resize(limit);
            }
            ans.push_back(relative_index);
        }
        return ans;
    }
private:
    InvertedIndex _index;
};


#endif //SEARCH_ENGINE_SEARCHSERVER_H
