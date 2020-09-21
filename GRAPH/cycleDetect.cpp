#include<bits/stdc++.h>

using namespace std;
bool check(vector<int> graph[], int u, vector<bool>& visit){
    visit[u] = true;
    for(int v : graph[u]){
        if(visit[v])
            return true;
        visit[v] = true;
        if(check(graph, v, visit))
            return true;
        visit[v] = false;
    }     
    visit[u] = false;
    return false;    
}
bool cycle(vector<int> graph[], int n){
    vector<bool> visit(n,false);
    for(int i=0; i<n; i++){
        if(!visit[i])
            if(check(graph, i, visit))
                return true;
    }    
    return false;
}

void add_edge(vector<int> graph[], int u, int v){
    graph[u].push_back(v);
}

void print(vector<int> graph[], int n){
    cout<<"Adjency List Representation \n";
    for(int i=0; i<n; i++){
        cout<<i;
        for(int v : graph[i])
            cout<<" -> "<<v;
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
    if(cycle(graph, n))
        cout<<"Cycle exist";
    else
        cout<<"Cycle doesn't exist";
        
}
