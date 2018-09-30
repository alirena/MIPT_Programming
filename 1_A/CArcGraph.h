#ifndef CARCGRAPH_H
#define CARCGRAPH_H

#include "IGraph.h"

using std::pair;

class CArcGraph:public IGraph{
public:
    CArcGraph(const IGraph * graph);
    CArcGraph(unsigned int verticesNumber);
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const override;
    
private:
    unsigned int verticesNumber_;
    vector<pair<int, int>> edges_;
};

#endif // CARCGRAPH_H
