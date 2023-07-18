#include <iostream>
#include <vector>
using namespace std;

class IGraph {
public:
    virtual ~IGraph() {}
    IGraph() {};
    IGraph(IGraph *_oth) {};
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
};

class ListGraph : public IGraph{
private:
    vector<vector<int>> vertices;
public:

    void AddEdge(int from, int to) override{
        vertices[from].push_back(to);
    }
    int VerticesCount() const override {
        int count = 0;
        for (const auto & vertex : vertices) {
            count += (int) vertex.size();
        }
        return count;
    }
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override{
        vertices = this->vertices[vertex];
        return;
    }
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override{
        for (int i = 0; i < this->vertices.size(); ++i) {
            for (int j = 0; j < this->vertices[i].size(); ++j) {
                if (this->vertices[i][j] == vertex){
                    vertices.push_back(vertex);
                    break;
                }
            }
        }
    }
    ListGraph(IGraph graph){

    }


};

class MatrixGraph : public IGraph{

};

int main() {

}
