// Exploring adjacency_list.hpp and its functions

#include <boost/graph/adjacency_list.hpp>
#include <iostream>
#include <string>

using namespace boost;

int main()
{
    /***********************************
     * Creating a graph - method 1
     ***********************************/

    // create an adjacency list, its a template
    boost::adjacency_list<> g;

    // adding vertices
    // add_vertex(g) --> return type = vertex_descriptor
    boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v4 = boost::add_vertex(g);
    
    // Iterate over the vertices
    typedef boost::adjacency_list<>::vertex_iterator v_it_t;
    std::pair<v_it_t, v_it_t> v_p = boost::vertices(g);

    for(auto it = v_p.first; it != v_p.second; ++it)
        std::cout << *it << ' '; // 0 1 2 3

    // typeid of vertex descriptor
    std::cout << typeid(v1).name() << '\n'; // returned 'y'?!

    // Adding Edges

    // add_edge(u, v, g) --> return type = std::pair<edge_descriptor, bool>
    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p;

    p = add_edge(v1, v2, g);
    p = add_edge(v2, v3, g);
    p = add_edge(v3, v4, g);
    p = add_edge(v4, v1, g);

    // edges(g)	--> return type = std::pair<edge_iterator, edge_iterator>
    std::pair<boost::adjacency_list<>::edge_iterator, 
            boost::adjacency_list<>::edge_iterator> p2;
    
    p2 = boost::edges(g);

    for(auto it = p2.first; it != p2.second; ++it)
        std::cout << *it << ' '; // (0,1) (1,2) (2,3) (3,0)
    std::cout << '\n';

    /***********************************
     * Creating a graph - method 2
     ***********************************/

    // adjacency_list<OutEdgeList, VertexList, Directed,
    //            VertexProperties, EdgeProperties,
    //            GraphProperties, EdgeList>
    
    // argument defaults 
    // OutEdgeList - vecS (vector selector)
    // VertexList - vecS [others - listS, setS, slistS, hash_setS]
    // Directed - directedS [others - undirectedS, bidirectedS]
    // Vertex, Edge, GraphProperties - none
    // EdgeList - listS
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> g2;
    enum { topLeft, topRight, bottomRight, bottomLeft };

    boost::add_edge(topLeft, topRight, g2);
    boost::add_edge(topRight, bottomRight, g2);
    boost::add_edge(bottomRight, bottomLeft, g2);
    boost::add_edge(bottomLeft, topLeft, g2);
    
    auto e_it = boost::edges(g2);
    for(auto it = e_it.first; it != e_it.second; ++it)
        std::cout << *it << ' '; // (0,1) (1,2) (2,3) (3,0)
    std::cout << '\n';

}