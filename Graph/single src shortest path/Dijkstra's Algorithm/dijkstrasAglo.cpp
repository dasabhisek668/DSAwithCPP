#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
    vector<vector<pair<int,int>>> adjList(V);
    
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        
        adjList[u].push_back({v , w});
        adjList[v].push_back({u , w});
    }
    vector<int> dist(V , 1e9);
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0 , src});
    dist[src] = 0;
    
    while(!pq.empty()) {
        
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(d > dist[u]) continue; //if the node got a smaller distance
        
        for(auto &it : adjList[u]) {
            int v = it.first;
            int w = it.second;
            
            if(dist[v] > dist[u] + w ) {
                
                dist[v] = dist[u] + w;
                pq.push({dist[v] , v});
            }
        }
    }
    
    return dist;
    
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    if (!(cin >> V)) return 0;
    cout << "Enter the number of edges: ";
    if (!(cin >> E)) return 0;

    vector<vector<int>> edges;
    cout << "Enter the edges (u, v, weight) for each of the " << E << " edges:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        if (cin >> u >> v >> w) {
            edges.push_back({u, v, w});
        }
    }

    int src;
    cout << "Enter the source vertex: ";
    if (!(cin >> src)) return 0;

    vector<int> dist = dijkstra(V, edges, src);

    cout << "\nShortest distances from source vertex " << src << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == 1e9) {
            cout << "To vertex " << i << ": INF" << endl;
        } else {
            cout << "To vertex " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}