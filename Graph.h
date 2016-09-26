#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph{
private:
    struct vertex{
        int data;
        bool visited;
        struct vertex* next;
    };

    struct adjList
    {
        struct vertex *head;
    };

    int V;
    std::vector<adjList> G;
public:
    Graph(int vertices);
    vertex* addVertex(int data);
    void addEdge(int index, int data);
    void dfs(int vertex);
    void printGraph();
};

#endif