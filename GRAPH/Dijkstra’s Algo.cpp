/* GFG solution 

int minDist(vector<int> dist, vector<bool> visit, int n){
    int min = INT_MAX;
    int min_ind;
    for(int i=0; i<n; i++)
        if(!visit[i] & min >= dist[i]){
            min = dist[i];
            min_ind = i;
        }
    return min_ind;
}
void Dijkstra(vector<pair<int, int>> graph[], int src, int n){
    vector<int> dist(n,INT_MAX);
    vector<bool> visit(n,false);
    dist[src] = 0;
    for(int i=0; i<n; i++){
        int u = minDist(dist, visit, n);
        visit[u] = true;
        if(visit[u]!=INT_MAX){
            for(auto v : graph[u])
                if(!visit[v.first] && (dist[u] + v.second)<dist[v.first]){
                    dist[v.first] = v.second+dist[u];
                }
        }
    }
    cout<<endl;
    cout<<"Distance of all vertex from "<<src<<" is : ";
    for(int d : dist)
        cout<<d<<" ";
    cout<<endl;
    
}*/

void shortestPath(vector<pair<int,int>> graph[], int n, vector<int>& parent, vector<int>& dist,int src, int dest){
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : graph[u]){
            if(dist[u]+v.second < dist[v.first]){
                q.push(v.first);
                dist[v.first] = dist[u]+v.second;
                parent[v.first] = u;
            }
        }
    }
}

void shortestRoute(vector<pair<int,int>> graph[], int n, int src, int dest){
    vector<int> parent(n,-1);
    vector<int> dist(n,INT_MAX);
    shortestPath(graph, n, parent, dist, src, dest);
    if(dist[dest]!=INT_MAX){
        cout<<endl;
        int temp = dest;
        vector<int> path;
        path.push_back(dest);
        while(parent[temp]!=-1){
            path.push_back(parent[temp]);
            temp = parent[temp];
        }
        cout<<"Total distance from "<<src<<" to "<<dest<<" : "<<dist[dest];
        cout<<endl;
        
        cout<<"Path between "<<src<<" and "<<dest<<" : ";
        for(int i=path.size()-1; i>=0; i--)
            cout<<path[i]<<" ";
        cout<<endl;

        cout<<"Distance of all vertex from "<<src<<" is : ";
        for(int d : dist)
            cout<<d<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"No Path is available between "<<src<<" and "<<dest;
    }
    
}
void add_edge(vector<pair<int,int>> graph[], int u, int v, int w){
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}

void print(vector<pair<int,int>> graph[], int n){
    cout<<"Adjency List Representation \n";
    for(int i=0; i<n; i++){
        cout<<i;
        for(auto v : graph[i])
            cout<<" -> "<<v.first<<"("<<v.second<<")";
        cout<<endl;
    }
}


int main(){
    int n;
    cout<<"Enter number of nodes(V) : ";
    cin>>n;
    vector<pair<int,int>> graph[n];
    vector<vector<int> > mat(n,vector<int>(n,0));
    char ch;
    cout<<"Enter edge (Y/N) : ";
    cin>>ch;
    while(ch!='N'){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(graph, u, v, w);
        cout<<"Enter edge (Y/N) : ";
        cin>>ch;
    }
    
    /*add_edge(graph, 0, 1, 4); 
    add_edge(graph, 0, 7, 8); 
    add_edge(graph, 1, 2, 8); 
    add_edge(graph, 1, 7, 11); 
    add_edge(graph, 2, 3, 7); 
    add_edge(graph, 2, 8, 2); 
    add_edge(graph, 2, 5, 4); 
    add_edge(graph, 3, 4, 9); 
    add_edge(graph, 3, 5, 14); 
    add_edge(graph, 4, 5, 10); 
    add_edge(graph, 5, 6, 2); 
    add_edge(graph, 6, 7, 1); 
    add_edge(graph, 6, 8, 6); 
    add_edge(graph, 7, 8, 7); */  
    
    
    int src, dest;
    cout<<"Enter starting vertex : ";
    cin>>src;
    cout<<"Enter destination vertex : ";
    cin>>dest;
    shortestRoute(graph, n, src, dest);
}
