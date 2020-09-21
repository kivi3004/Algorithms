#include<bits/stdc++.h>

using namespace std;
bool check(vector<int> graph[], int v, int u, vector<bool>& visit){
    visit[v] = true;
    for(int k : graph[v]){
        if(!visit[k]){
            if(check(graph, k, v, visit))
                return true;
        }
        else if(k!=u)
            return true;
    }     
    return false;    
}
bool cycle(vector<int> graph[], int n){
    vector<bool> visit(n,false);
    for(int i=0; i<n; i++){
        if(!visit[i] && check(graph, i, -1, visit))
            return true;
    }
    return false;
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
        cout<<"Cycle Possible";
    else
    {
        cout<<"Cycle doesn't exist";
    }
    
      
}