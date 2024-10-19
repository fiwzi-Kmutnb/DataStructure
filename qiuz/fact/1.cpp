#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    stack<char> st;
    int suss = 0,fail = 0;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '<' || s[i] == '[' || s[i] == '{' || s[i] == '(')
            st.push(s[i]);
        if(s[i] == '>' || s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if(st.empty())
            {
                fail++;
            } else {
                st.pop();
                suss++;
            }
        }
    }
    while (!st.empty())
    {
        fail++;
        st.pop();
    }
    
    cout << "Suss: " << suss << endl;
    cout << "Fail: " << fail << endl;

    return 0;
}