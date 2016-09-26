#include "Graph.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Graph:: Graph(int vertices){
    this->V=vertices;
    for(int i=0; i<V; i++){
        //allocating space in G for V amount and using constructor of struct
        G.push_back(adjList());
        visited[i]=false;
    }
}
//create a node
Graph:: vertex* Graph::addVertex(int data){
    struct vertex* newNode= new vertex;
    newNode->data= data;
    newNode->next= NULL;
    newNode->visited=false;
    return newNode;
    delete(newNode);
}
//add an Edge to the list
void Graph:: addEdge(int index, int data){
    struct vertex* cursor= G[index].head;
    while(cursor){
      if(cursor->data==data)
        return;
      cursor= cursor->next;
    }
    struct vertex* newVertex= addVertex(data);
    newVertex->next = G[index].head;
    G[index].head= newVertex;
    // this is undirected graph, so we are adding an edge from data to index;
    newVertex = addVertex(index);
    newVertex->next= G[data].head;
    G[data].head= newVertex;
}
// dfs algorithm
void Graph::dfs(int vertex){
    cout<<vertex<<", ";
    G[vertex].head->visited = true;
    visited[vertex]=true;
    struct vertex* cursor = G[vertex].head;
    while(cursor!=NULL){
      vertex=cursor->data;
      if(visited[vertex]==false)
          dfs(vertex);
      cursor= cursor->next;
    }
}

void Graph::printGraph(){
    for(int i=0; i<V; i++){
        struct vertex* cursor= G[i].head;
        cout<<"vertex: "<<i<<endl;
        while(cursor!=NULL){
            cout<<"->"<<cursor->data;
            cursor=cursor->next;
        }
        cout<<endl;
    }
}

int main(){
    Graph Graph(5);
    Graph.addEdge(0,1);
    Graph.addEdge(0,4);
    Graph.addEdge(1,2);
    Graph.addEdge(1,3);
    Graph.addEdge(1,4);
    Graph.addEdge(2,3);
    Graph.addEdge(3,4);

    Graph.printGraph();
    Graph.dfs(3);
    std::cout<<std::endl;
    return 0;
}
