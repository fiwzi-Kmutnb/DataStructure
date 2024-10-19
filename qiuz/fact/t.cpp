#include <iostream>
#include <queue>

using namespace std;

// โครงสร้างสำหรับเก็บข้อมูลของแต่ละ process
struct Process {
    int pid;     // Process ID
    int arrival; // Arrival Time
    int service; // Service Time
};

// ฟังก์ชันสำหรับเรียงลำดับกระบวนการตาม Arrival Time (ใช้ Bubble Sort)
void bubbleSort(Process arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].arrival > arr[j + 1].arrival) {
                // สลับค่า
                Process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int quantum = 1;  // Quantum time set to 1 for Round Robin
    const int n = 2;        // จำนวน process
    
    Process processes[n] = {
        {2020, 0, 3},  // Process A: Arrival = 0, Service = 3
        {2010, 1, 5},  // Process B: Arrival = 2, Service = 6
        // {3, 4, 4},  // Process C: Arrival = 4, Service = 4
        // {4, 6, 5},  // Process D: Arrival = 6, Service = 5
        // {5, 8, 2}   // Process E: Arrival = 8, Service = 2
    };

    // เรียงลำดับกระบวนการตาม Arrival Time โดยใช้ Bubble Sort
    bubbleSort(processes, n);

    queue<Process> process_queue;
    int current_time = 0;
    int i = 0; // index ของ process ที่จะนำเข้า queue ต่อไป

    cout << "Gantt Chart (PID at time):\n";

    // จำลองการทำงานตาม Round Robin Scheduling
    while (i < n || !process_queue.empty()) {
        // เพิ่ม process ที่มาถึงเวลาปัจจุบันเข้า queue
        while (i < n && processes[i].arrival <= current_time) {
            process_queue.push(processes[i]);
            i++;
        }

        if (!process_queue.empty()) {
            Process current_process = process_queue.front();
            process_queue.pop();  // นำ process ออกจาก queue

            // ทำงานเป็นระยะเวลา quantum หรือจนกว่า process จะเสร็จสิ้น
            int exec_time = min(quantum, current_process.service);
            current_process.service -= exec_time;
            current_time += exec_time;

            // แสดงผลการทำงานในแต่ละหน่วยเวลา (Gantt Chart)
            cout << "Time " << current_time - exec_time << " to " << current_time 
                 << ": PID " << current_process.pid << endl;

            // ถ้า process ยังไม่เสร็จให้กลับเข้า queue
            if (current_process.service > 0) {
                // Process ที่ยังไม่เสร็จต้องถูกสลับกลับไปทำงานในรอบถัดไป
                process_queue.push(current_process);
            } else {
                // Process เสร็จสิ้น
                cout << "PID " << current_process.pid << " is completed." << endl;
            }
        } else {
            // ไม่มี process ใน queue ให้เวลาผ่านไป
            current_time++;
        }
    }

    return 0;
}
