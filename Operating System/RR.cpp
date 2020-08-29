#include<bits/stdc++.h>

using namespace std;

vector<int> waiting_Time(int n, int quantum, vector<int>& bt_time){
    vector<int> rm_time = bt_time;
    vector<int> wt_time(n);
    int t;
    t=0;
    while(true){
        bool done = true;
        for(int i=0; i<n; i++){
            if(rm_time[i]>0){
                done = false;
                if(rm_time[i]>quantum){
                    t += quantum;
                    rm_time[i] -= quantum;
                }
                else{
                    t += rm_time[i];
                    rm_time[i] = 0;
                    wt_time[i] = t - bt_time[i];
                }
            }
        }
        if(done)
            break;
    }
    return wt_time;
}

vector<int> turn_Around_time(int n, int quantum, vector<int>& wt_time, vector<int>& bt_time){
    vector<int> tat(n);
    for(int i=0; i<n; i++)
        tat[i] = wt_time[i]+ bt_time[i];
    return tat;
}

void average_Time(int n, int quantum, vector<int>& process, vector<int>& bt_time){
    vector<int> wt_time = waiting_Time(n, quantum, bt_time);
    vector<int> tat = turn_Around_time(n, quantum, wt_time, bt_time);
    int total_tat=0, total_wt=0;
    cout<<"Processes   ||  Burst_Time   ||  Waiting Time  ||  Turn Around Time  "<<endl;  
    for(int i=0; i<n; i++){
        cout<<"    "<<process[i]<<"      ||     "<<bt_time[i]<<"    ||      "<<wt_time[i]<<"        ||   "<<tat[i]<<endl;
        total_tat += tat[i];
        total_wt += wt_time[i]; 
    }
    cout<<"\n\n";
    cout<<"Average Waiting Time : "<<(float)total_wt/(float)n<<endl;
    cout<<"Average Turn Around Time : "<<(float)total_tat/(float)n<<endl;
}

int main(){
    int quantum;
    cout<<"Enter quantum time : ";
    cin>>quantum;
    int n;
    cout<<"Enter Number of Processes : ";
    cin>>n;
    vector<int> process(n);
    vector<int> burst_time(n);
    for(int i=0; i<n; i++){
        cin>>process[i];
        cin>>burst_time[i];
    }
    average_Time(n, quantum, process, burst_time);
}
