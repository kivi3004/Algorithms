#include<bits/stdc++.h>

using namespace std;

void topologicalRoute(int i, vector<int> graph[], vector<bool> &visit, stack<int>& st){
    visit[i]=true;
    for(int k=0; k<graph[i].size(); k++){
        if(!visit[graph[i][k]])
            topologicalRoute(graph[i][k], graph, visit,st);
    }
    st.push(i);
}
void topologicalSort(vector<int> graph[], int n){
    cout<<"Topological order: ";
    vector<bool> visit(n, false);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!visit[i])
            topologicalRoute(i, graph, visit, st);
    }
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void AllTopologicalRoute(vector<bool>& visit, vector<int>& res, int n, vector<int> graph[], vector<int>& indegree){
    bool flag = false;
    for(int u=0; u<n; u++){
        if(indegree[u]==0 && !visit[u]){
            for(auto k : graph[u]){
                indegree[k]--;
            }
            res.push_back(u);
            visit[u] = true;
            AllTopologicalRoute(visit, res, n, graph, indegree);

            visit[u] = false;
            res.pop_back();
            for(auto k : graph[u]){
                indegree[k]++;
            }
            flag=true;
        }
    }
    if(!flag){
        for(int v : res)
            cout<<v<<" ";
        cout<<endl;
    }
}
void InDegree(vector<int> graph[], vector<int>& indegree, int n){
    for(int i=0; i<n; i++){
        for(auto u : graph[i])
            indegree[u]++;
    }
}
void AllTopological(vector<int> graph[], int n){
    vector<int> indegree(n);
    InDegree(graph, indegree, n);
    vector<bool> visit(n,false);
    vector<int> res;
    AllTopologicalRoute(visit, res, n, graph, indegree);
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
    topologicalSort(graph, n);    
    
    cout<<"All Topological Order : \n";
    AllTopological(graph, n);
}
