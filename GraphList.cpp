#include <iostream>
#include <bits/stdc++.h>
#include <list>
#define INFINITO 999999
#define UNVISITED false
#define VISITED true

using namespace std;

class Edge
{
    int vert, wt;

public:
    Edge()
    {
        vert = -1;
        wt = -1;
    }
    Edge(int v, int w)
    {
        vert = v;
        wt = w;
    }
    int vertex() { return vert; }
    int weight() { return wt; }
};
class Graphl
{
private:
    list<Edge> **vertex;    // List headers
    int numVertex, numEdge; // Number of vertices, edges
    bool *mark;              // Pointer to mark array
public:
    Graphl(int numVert)
    {
        int i;
        numVertex = numVert;
        numEdge = 0;
        mark = new bool[numVert]; // Initialize mark array
        for (i = 0; i < numVertex; i++)
            mark[i] = UNVISITED;
        // Create and initialize adjacency lists
        vertex = (list<Edge> **)new list<Edge> *[numVertex];
        for (i = 0; i < numVertex; i++)
            vertex[i] = new llist<Edge>();
    }
    Graphl()
    {                  // Destructor
        delete[] mark; // Return dynamically allocated memory
        for (int i = 0; i < numVertex; i++)
            delete[] vertex[i];
        delete[] vertex;
    }

    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; }   // Number of edges
    int first(int v)
    { // Return first neighbor of "v"
        if (vertex[v]->length() == 0)
            return numVertex; // No neighbor
        vertex[v]->moveToStart();
        Edge it = vertex[v]->getValue();
        return it.vertex();
    }
    // Get v’s next neighbor after w
    int next(int v, int w)
    {
        Edge it;
        if (isEdge(v, w))
        {
            if ((vertex[v]->currPos() + 1) < vertex[v]->length())
            {
                vertex[v]->next();
                it = vertex[v]->getValue();
                return it.vertex();
            }
        }
        return n(); // No neighbor
    }
    // Set edge (i, j) to "weight"
    void setEdge(int i, int j, int weight)
    {
        Assert(weight > 0, "May not set weight to 0");
        Edge currEdge(j, weight);
        if (isEdge(i, j))
        { // Edge already exists in graph
            vertex[i]->remove();
            vertex[i]->insert(currEdge);
        }
        else
        { // Keep neighbors sorted by vertex index
            numEdge++;
            for (vertex[i]->moveToStart();
                 vertex[i]->currPos() < vertex[i]->length();
                 vertex[i]->next())
            {
                Edge temp = vertex[i]->getValue();
                if (temp.vertex() > j)
                    break;
            }
            vertex[i]->insert(currEdge);
        }
    }
    void delEdge(int i, int j)
    { // Delete edge (i, j)
        if (isEdge(i, j))
        {
            vertex[i]->remove();
            numEdge--;
        }
    }
    bool isEdge(int i, int j)
    { // Is (i,j) an edge?
        Edge it;
        for (vertex[i]->moveToStart();
             vertex[i]->currPos() < vertex[i]->length();
             vertex[i]->next())
        { // Check whole list
            Edge temp = vertex[i]->getValue();
            if (temp.vertex() == j)
                return true;
        }
        return false;
    }
    int weight(int i, int j)
    { // Return weight of (i, j)
        Edge curr;
        if (isEdge(i, j))
        {
            curr = vertex[i]->getValue();
            return curr.weight();
        }
        else
            return 0;
    }
    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }
    // Compute shortest path distances from "s".
    // Return these distances in "D".
    void Dijkstra(Graph *G, int *D, int s)
    {
        int i, v, w;
        for (int i = 0; i < G->n(); i++) // Initialize
            D[i] = INFINITO;
        D[0] = 0;
        for (i = 0; i < G->n(); i++)
        { // Process the vertices
            v = minVertex(G, D);
            if (D[v] == INFINITO)
                return; // Unreachable vertices
            G->setMark(v, VISITED);
            for (w = G->first(v); w < G->n(); w = G->next(v, w))
                if (D[w] > (D[v] + G->weight(v, w)))
                    D[w] = D[v] + G->weight(v, w);
        }
    }
};
int main(){
    int numCases;
    cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {   
        int numVertex,numEdges,S,T;
        //n (2 ≤ n ≤ 20000), m (0 ≤ m ≤ 50000), S (0 ≤ S < n) and T (0 ≤ T < n). S ̸= T.
        cin >> numVertex >> numEdges >> S >> T;
        Graphl g(numVertex);
        for (int j = 0; j < numEdges; j++)
        {
            int vertexA, vertexB, wt;
            cin >> vertexA >> vertexB >> wt;

            g.setEdge(vertexA, vertexB, wt);
            g.setEdge(vertexB, vertexA, wt);
        }
        int dist[numVertex];

        g.Dijkstra(g,S,dist);

        if (dist[T]!=INFINITO)
        {
            printf("Case #%d: %d\n",i+1,dist[T]);
        }
        else{
            printf("Case #%d: unreachable\n",i+1);
        }
    }
}