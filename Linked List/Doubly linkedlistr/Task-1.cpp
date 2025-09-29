#include <iostream>
#include <vector>
using namespace std;

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;

    Process(int id, int at, int bt) {
        pid = id;
        arrivalTime = at;
        burstTime = bt;
        startTime = 0;
        completionTime = 0;
        turnaroundTime = 0;
        waitingTime = 0;
    }
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        int at, bt;
        cout << "Enter arrival time for P" << i + 1 << ": ";
        cin >> at;
        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> bt;
        processes.push_back(Process(i + 1, at, bt));
    }

    int currentTime = 0;
    double totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].startTime = currentTime;
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].startTime - processes[i].arrivalTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        currentTime = processes[i].completionTime;
    }

    cout << "\nPID\tArrival\tBurst\tStart\tCompletion\tTurnaround\tWaiting\n";
    for (auto& p : processes) {
        cout << "P" << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.startTime << "\t" << p.completionTime << "\t\t"
             << p.turnaroundTime << "\t\t" << p.waitingTime << endl;
    }

    cout << "\nAverage Waiting Time = " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time = " << totalTurnaroundTime / n << endl;

    return 0;
}
