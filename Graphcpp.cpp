#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#define INFINITO 999999

using namespace std;

class Graph
{
private:
    int **matrix;
    int numEdge;
    int numVertex;
    bool *mark;

public:
    Graph(int n)
    {
        mark = new bool[n];
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
        numEdge = 0;
        numVertex = n;
    }

    int n()
    {
        return numVertex;
    }

    int e()
    {
        return numEdge;
    }

    int first(int v)
    {
        for (int i = 0; i < n(); i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return n();
    }

    int next(int v, int w)
    {
        for (int i = w + 1; i < n(); i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return n();
    }

    void setMark(int i, bool value)
    {
        mark[i] = value;
    }

    bool getMark(int v)
    {
        return mark[v];
    }

    void BFS(int start)
    {
        int v, w;
        queue<int> Q;
        Q.push(start);
        setMark(start, true);
        while (Q.size() > 0)
        {
            v = Q.front();
            Q.pop();
            printf("%d", v);
            w = first(v);

            while (w < n())
            {
                if (!(getMark(w)))
                {
                    setMark(w, true);
                    Q.push(w);
                }
                w = next(v, w);
            }
        }
    }

    void DFS(int v)
    {
        setMark(v, true);
        int w = first(v);
        while (w < n())
        {
            if (!(getMark(w)))
            {
                DFS(w);
            }
            w = next(v, w);
        }
        printf("%d -", v);
    }

    void Dijkstra(int s, int D[])
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> H;
        tuple<int, int, int> edge, temp;
        //(dist,p,v)
        int p, v;
        int P[n()];
        for (int i = 0; i < n(); i++)
        {
            D[i] = INFINITO;
            P[i] = -1;
            setMark(i, false);
        }
        edge = make_tuple(0, s, s);
        H.push(edge);
        D[s] = 0;
        for (int i = 0; i < n(); i++)
        {
            do
            {
                if (H.empty())
                {
                    break;
                }
                edge = H.top();
                v = get<2>(edge);
                p = get<1>(edge);
                H.pop();
            } while (getMark(v) != false);
            setMark(v, true);
            P[v] = p;
            int w = first(v);
            while (w < n())
            {
                if ((!(getMark(w))) && (D[w] > (D[v] + matrix[v][w])))
                {
                    D[w] = D[v] + matrix[v][w];
                    temp = make_tuple(D[w], v, w);
                    H.push(temp);
                }
                w = next(v, w);
            }
        }
    }

    void Prim(int D[], int V[])
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> H;
        tuple<int, int, int> edge, temp;
        //(dist,p,v)
        int p, v;
        for (int i = 0; i < n(); i++)
        {
            D[i] = INFINITO;
            V[i] = -1;
            setMark(i, false);
        }
        edge = make_tuple(0, 0, 0);
        H.push(edge);
        D[0] = 0;
        for (int i = 0; i < n(); i++)
        {
            do
            {
                if (H.empty())
                {
                    break;
                }
                edge = H.top();
                v = get<2>(edge);
                p = get<1>(edge);
                H.pop();
            } while (getMark(v) != false);
            setMark(v, true);
            V[v] = p;
            int w = first(v);
            while (w < n())
            {
                if ((!(getMark(w))) && (D[w] > matrix[v][w]))
                {
                    D[w] = matrix[v][w];
                    temp = make_tuple(D[w], v, w);
                    H.push(temp);
                }
                w = next(v, w);
            }
        }
    }

    void graphTraverse()
    {
        for (int v = 0; v < n(); v++)
        {
            setMark(v, false);
        }
        for (int v = 0; v < n(); v++)
        {
            if (!(getMark(v)))
            {
                DFS(v);
            }
        }
    }

    void setEdge(int i, int j, int wt)
    {
        if (wt == 0)
        {
            printf("Erro!");
        }
        if (matrix[i][j] == 0)
        {
            numEdge++;
        }
        matrix[i][j] = wt;
    }

    void delEdge(int i, int j)
    {
        if (matrix[i][j] != 0)
        {
            numEdge--;
        }
        matrix[i][j] = 0;
    }
    void toposort(int v, stack<int> s)
    {
        setMark(v, true);
        int w = first(v);
        while (w < n())
        {
            if (!(getMark(w)))
            {
                toposort(w, s);
            }
            w = next(v, w);
        }
        s.push(v);
    }
};

int main()
{
    Graph g(5);
    /* Exemplo Slide Prim/Dijkstra
    g.setEdge(0, 1, 10);
    g.setEdge(0, 2, 3);
    g.setEdge(0, 3, 20);
    g.setEdge(1, 0, 10);
    g.setEdge(1, 2, 3);
    g.setEdge(1, 3, 5);
    g.setEdge(2, 0, 3);
    g.setEdge(2, 1, 2);
    g.setEdge(2, 5, 15);
    g.setEdge(3, 0, 20);
    g.setEdge(3, 1, 5);
    g.setEdge(3, 4, 11);
    g.setEdge(4, 2, 15);
    g.setEdge(4, 3, 11);*/
    
    // Exemplo AP12 Prim
    
    g.setEdge(0, 1, 6);
    g.setEdge(1, 0, 6);
    g.setEdge(2, 3, 2);
    g.setEdge(3, 2, 2);
    g.setEdge(4, 0, 7);
    g.setEdge(0, 4, 7);
    g.setEdge(2, 1, 15);
    g.setEdge(1, 2, 15);
    g.setEdge(3, 1, 3);
    g.setEdge(1, 3, 3);
    
    int D[5];
    int V[5];
    int custo=0;
   
    g.Prim(D,V);

    for (int i = 0; i < 5; i++)
    {
        custo+=D[i];
    }

    cout << custo << endl;
}