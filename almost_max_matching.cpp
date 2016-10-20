#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    size_t first;
    size_t second;
};

// Граф -- очередь из ребер, поданных на вход
using Graph = std::queue<Edge>;

class Matching {
  public:
    void Read();
    void Solve();
    void PrintEdges();

  private:
    Graph graph_;
    std::vector<bool> included_; // включены ли уже вершины в паросочетание?
    std::vector<Edge> edges_in_matching_; // ребра, входящие в паросочетание
};

void Matching::Read() {
    size_t number_of_vertices, number_of_edges;
    std::cin >> number_of_vertices >> number_of_edges;
    included_.resize(number_of_vertices, false);
    for (size_t i = 0; i != number_of_edges; ++i) {
        Edge edge;
        // Пусть будет нумерация с 0, а не с 1
        std::cin >> edge.first >> edge.second;
        graph_.push(edge);
    }
}

void Matching::Solve() {
    while (!graph_.empty()) {
        Edge edge;
        edge = graph_.front();
        if (!included_[edge.first] && !included_[edge.second]) {
            edges_in_matching_.push_back(edge);
            included_[edge.first] = true;
            included_[edge.second] = true;
        }
        graph_.pop();
    }
}

void Matching::PrintEdges() {
    for (auto edge : edges_in_matching_) {
        std::cout << std::endl << edge.first << ' ' << edge.second;
    }
}

int main() {
    Matching matching;
    matching.Read();
    matching.Solve();
    matching.PrintEdges();
}
