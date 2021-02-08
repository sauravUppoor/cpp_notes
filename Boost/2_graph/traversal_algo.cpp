// Exploring basic traversal algorithms using boost library

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/depth_first_search.hpp>

#include <iostream>

// acts as user-defined null visitor
struct my_null_visitor {
    // these are key words
    typedef boost::on_no_event event_filter;
    template<typename T, typename Graph>
    void operator() (T t, Graph&)
    {
        std::cout << t << '\n';
    }
};

// user-defined visitor to print vertice being discovered
struct my_discover_visitor {
    typedef boost::on_discover_vertex event_filter;
    template<typename T, typename Graph>
    void operator() (T t, Graph&)
    {
        std::cout << t << '\n';
    }
} vis1; // vis1 is algorithm independent

int main()
{
    // Non-named vs Named Parameters
    // 1. Non-named parameter - must pass all parameters to the algor function
    // 2. Named paramtere - only pass the logical and mandatory ones

    // Create a simple graph
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> g;

    enum{ topLeft, topRight, bottomRight, bottomLeft };

    boost::add_edge(topLeft, topRight, g);
    boost::add_edge(topRight, bottomRight, g);
    boost::add_edge(bottomRight, bottomLeft, g);
    boost::add_edge(bottomLeft, topLeft, g);

    // breadth_first_search
    // boost::bfs_visitor<boost::null_visitor> vis; // null visitor does nothing

    // making our own visitor
    
    boost::bfs_visitor<my_discover_visitor> vis;
    boost::breadth_first_search(g, topLeft, visitor(vis)); // 0 1 3 2
    // we give visitor() to tell bfs() that its visitor object and not something else
    // like colormap()

    boost::depth_first_search(g, visitor(boost::make_dfs_visitor(vis1))); // 0 1 2 3
    // making independant vis1 a dfs visitor
    
    
}