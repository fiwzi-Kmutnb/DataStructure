#include <iostream>
#define asize 100
using namespace std;

class Heap {
	public:
		int arr[asize] = {0};
		int index = 0;
		void add(int a) {
			arr[++index] = a;
			for(int i = index; i >= 2; i--) {
				if(arr[i] > arr[(i / 2)]) {
					int temp = arr[(i / 2)];
					arr[(i / 2)] = arr[i];
					arr[i] = temp;
				}
			}
		}
		void remove() {
			cout << arr[1] << "\n";
			arr[1] = arr[index];
			if(index >= 1)
				index--;
			for(int i = 1; i < index; i++) {
				if(arr[i] < arr[2*i] && arr[2*i] >= arr[2*i+1]) {
					int temp = arr[2*i];
					arr[2*i] = arr[i];
					arr[i] = temp;
				} 
				else if(arr[i] < arr[2*i] && arr[2*i] <= arr[2*i+1]) {
					int temp = arr[2*i+1];
					arr[2*i+1] = arr[i];
					arr[i] = temp;
				}
			}
		}
		void print() {
			for(int i = 1; i <= index; i++){
				cout << arr[i] << " ";
			}	
			cout << "\n";
		}
};


int main() {
	Heap h;
	char type;
	int value = 0;
	while(true) {
		cin >> type;
		switch(type) {
			case 'a':
				cin >> value;
				h.add(value);
				break;
			case 'p':
				h.print();
				break;
			case 'd':
				h.remove();
				break;
			case 'e':
				return 0;
			default:
				return 0;
		}
	}
	return 0;
}
