#include<bits/stdc++.h>


using namespace std;
void add_edge(vector<int> graph[], int u, int v, vector<vector<int> >& mat){
    graph[u].push_back(v);
    graph[v].push_back(u);
    mat[u][v] = 1;
    mat[v][u] = 1;
}

void print(vector<int> graph[], int n, vector<vector<int> > mat){
    cout<<"Adjency List Representation \n";
    for(int i=0; i<n; i++){
        cout<<i;
        for(int v : graph[i])
            cout<<" ->"<<v;
        cout<<endl;
    }
    cout<<"\n\n Adjency Matrix Representation \n";
    cout<<"   ";
    for(int i=0; i<n; i++)
        cout<<" "<<i<<" ";
    cout<<"\n--|------------------------\n";
    for(int i=0; i<n; i++){
        cout<<" "<<i<<"|";
        for(int j=0; j<n; j++)
            cout<<" "<<mat[i][j]<<" ";
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
        add_edge(graph, u, v, mat);
        cout<<"Enter edge (Y/N) : ";
        cin>>ch;
    }
    print(graph,n,mat);

}