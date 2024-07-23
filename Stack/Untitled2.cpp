#include <iostream>
#define ASIZE 5
using namespace std;
class Stack {
    public:
        int length = -1;
        char Array[ASIZE];
        void push(char data) {
            if(length >= (ASIZE-1)) {
                return;
            } 
            Array[++length] = data;
        }
        void pop() {
            if(length < 0) {
                return;
            }
			length -= 1;
        }
        void print() {
        	if(length >= 0) {
            cout << "Stack : ";
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
    string text;
    cin >> text;
    int strCount = text.length();
    for(int i = 0; i < strCount; i++) {
    	char d = text[i];
    	if(text[i] == '(') {
    		s.push(d);
		}
		if(text[i] == ')') {
			if(s.length == -1) {
				cout << "Error\n";
				return 0;
			}
			s.pop();
		}
	}
	
	if(s.length == -1) {
		cout << "Pass\n";
	} else {
		cout << "Error\n";
	}
    
    return 0;
}


