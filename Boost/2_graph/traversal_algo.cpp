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
        std::cout << t << ' ';
    }
};

// user-defined visitor to print vertice being discovered
struct my_discover_visitor {
    typedef boost::on_discover_vertex event_filter;
    template<typename T, typename Graph>
    void operator() (T t, Graph&)
    {
        std::cout << t << ' ';
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


    /***********************************
     * User defined visitor
     **********************************/
    boost::bfs_visitor<my_discover_visitor> vis;
    std::cout << "BFS - ";
    boost::breadth_first_search(g, topLeft, visitor(vis)); // 0 1 3 2
    // we give visitor() to tell bfs() that its visitor object and not something else
    // like colormap()
    std::cout << "\nDFS - ";

    boost::depth_first_search(g, visitor(boost::make_dfs_visitor(vis1))); // 0 1 2 3
    // making independant vis1 a dfs visitor
    std::cout << "\n";

    /***********************************
     * EventVisitor Models - 
     * 1. distance_recorder - record_distances()
     * 2. predecessor_recorder - record_predecessors()
     * 3. time_stamper - stamp_times()
     * 4. property _writer
     * 5. null_visitor
     * 
     * Event Tags -
     * 1. on_start_vertex()
     * 2. on_discover_vertex()
     * 3. on_finish_vertex()
     * 4. on_initialize_vertex()
     * 5. on_tree_edge()
     * 6. on_cycle_edge()
     * 7. on_examine_edge()
     * 8. on_edge_[not_]relaxed()
     * 9. on_edge_[not_]minimized()
     * 10. on_no_event
     **********************************/

    /***********************************
     * record_distance(distanceMap, Tag) - non member function of
     *      distance_recorder model
     **********************************/
    
    std::array<int, 4> distances{0}; // 4 nodes in our graph
    boost::breadth_first_search(g, topLeft,
        visitor(
            boost::make_bfs_visitor(
                boost::record_distances(distances.data(),
                    boost::on_tree_edge()))));

    std::cout << "Distances - ";
    for(auto d: distances)
        std::cout << d << ' '; // 0 1 2 1
    std::cout << '\n';

    /***********************************
     * record_predecessor(predecessorMap, Tag) - nm function of 
     *      predecessor_recorder
     **********************************/

    std::array<int, 4> pred;
    pred[topLeft] = topLeft; // fix pred of starting vertices else garbage returned
    boost::breadth_first_search(g, topLeft,
        visitor(
            boost::make_bfs_visitor(
                boost::record_predecessors(pred.data(),
                    boost::on_tree_edge()))));
    
    for(auto p : pred)
        std::cout << p << ' '; // 0 0 1 0
    std::cout << '\n'; 


    /***********************************
     * Combining multiple recorders using std::pair
     * NOTE - for more than 2 recorders store them in nested pair fashion
     * eg - std::pair(vis1,
     *          std::pair(vis2,
     *              .
     *              .
     *              std:: pair(vis n-1, vis n)));
     * 
     * stamps_time(timeMap, int time, Tag) - nm function of 
     *      time_stamper
     **********************************/
    std::vector<int> dtime(boost::num_vertices(g));
    std::vector<int> ftime(boost::num_vertices(g));
    std::vector<int> dist(boost::num_vertices(g));

    int time = 0;
    boost::breadth_first_search(g, topLeft, 
        visitor(
            boost::make_bfs_visitor(
                std::pair(
                    boost::stamp_times(
                        dtime.data(),
                        time,
                        boost::on_discover_vertex()
                    ),
                    std::pair(
                        boost::stamp_times(
                            ftime.data(),
                            time,
                            boost::on_finish_vertex()),
                        boost::record_distances(
                            dist.data(),
                            boost::on_tree_edge()
                        ))))));
    
    std::cout << "EventList\nDistances - ";
    for(auto d: dist)
        std::cout << d << ' ';
    std::cout << '\n';

    std::cout << "Discovery Time - ";
    for(auto dt: dtime)
        std::cout << dt << ' ';
    std::cout << '\n';

    std::cout << "Finish Time - ";
    for(auto ft: ftime)
        std::cout << ft << ' ';
    std::cout << '\n';

    // EventList
    // Distances - 0 1 2 1
    // Discovery Time - 1 2 5 3
    // Finish Time - 4 6 8 7

    

}