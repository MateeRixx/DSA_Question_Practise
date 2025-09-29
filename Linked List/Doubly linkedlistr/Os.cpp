#include<bits/stdc++.h>
using namespace std;

class Node_t {
public:
    int tickets;
    Node_t* next;

    Node_t(int tickets) : tickets(tickets), next(NULL) {}
};

int main() {
    // Create a simple linked list of jobs
    Node_t* head = new Node_t(10);
    head->next = new Node_t(20);
    head->next->next = new Node_t(30);

    int totalTickets = 10 + 20 + 30;
    int winner = rand() % totalTickets + 1;

    int currentTicket = 0;
    Node_t* currentjob = head;

    while (currentjob) {
        currentTicket += currentjob->tickets;
        if (currentTicket >= winner) {
            cout << "Winner found, tickets held: " << currentjob->tickets << endl;
            break;
        }
        currentjob = currentjob->next;
    }

    // Free allocated nodes (good practice)
    while (head) {
        Node_t* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
