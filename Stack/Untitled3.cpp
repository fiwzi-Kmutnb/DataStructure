#include <iostream>
#define ASIZE 5
using namespace std;
class Stack {
    public:
        int length = -1;
        int Array[ASIZE];
        void push(int data) {
            if(length >= (ASIZE-1)) {
                return;
            } 
            Array[++length] = data;
        }
        void pop() {
            if(length < 0) {
                return;
            }
			length--;
        }
        void print() {
        	if(length >= 0) {
            int i = 0;
            for(i = 0; i <= length; i++) {
                cout << Array[i] << " ";
            }
            cout << "\n";
			}
        }
        
};

int main() {
	Stack s;
	char t;
	int u = 0;
	while(true) {
		
	cin >> t;
	if(t == 'U') {
			cin >> u;
			s.push(u);
	}
	if(t == 'P') {
			s.print();
	}
	if(t == 'T') {
			cout << s.Array[s.length]  << "\n";
	}
	if(t == 'N') {
			cout << s.length+1  << "\n";
	}
	if(t == 'O') {
			cout << s.Array[s.length]  << "\n";
			s.pop();
	}
	if(t == 'X') {
		break;
	}
	}
    return 0;
}


