// Adding properties to nodes and edges
// https://www.boost.org/doc/libs/1_64_0/libs/graph/doc/using_property_maps.html

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

#include <iostream>

using namespace boost;

struct vertexData {
    int population;
    float temperature;
};

struct edgeData {
    double distance;
    std::string name;
};

void f1()
{
    /***********************************
     * Creating a weighted graph with default properties
     ***********************************/

    // propert<PropertyTag, data type> 
    // https://www.boost.org/doc/libs/1_64_0/libs/graph/doc/using_adjacency_list.html#sec:adjacency-list-properties

    typedef adjacency_list<vecS, 
                        vecS, 
                        undirectedS, 
                        property<vertex_name_t, std::string>, 
                        property<edge_weight_t, int>
                        > graph;
    graph g;

    typedef graph::vertex_descriptor vertexDes;
    typedef graph::edge_descriptor edgeDes;
    typedef graph::vertex_iterator vertexIt;
    typedef graph::edge_iterator edgeIt;

    typedef std::pair<edgeDes, bool> myEdge;

    vertexDes v1 = add_vertex(g);
    vertexDes v2 = add_vertex(g);
    vertexDes v3 = add_vertex(g);

    edgeDes e1 = add_edge(0, 1, g).first;
    edgeDes e2 = add_edge(1, 2, g).first;
    edgeDes e3 = add_edge(2, 0, g).first;

    // property map to store default properties
    // property_map<graph type, internal property type>
    property_map<graph, vertex_name_t>::type vertexName = get(vertex_name, g);
    
    vertexName[v1] = "Mumbai";
    vertexName[v2] = "Chennai";
    vertexName[v3] = "Delhi";

    property_map<graph, edge_weight_t>::type edgeWt = get(edge_weight, g);

    edgeWt[e1] = 1;
    edgeWt[e2] = 2;
    edgeWt[e3] = 3;

    vertexIt vIt, vEnd;
    edgeIt eIt, eEnd;

    tie(vIt, vEnd) = vertices(g);
    tie(eIt, eEnd) = edges(g);

    for(; vIt != vEnd; ++vIt)
        std::cout << vertexName[*vIt] << ' ';
    std::cout << std::endl;

    for(; eIt != eEnd; ++eIt)
        std::cout << edgeWt[*eIt] << ' ';
    std::cout << std::endl;

    for(; eIt != eEnd; ++eIt) 
    {
        std::cout << vertexName[source(*eIt, g)] << ' ';
        std::cout << vertexName[target(*eIt, g)] << '\n';
    }
    std::cout << std::endl;
}

void f2()
{
    /***********************************
     * Adding custom properties to graph
     ***********************************/

    typedef adjacency_list<vecS,
                           vecS,
                           undirectedS,
                           vertexData,
                           property<edge_weight_t, int, edgeData>
                        > graph;
    
    graph g;

    typedef graph::vertex_descriptor vDes;
    typedef graph::edge_descriptor eDes;
    typedef graph::vertex_iterator vIt;
    typedef graph::edge_iterator eIt;

    vDes v = add_vertex(g);
    g[v].population = 1000;
    g[v].temperature = 9.7;

    eDes e = add_edge(0, 0, g).first;
    g[e].distance = 33.333;
    g[e].name = "e1";

    property_map<graph, edge_weight_t>::type edgeWt = get(edge_weight, g);
    edgeWt[e] = 2;

    vIt vI, vE;
    eIt eI, eE;

    tie(vI,vE) = vertices(g);
    tie(eI,eE) = edges(g);

    std::cout << "Vertex Details - \n";
    std::cout << "Vertex Idx - " << *vI << '\n';
    std::cout << "Population - " << g[*vI].population << '\n';
    std::cout << "Temperature - " << g[*vI].temperature << '\n';

    std::cout << std::endl;

    std::cout << "Edge Details - \n";
    std::cout << "Edge - " << *eI << '\n';
    std::cout << "Edge Distance - " << g[*eI].distance << '\n';
    std::cout << "Edge Name - " << g[*eI].name << '\n';
    std::cout << "Edge Weight - " << edgeWt[*eI] << '\n';
}

void f3()
{
    /***********************************
     * Adding multiple predefined properties to graph
     ***********************************/

    typedef adjacency_list<vecS,
                           vecS,
                           undirectedS,
                           property<vertex_name_t, std::string,
                                property<vertex_index1_t, int> >,
                           property<edge_weight_t, int, 
                                property<edge_weight2_t, int> >
                        > graph;
    
    graph g;

    typedef graph::vertex_descriptor vDes;
    typedef graph::edge_descriptor eDes;
    typedef graph::vertex_iterator vIt;
    typedef graph::edge_iterator eIt;

    vDes v = add_vertex(g);
    eDes e = add_edge(0, 0, g).first;

    property_map<graph, vertex_name_t>::type vName = get(vertex_name, g);
    property_map<graph, vertex_index1_t>::type vIdx = get(vertex_index1, g);
    property_map<graph, edge_weight_t>::type eWt1 = get(edge_weight, g);
    property_map<graph, edge_weight2_t>::type eWt2 = get(edge_weight2, g);

    vName[v] = "India";
    vIdx[v] = 2;
    
    eWt1[e] = 6;
    eWt2[e] = 4;


    // Using get to print nodes and edges data
    std::cout << "vertex details - \n";
    std::cout << "vertex name " << get(vertex_name, g)[v] << '\n';
    std::cout << "vertex index " << get(vertex_index1, g)[v] << '\n';

    std::cout << "edge details \n";
    std::cout << "edge " << e << '\n';
    std::cout << "edge weight 1 " << get(edge_weight, g)[e] << '\n';
    std::cout << "edge weight 2 " << get(edge_weight2, g)[e] << "\n";

    
}
int main()
{
    
    f1();
    f2();
    f3();
    return EXIT_SUCCESS;

}