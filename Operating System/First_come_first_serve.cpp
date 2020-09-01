#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>& pro){
    cout<<"Process  Arrival Time  Burst Time  WAiting Time  Turn Around Time   Completion Time\n";
    for(int i=0; i<pro.size(); i++){
        for(int j=0; j<pro[i].size(); j++)
            cout<<pro[i][j]<<"             ";
        cout<<endl;
    }
    cout<<endl;
}
void findWaitingTime(vector<vector<int>>& pro, int n)
{
    int bt=0;
    pro[0].push_back(0);
    for (int i = 1; i < n; i++)
    {
        bt = (pro[i][1] > bt+pro[i-1][2] ) ? 0 : (bt+pro[i-1][2]-(pro[i][1]-pro[i-1][1]));
        pro[i].push_back(bt);
    
    }
}
void findTurnAroundTime(vector<vector<int>>& pro, int n)
{  
    for (int i = 0; i < n; i++)
    {
        pro[i].push_back(pro[i][2] + pro[i][3]);
        pro[i].push_back(pro[i][4] + pro[i][1]);
    }
}
int main()
{
    int n;
    cout << "Enter Number Of Process :";
    cin >> n;
    vector<vector<int>> pro;
    for (int i = 1; i <= n; i++)
    {
        vector<int> v(3);     /*Process     ArrivalTime    BurstTime*/
        cout << "Enter process " << i << " Arrival Time and Burst Time:";
        v[0] = i;
        cin >> v[1];
        cin >> v[2];
        if (pro.empty())
            pro.push_back(v);
        else
        {
            int j = pro.size() - 1;
            while (j >= 0 && pro[j][1] > v[1])   /*Sorting Processes according to arrival time*/
                j--;
            pro.insert(begin(pro) + j + 1, v);
        }
    }
    findWaitingTime(pro, n);
    findTurnAroundTime(pro, n);
    sort(begin(pro), end(pro));
    print(pro);
}
