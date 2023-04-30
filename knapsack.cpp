#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int MFKnapsack(int i, int j, int w[], int v[], int **F)
{
    int value;
    if (F[i][j] < 0)
    {
        if (j < w[i])
        {
            value = MFKnapsack(i - 1, j, w, v, F);
            cout << value << std::endl;
        }
        else
        {
            value = max(MFKnapsack(i - 1, j, w, v, F), v[i] + MFKnapsack(i - 1, j - w[i], w, v, F));
            cout << value << std::endl;
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int Knapsack(int n, int W, int w[], int v[], int **F)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                F[i][j] = 0;
            }
            else if (w[i] <= j)
            {
                F[i][j] = max(F[i - 1][j], v[i] + F[i - 1][j - w[i]]);
            }
            else
            {
                F[i][j] = F[i - 1][j];
            }
            std::cout << F[i][j] << " - ";
        }
        std::cout << std::endl;
    }
    return F[n][W];
}

int main(int argc, char const *argv[])
{
    int n = 4;
    int W = 5;
    int w[W] = {0, 2, 1, 3, 2};
    int v[W] = {0, 12, 10, 20, 15};

    // Alocando a matriz dinâmicamente
    int **F = new int *[n];

    for (int i = 0; i <= n; i++)
    {
        F[i] = new int[W];
        for (int j = 0; j <= W; j++)
        {
            F[i][j] = 0;
        }
    }

    

    cout << MFKnapsack(n, W, w, v, F) << endl;
    // Libere a memória alocada dinamicamente quando você acabar de usar.
    free(F);
    return 0;
}