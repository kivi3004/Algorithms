
import java.text.ParseException;
import java.util.Scanner;
class First_come_first_serve {
    static void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
        wt[0] = 0;
        for (int i = 1; i < n; i++) {
            wt[i] = bt[i - 1] + wt[i - 1];
        }
    }
    static void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
        for (int i = 0; i < n; i++) {
            tat[i] = bt[i] + wt[i];
        }
    }
    static void inputProcess(int processes[], int n, int bt[]){
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<n; i++){
            processes[i] =i+1;
            int x = sc.nextInt();
            bt[i]=x;
        }
    }
    static void findavgTime(int processes[], int n, int bt[]) {
        int wt[] = new int[n], tat[] = new int[n];
        int total_wt = 0, total_tat = 0;

        findWaitingTime(processes, n, bt, wt);

        //Function to find turn around time for all processes
        findTurnAroundTime(processes, n, bt, wt, tat);

        //Display processes along with all details
        System.out.printf("Processes || Burst time || Waiting time || Turn around time\n");
        for (int i = 0; i < n; i++) {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            System.out.printf("    %d     ||", processes[i]);
            System.out.printf("   	%d       ||", bt[i]);
            System.out.printf("       %d      ||", wt[i]);
            System.out.printf("	 %d\n", tat[i]);
        }
        float s = (float)total_wt /(float) n;
        int t = total_tat / n;
        System.out.printf("Average waiting time = %f", s);
        System.out.printf("\n");
        System.out.printf("Average turn around time = %d ", t);
    }

    // Driver code
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int processes[] = new int[n];
        int burst_time[] = new int[n];
        inputProcess(processes, n, burst_time);
        findavgTime(processes, n, burst_time);

    }
}