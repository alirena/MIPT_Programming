#include <iostream>



class Graph{
public:
    int BFS( int vertex );
    int FindMinCircle( Graph graph );
private:
    void GetNext ( int vertex, std::vector <std::pair <int, int> > & vetices );
    void AddEdge ( int from, int to );
    
};
