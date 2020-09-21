/*Directed Graph*/


bool isCycle(int V, vector<int> adj) 
{ 
    vector<int> in_degree(V, 0); 
    for (int u = 0; u < V; u++) { 
        for (auto v : adj[u]) 
            in_degree[v]++; 
    } 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
    int cnt=0;
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop();
        for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
        cnt++; 
    }  
    if (cnt != V)  
        return true; 
    else
        return false; 
} 


/*Undirected Graph*/

bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool>& visited) 
{ 
    // Set parent vertex for every vertex as -1. 
    vector<int> parent(V, -1);
    queue<int> q; 
    visited[s] = true; 
    q.push(s); 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop();
        for (auto v : adj[u]) { 
            if (!visited[v]) { 
                visited[v] = true; 
                q.push(v); 
                parent[v] = u; 
            } 
            else if (parent[u] != v) 
                return true; 
        } 
    } 
    return false; 
} 
  
bool isCyclic(vector<int> adj[], int V) 
{ 
    vector<bool> visited(V, false); 
    for (int i = 0; i < V; i++) 
        if (!visited[i] && isCyclicConntected(adj, i, V, visited)) 
            return true; 
    return false; 
} 
