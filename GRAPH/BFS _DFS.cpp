#include<bits/stdc++.h>

using namespace std;

void dfsRoute(int i, vector<int> graph[], vector<bool> &visit){
    cout<<i<<" ";
    visit[i]=true;
    for(int k=0; k<graph[i].size(); k++){
        if(!visit[graph[i][k]])
            dfsRoute(graph[i][k], graph, visit);
    }
}
void dfs(vector<int> graph[], int n){
    cout<<"DFS Traversal through Recursion: ";
    vector<bool> visit(n, false);
    for(int i=0; i<n; i++){
        if(!visit[i])
            dfsRoute(i, graph, visit);
    }

}
void dfsIterative(vector<int> graph[], int n){
    cout<<"DFS Traversal through Iteration: ";
    vector<bool> visit(n, false);
    stack<int> st;
    st.push(0);
    while(st.size()){
        int u = st.top();
        st.pop();
        if(!visit[u]){
            visit[u]=true;
            cout<<u<<" ";
        }
        for(int i=0; i<graph[u].size(); i++)
            if(!visit[graph[u][i]])
                st.push(graph[u][i]);
    }

}

void bfsIterative(vector<int> graph[], int n){
    cout<<"BFS Traversal: ";
    vector<bool> visit(n, false);
    queue<int> queue;
    queue.push(0);
    visit[0]=true;
    while(queue.size()){
        int u = queue.front();
        queue.pop();
        cout<<u<<" ";
        for(int i=0; i<graph[u].size(); i++)
            if(!visit[graph[u][i]]){
                visit[graph[u][i]]=true;
                queue.push(graph[u][i]);
            }
    }

}
void add_edge(vector<int> graph[], int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void print(vector<int> graph[], int n){
    cout<<"Adjency List Representation \n";
    for(int i=0; i<n; i++){
        cout<<i;
        for(int v : graph[i])
            cout<<" ->"<<v;
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of nodes(V) : ";
    cin>>n;
    vector<int> graph[n];
    vector<vector<int> > mat(n,vector<int>(n,0));
    char ch;
    cout<<"Enter edge (Y/N) : ";
    cin>>ch;
    while(ch!='N'){
        int u,v;
        cin>>u>>v;
        add_edge(graph, u, v);
        cout<<"Enter edge (Y/N) : ";
        cin>>ch;
    }
    print(graph,n);
    dfs(graph, n);
    cout<<endl;
    dfsIterative(graph, n);
    bfsIterative(graph, n);

}