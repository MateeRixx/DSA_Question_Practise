#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process {
public:
    int pid;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;

    Process(int id, int bt) {
        pid = id;
        burstTime = bt;
        remainingTime = bt;
        waitingTime = 0;
        turnaroundTime = 0;
    }
};

int main() {
    int n, timeQuantum;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++) {
        int bt;
        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> bt;
        processes.push_back(Process(i + 1, bt));
    }

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);

    int currentTime = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (processes[i].remainingTime > timeQuantum) {
            currentTime += timeQuantum;
            processes[i].remainingTime -= timeQuantum;

            for (int j = 0; j < n; j++) {
                if (j != i && processes[j].remainingTime > 0)
                    processes[j].waitingTime += timeQuantum;
            }

            q.push(i);
        } else {
            int execTime = processes[i].remainingTime;
            currentTime += execTime;
            processes[i].remainingTime = 0;

            for (int j = 0; j < n; j++) {
                if (j != i && processes[j].remainingTime > 0)
                    processes[j].waitingTime += execTime;
            }
        }
    }

    double totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    cout << "\nPID\tBurst\tWaiting\tTurnaround\n";
    for (auto& p : processes) {
        cout << "P" << p.pid << "\t" << p.burstTime << "\t"
             << p.waitingTime << "\t" << p.turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time = " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time = " << totalTurnaroundTime / n << endl;

    return 0;
}
