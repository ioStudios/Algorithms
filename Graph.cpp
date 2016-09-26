#include "Graph.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Graph:: Graph(int vertices){
    this->V=vertices;
    for(int i=0; i<V; i++){
        G.push_back(adjList()); 
    }
}

Graph:: vertex* Graph::addVertex(int data){
    struct vertex* newNode= new vertex;
    newNode->data= data;
    newNode->next= NULL;
    newNode->visited=false;
    return newNode;
}
void Graph:: addEdge(int index, int data){
    struct vertex* newVertex= addVertex(data);
    newVertex = G[index].head;
    cout<<"fucked up\n";
    //G[index]->head= newVertex;
}
void Graph::printGraph(){
    for(int i=0; i<V; i++){
        struct vertex* cursor= G[i].head;
        cout<<"vertex: "<<i<<endl;
        while(cursor->next!=NULL){
            cout<<cursor->data<<"->";
            cursor=cursor->next;    
        }
        cout<<endl;
    }
}

int main(){
    Graph Graph(5);
    Graph.addEdge(0,1);
    /*Graph.addEdge(0,4);
    Graph.addEdge(1,2);
    Graph.addEdge(1,3);
    Graph.addEdge(1,4);
    Graph.addEdge(2,3);
    Graph.addEdge(3,4);

    Graph.printGraph();*/
    return 0;   
}