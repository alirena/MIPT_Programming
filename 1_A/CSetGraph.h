#ifndef CSETGRAPH_H
#define CSETGRAPH_H

#include "IGraph.h"
#include <set>

class CSetGraph : public IGraph{
public:
    CSetGraph( const IGraph * graph );
    CSetGraph( unsigned int verticesNumber );
    
    virtual void AddEdge ( int from, int to ) override;
    
    virtual int VerticesCount() const override;
    
    virtual void GetNextVertices(int vertex, vector<int> & vertices) const override;
    virtual void GetPrevVertices(int vertex, vector<int> & vertices) const override;
    
private:
    unsigned int verticesNumber_;
    vector<std::set<int>> in_;
    vector<std::set<int>> out_;
};

#endif CSETGRAPH_H
