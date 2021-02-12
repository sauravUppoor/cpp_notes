#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include <boost/graph/random.hpp>

#include <iostream>
#include <random>

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

    typedef property_map<graph, vertex_index_t>::type vertexIndexMap;

    std::mt19937 prng { std::random_device{}() };
    generate_random_graph(g,9,10, prng);

    eIt edge_it, edge_end;
    tie(edge_it, edge_end) = edges(g);

    std::vector<double> centrality(num_vertices(g), 0.0);
    vertexIndexMap v_idx = get(vertex_index, g);

    iterator_property_map<std::vector<double>::iterator,
                        vertexIndexMap
                        > vertex_property_map(centrality.begin(), v_idx);
    
    brandes_betweenness_centrality(g, vertex_property_map);

    for(; edge_it != edge_end; ++edge_it)
        std::cout << *edge_it << '\n';
    std::cout << '\n';

    for(auto x: centrality)
        std::cout << x << ' ';
    std::cout << '\n';


    
}

int main()
{
    f1();
    return EXIT_SUCCESS;
}