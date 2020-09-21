#include<bits/stdc++.h>

using namespace std;
bool check(vector<int> graph[], int u, vector<bool>& visit){
    for(int i=0; i<graph[u].size(); i++){
        if(visit[graph[u][i]])
            return true;
        visit[graph[u][i]] = true;
        if(check(graph, graph[u][i], visit))
            return true;
        visit[graph[u][i]] =false;
    }     
    return false;    
}
bool cycle(vector<int> graph[], int u, int n){
    vector<bool> visit(n,false);
    visit[u]=true;
    return check(graph, u, visit);
}

void add_edge(vector<int> graph[], int u, int v){
    graph[u].push_back(v);
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
    int i;
    for(i=0; i<n; i++)
        if(cycle(graph, i, n))
            break;
    if(i==n)
        cout<<"Cycle Doesn't Exist";
    else
        cout<<"Cycle Exist";
}
