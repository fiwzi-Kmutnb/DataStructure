#include <iostream>
#include <stack>

using namespace std;

struct Process {
    int pid;    
    int arrival; 
    int service;
};

void Sort(Process arr[],int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i].arrival > arr[j].arrival){
                Process temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
}

int main() {
    int n;
    cin >> n;

    Process processes[n]; 

    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].service;
    }

    Sort(processes, n);

    stack<Process> process_stack;
    int current_time = 0;
    int i = 0;
    while (i < n || !process_stack.empty()) {
        while (i < n && processes[i].arrival <= current_time) {
            process_stack.push(processes[i]);
            i++;
        }
        if (!process_stack.empty()) {
            Process current_process = process_stack.top();
            process_stack.pop(); 

            while (current_process.service > 0) {
                cout << current_process.pid << ": " << current_process.service << endl;
                current_process.service--;
                current_time++;
            }
        } else {
            current_time++;
        }
    }

    return 0;
}
