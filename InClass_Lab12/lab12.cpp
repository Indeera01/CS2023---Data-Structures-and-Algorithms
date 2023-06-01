#include <iostream>

using namespace std;

#define max 6
#define INFINITY 9999

int minTime(int time[], bool sptSet[])
{
    int min = INFINITY;
    int indexMin;

    for(int v=0; v<max; v++)
    {
        if(sptSet[v] == false && time[v] <= min)
        {
            min = time[v];
            indexMin = v;
        }
    }
    return indexMin;
}

void displayTime(int time[])
{
    for(int i=0; i<max; i++)
    {
        cout << "Time taken from the source to the city "<< i <<  " = " << time[i] << endl;
    }
}

void dijkstra(int graph[max][max], int src)
{
    int time[max];
    bool sptSet[max];

    for(int i=0; i<max; i++)
    {
        time[i] = INFINITY;
        sptSet[i] = false;
    }

    time[src] = 0;

    for(int count=0; count<max-1; count++)
    {
        int u = minTime(time, sptSet);
        sptSet[u] = true;

        for(int v=0; v<max; v++)
        {
            if(!sptSet[v] && graph[u][v] && time[u] != INFINITY && time[u] + graph[u][v] < time[v])
            {
                time[v] = time[u] + graph[u][v];
            }
        }
    }

    cout << "Starting city " << src << endl;

    displayTime(time);
}


int main() {
    int graph[max][max] = {
        { 0, 10,  0,  0, 15,  5},
        {10,  0, 10, 30,  0,  0},
        { 0, 10,  0, 12,  5,  0},
        { 0, 30, 12,  0,  0, 20},
        {15,  0,  5,  0,  0,  0},
        { 5,  0,  0, 20,  0,  0}
    };
    int src = 5;
    dijkstra(graph, src);
    return 0;
}

