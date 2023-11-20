//#include <iostream>
//#include <set>
#include "ConverterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"
using json = nlohmann::json;
//using namespace std;

int main() {
//    std::cout << "start" << std::endl;
    auto converterJson = new ConverterJSON;
    auto invertedIndex = new InvertedIndex;
    std::vector<std::string> requests = converterJson->GetRequests();
    std::vector<std::string> docs = converterJson->GetTextDocuments();
    invertedIndex->UpdateDocumentBase(docs);
    auto searchServer = new SearchServer(*invertedIndex);
    std::vector<std::vector<RelativeIndex>> ans_relativeIndex = searchServer->search(requests);
    std::vector<std::vector<std::pair<int, float>>> answer;
    for (const auto& it1 : ans_relativeIndex) {
        std::vector<std::pair<int, float>> vec;
        for (auto it2 : it1) {
            vec.emplace_back(it2.doc_id, it2.rank);
        }
        answer.emplace_back(vec);
    }
    converterJson->putAnswers(answer);
//    std::cout << "end" << std::endl;
}
