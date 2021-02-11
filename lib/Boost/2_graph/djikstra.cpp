#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

#include <iostream>

using namespace boost;

void f1()
{
    typedef adjacency_list<vecS,
                        vecS,
                        undirectedS,
                        no_property,
                        property<edge_weight_t, int>
                        > graph;

    graph g;

    typedef graph::vertex_descriptor vDes;
    typedef graph::edge_descriptor eDes;
    typedef graph::vertex_iterator vIt;
    typedef graph::edge_iterator eIt;

    vDes v1 = add_vertex(g);
    vDes v2 = add_vertex(g);
    vDes v3 = add_vertex(g);

    eDes e1 = add_edge(0,1,g).first;
    eDes e2 = add_edge(1,2,g).first;
    eDes e3 = add_edge(2,0,g).first;

    typedef property_map<graph, edge_weight_t>::type eMap;
    eMap eWt = get(edge_weight, g);
    eWt[e1] = 1;
    eWt[e2] = 1;
    eWt[e3] = 0;

    // we use iterator maps to map any datatype to ints 
    typedef property_map<graph, vertex_index_t>::type idxMap;

    // we need to pass iterator property maps to the algorithm template
    // predecessor iterator map

    std::vector<vDes> predecessors(num_vertices(g));

    iterator_property_map<std::vector<vDes>::iterator,
                            idxMap,
                            vDes,
                            vDes&>
                            predMap(predecessors.begin(), get(vertex_index, g));
    
    // weight iterator map

    std::vector<int> wt(num_vertices(g));

    iterator_property_map<std::vector<int>::iterator,
                            idxMap,
                            int,
                            int&>
                            wtMap(wt.begin(), get(vertex_index, g));

    dijkstra_shortest_paths(g, v1,
                            predecessor_map(predMap)
                            .distance_map(wtMap));

    // dijkstra_shortest_paths(g, v1,
    //                         distance_map(wtMap)
    //                         .predecessor_map(predecessors));

    std::cout << "Predecessor - ";
    for(auto it: predecessors) 
        std::cout << it << ' ';
    std::cout << "\n";

    std::cout << "Distance - ";
    for(auto it: wt) 
        std::cout << it << ' ';
    std::cout << "\n";

    // Predecessor - 0 0 0
    // Distance - 0 1 0
}

int main()
{
    f1();
    return EXIT_SUCCESS;
}