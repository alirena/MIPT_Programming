#ifndef CMATRIXGRAPH_H
#define CMATRIXGRAPH_H

#include "IGraph.h"

class CMatrixGraph : public IGraph{
public:
    
    CMatrixGraph(unsigned int verticesNumber);
    
    CMatrixGraph(const IGraph * graph);
    
    
    virtual void    AddEdge(int from, int to) override;
    
    
    virtual int     VerticesCount() const override;
    
    
    virtual void    GetNextVertices(int vertex, vector<int> & vertices) const override;
    
    virtual void    GetPrevVertices(int vertex, vector<int> & vertices) const override;
    
private:
    
    unsigned int            verticesNumber_;
    
    vector<vector<bool>>    edges_;
    
};

#endif //CMATRIXGRAPH_H
