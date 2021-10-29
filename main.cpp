#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define MX 110

vector < int > graph[MX];
bool vis[MX];
int dist[MX];

void bfs(int source){
    queue < int > Q;

    vis[source] = 1;
    cout<<source<<"\t";
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                vis[next] = 1; // visit
                cout<<next<<"\t";
                dist[next] = dist[node] + 1;
                Q.push(next); // push to queue
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cout<< "enter how many node and edges you want to enter";
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++){
        int u, v;
        cout<<"enter directed edges";
        cin >> u >> v;
        graph[u].push_back(v);

    }

    int source;
    cout<<"enter the source node";
    cin >> source;
    cout<<"Following is the breadth first traversal"<<endl;
    bfs(source);
    cout<<endl<<"the distance of each node from source node"<<endl;
    cout << "From source node " << source << endl;
    for (int i = 1; i <= nodes; i++){
        cout << "Distance of " << i << " is : " << dist[i] << endl;
    }

    return 0;
}
