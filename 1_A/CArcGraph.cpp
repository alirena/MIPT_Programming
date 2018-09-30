#include "CArcGraph.h"

CArcGraph::CArcGraph(const IGraph * graph):
verticesNumber_(graph->VerticesCount()){
    for (int i = 0; i < verticesNumber_; i++){
        vector<int> vertices;
        graph->GetNextVertices(i, vertices);
        for (int j:vertices) {
            AddEdge(i, j);
        }
    }
};

CArcGraph::CArcGraph(unsigned int verticesNumber):
verticesNumber_(verticesNumber){};

void CArcGraph::AddEdge(int from, int to){
    edges_.push_back(std::make_pair(from, to));
};
int CArcGraph::VerticesCount() const{
    return verticesNumber_;
};

void CArcGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    for(int i = 0; i < sizeof(edges_); i++){
        if (edges_[i].first == vertex) {
            vertices.push_back(edges_[i].second);
        }
    }
};

void CArcGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    for(int i = 0; i < sizeof(edges_); i++){
        if (edges_[i].second == vertex) {
            vertices.push_back(edges_[i].first);
        }
    }
};
