#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct process
{
    int PID;
    int A;
    int T;
};

int main() {
    int n = 0;
    cin >> n;
    process p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].PID >> p[i].A >> p[i].T;
    }
    sort(p, p + n, [](process a, process b) {
        return a.A < b.A;
    });

    int j = 0;
    int time = 0;
    stack<process> s;
    while (j <= n-1)
    {
        cout << "Time: " << time << endl;
        cout << "J: " << j << endl;

        if(p[j+1].A == time){
            j++;
        }
        time++;
    }
    

    

    return 0;
}