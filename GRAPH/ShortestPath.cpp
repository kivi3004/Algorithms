
bool shortestPath(vector<int> graph[], int n, vector<int>& parent, int src, int dest){
    vector<bool> visit(n, false);
    queue<int> q;
    q.push(src);
    visit[src]=true;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : graph[u]){
            if(!visit[v]){
                visit[v] = true;
                q.push(v);
                parent[v] = u;
            }
            if(v==dest)
                return true;
        }

    }
    return false;

}

void shortestRoute(vector<int> graph[], int n, int src, int dest){
    vector<int> parent(n,-1);
    if(shortestPath(graph, n, parent, src, dest)){
        for(int p : parent)
            cout<<p<<" ";
        cout<<endl;
        int temp = dest;
        cout<<"Path between "<<src<<" and "<<dest<<" : ";
        vector<int> path;
        path.push_back(dest);
        while(parent[temp]!=-1){
            path.push_back(parent[temp]);
            temp = parent[temp];
        }
        for(int i=path.size()-1; i>=0; i--)
            cout<<path[i]<<" ";
    }
    else
    {
        cout<<"No Path is available between "<<src<<" and "<<dest;
    }
    
}
