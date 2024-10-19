#include <iostream>
#include <stack>
using namespace std;

struct process
{
    int PID;
    int A;
    int T;
};



int main()
{
    int n = 0;
    cin >> n;
    stack<process> s ;
    for (int i = 0; i < n; i++)
    {
        process p;
        cin >> p.PID >> p.A >> p.T;
        s.push(p);
    }
    process k;
    process c;
    for (int i = 0; i < n; i++)
    {
        if(s.top().A == 0){
            for (int i = 0; i < n; i++)
            {
                s.pop();
                if(s.top().T < c.T){
                    c = s.top();
                }
                
            }
            


            
        }
    }
    

    return 0;
}
