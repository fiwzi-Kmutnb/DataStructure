#include <iostream>
using namespace std;

int main() {
    int n,m,p;
    cin >> n >> m >> p;
    int *data = new int[(m+1)*(p+1)];
    int vs = 0;
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            vs += 1;
            if(vs > n) break;
            int d;
            cin >> d;
            data[i * (p + 1) + j] = d;
            data[m * (p + 1) + j] += d;
            data[i * (p + 1) + p] += d;
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= p; j++)
        {
            if(j == p)
                cout << "| ";
            cout << data[i * (p + 1) + j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}