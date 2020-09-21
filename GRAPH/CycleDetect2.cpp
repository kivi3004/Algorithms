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
