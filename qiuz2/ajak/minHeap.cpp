#include <iostream>
#include <limits.h>
using namespace std;
#define MAX 50

int arr[MAX];
int count;

void init();
int  parentOf(int i);
void swap(int i, int j);
void insert(int value);
void print();

void init(){
	count = 0;
	for (int i=0; i<MAX; i++){
		arr[i] = INT_MIN;
	}
}

int parentOf(int i){
	return i/2;
}

int leftChildOf(int i){
	return i*2;
}

int rightChildOf(int i){
	return i*2 + 1;
}

void swap(int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void insert(int value){
	// 1. maintain Complete Binary Tree
	count++;
	arr[count] = value;
	
	// 2. maintain Heap Property of a MIN heap
	int temp = count;
	int parent = parentOf(temp);
	while (arr[parent] > arr[temp]) {
		swap(temp, parent);
		temp = parent;
		parent = parentOf(temp);
	}
	print();
	
}

void print(){
	for (int i=1; i<= count; i++){
		cout << arr[i] << "  ";
	}
	
	cout << endl;
}

int removeSmallest(){
	// 1. save smallest for return
	int smallest = arr[1];
	
	// 2. remove last node
	arr[1] = arr[count];
	count--;
	
	// 3. heapify
	heapify(1);
//	int temp = 1;
//	while (leftChildOf(temp) <= count){ 
//		int min = leftChildOf(temp);
//		int rightChild = min+1;
//		if (rightChild <= count){  
//			if (arr[rightChild] < arr[min]) 
//			    min= rightChild;
//		}
//		if (arr[temp] <= arr[min]) break;
//		swap(temp, min);
//		temp = min;	
//	}
	
	// 4. return the smallest
	return smallest;
}

void heapify(int parent){
	int temp = parent;
	while (leftChildOf(temp) <= count){ 
		int min = leftChildOf(temp);
		int rightChild = min+1;
		if (rightChild <= count){  
			if (arr[rightChild] < arr[min]) 
			    min= rightChild;
		}
		if (arr[temp] <= arr[min]) break;
		swap(temp, min);
		temp = min;	
	}
}

void heapConstruction(){
	// 1. read all input into array
	cin >> count;
	for (int i=1; i<=count; i++){
		cin >> arr[i];
	}
	
	// 2. Repeatedly heapify from last parent to first parent (bottom up)
	int parent = count/2;
	for (; parent>0; parent--){
		heapify(parent);
	}
}


int main(){
	init();
	
	for (int i =10; i>0; i--){
		insert(i);
	}
	for (int i =10; i>0; i--){
		int smallest = removeSmallest();
		cout << "Remove " << smallest << endl;
		print();
	}
	return 0;
}
