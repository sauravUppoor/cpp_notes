#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include <boost/graph/random.hpp>

#include <iostream>
#include <random>

using namespace boost;

struct vertexData {

};

struct EdgeData {

};

void f1()
{
    typedef adjacency_list<vecS,
                        vecS,
                        undirectedS
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

// unweighted graph, centrality on vertices
void f2()
{   
    typedef adjacency_list<vecS, vecS,
                            undirectedS,
                            no_property,
                            property<edge_weight_t, int>
                            > graph;
    
    graph g;

    typedef graph::vertex_descriptor vDes;
    typedef graph::edge_descriptor eDes;
    typedef graph::vertex_iterator vIt;
    typedef graph::edge_iterator eIt;

    eDes e1, e2, e3, e4, e5, e6, e7;

    // adding edges to the graph
    e1 = add_edge(0,1,g).first;
    e2 = add_edge(0,4,g).first;
    e3 = add_edge(0,3,g).first;
    e4 = add_edge(4,3,g).first;
    e5 = add_edge(3,1,g).first;
    e6 = add_edge(3,2,g).first;
    e7 = add_edge(2,1,g).first;

    std::vector<double> centrality(num_vertices(g), 0.0);

    // property map with vertex index
    typedef property_map<graph, vertex_index_t>::type vertexIndexMap;

    vertexIndexMap vertex_map = get(vertex_index, g);

    // iterator for property map
    iterator_property_map<std::vector<double>::iterator,
                            vertexIndexMap
                            > vertex_itr_map(centrality.begin(), vertex_map);
    
    // centrality on vertices in a unweighted graph
    brandes_betweenness_centrality(g, vertex_itr_map);
    std::cout << "unweighted - \n";
    for(auto x: centrality)
        std::cout << x << '\t';
    std::cout << '\n';
}

// weighted graph, centrality on vertices
void f3()
{
    typedef adjacency_list<vecS, vecS,
                            undirectedS,
                            no_property,
                            property<edge_weight_t, int>
                            > graph;
    
    graph g;

    typedef graph::vertex_descriptor vDes;
    typedef graph::edge_descriptor eDes;
    typedef graph::vertex_iterator vIt;
    typedef graph::edge_iterator eIt;

    eDes e1, e2, e3, e4, e5, e6, e7;

    // adding edges to the graph
    e1 = add_edge(0,1,2,g).first;
    e2 = add_edge(0,4,3,g).first;
    e3 = add_edge(0,3,3,g).first;
    e4 = add_edge(4,3,2,g).first;
    e5 = add_edge(3,1,4,g).first;
    e6 = add_edge(3,2,1,g).first;
    e7 = add_edge(2,1,2,g).first;

    std::vector<double> centrality1(num_vertices(g), 0.0);
    std::vector<double> centrality2(num_edges(g), 0.0);
    typedef property_map<graph, edge_weight_t>::type WeightMap;
    WeightMap e_wt_map = get(edge_weight, g);

    e_wt_map[e1] = 2;
    e_wt_map[e2] = 3;
    e_wt_map[e3] = 3;
    e_wt_map[e4] = 2;
    e_wt_map[e5] = 4;
    e_wt_map[e6] = 1;
    e_wt_map[e7] = 2;
    iterator_property_map<std::vector<double>::iterator,
                            WeightMap
                            > e_itr_map(centrality1.begin(), e_wt_map);

    // property map with vertex index
    typedef property_map<graph, vertex_index_t>::type vertexIndexMap;

    vertexIndexMap vertex_map = get(vertex_index, g);

    // iterator for property map
    iterator_property_map<std::vector<double>::iterator,
                            vertexIndexMap
                            > vertex_itr_map(centrality2.begin(), vertex_map);

    brandes_betweenness_centrality(g, vertex_itr_map, e_wt_map);
                            // none,
                            // none,
                            // none,
                            // none,
                            // get(vertex_index, g),
                            // get(edge_weight, g));

    std::cout << "weighted - \n";
    for(auto x: centrality1)
        std::cout << x << '\t';
    std::cout << "\n";

    for(auto x: centrality2)
        std::cout << x << '\t';
    std::cout << "\n";
}
int main()
{
    // f1();
    f2();
    f3();
    return EXIT_SUCCESS;
}