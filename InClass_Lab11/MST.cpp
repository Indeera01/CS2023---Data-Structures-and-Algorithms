#include <iostream>

using namespace std;

#define V 6
#define INFINITY 9999

// to find the pole with the minimum distance, from the poles not yet included in the MST

int minDist(int distances[], bool MST[])
{
    int min = INFINITY;
    int minIndex;

    for (int v=0; v<V; v++)
    {
        if (MST[v] == false && distances[v] < min)
        {
            min = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void displayMST(int graph[V][V])
{
    int final[V];
    int distances[V];
    bool MST[V];

    for (int i=0; i<V; i++)
    {
        distances[i] = INFINITY;
        MST[i] = false;
    }

    distances[0] = 0;  // to start from the first pole

    final[0] = -1;

    for (int i = 0; i < V-1; i++)
    {
        int u = minDist(distances, MST);

        MST[u] = true;

        for (int v=0; v<V; v++)
        {
            if (graph[u][v] && MST[v] == false && graph[u][v] < distances[v])
            {
                final[v] = u;
                distances[v] = graph[u][v];
            }
        }
    }

    // to print the MST

    cout << "Edge" << "    " << "Weight" <<endl;
    for (int i=1; i<V; i++)
    {
        cout << final[i] << " - " << i << "    " << graph[i][final[i]] << endl;
    }
}


int main()
{
    int graph[V][V] = { {0, 3, 0, 0, 0, 1},
                        {3, 0, 2, 1, 10, 0},
                        {0, 2, 0, 3, 0, 5},
                        {0, 1, 3, 0, 5, 0},
                        {0, 10, 0, 5, 0, 4},
                        {1, 0, 5, 0, 4, 0} };

    displayMST(graph);
}
