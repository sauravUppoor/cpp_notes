// Exploring graph traits

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

#include <iostream>

using namespace boost;

int main()
{
    /***********************************
     * Creating a weighted graph - using property list
     ***********************************/

    typedef property<edge_weight_t, int> edgeDistanceProperty;
    typedef property<vertex_name_t, std::string> vertexName;

    typedef adjacency_list<vecS, vecS, undirectedS, vertexName, 
        edgeDistanceProperty> Graph;

    
}