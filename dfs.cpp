#include<bits/stdc++.h>
using namespace std;

vector <int> graph[5];
bool visited[5];

void dfs(int source){
  //  cout<<source;
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++){
        int next = graph[source][i];
        if (visited[next] == 0){
                cout<<next;
            dfs(next);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cin >> source;
    cout<<source;
    dfs(source);

    //for (int i = 0; i < nodes; i++){
   //     if (visited[i] == 1){
   //         cout << "Node " << i << " is visited." << endl;

   //     }
    //    else{
        //    cout << "Node " << i << " is not visited" << endl;
      //  }
  //  }

    return 0;
}
