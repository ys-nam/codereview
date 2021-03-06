#include <iostream>
#include <cstdlib>
#include "priority_queue.h"

using namespace std;

template <typename T>
void pushQueue(templatePriorityQueue<T>* Que, int data){
	cout << " [+] Integer "<< data <<" pushed in the Priority Queue. " << endl;
	Que->push(data);
}

template<typename T>
void popQueue(templatePriorityQueue<T>* Que){
	cout << " [+] Integer "<< Que->top() << " will be poped from the Priority Queue. " << endl;
	Que->pop();
}

int main(int argc, char* argv[]){
	templatePriorityQueue<int> priQueue;
	int customNumber = 0;

	if(priQueue.empty()){
		cout << " [!] Priority Queue is empty - initalized " << endl;
	}
	
	int test_array[] = {23, 598, 302};
	int test_count = sizeof(test_array) / sizeof(int);
	for (int i=0; i<test_count; i++) {
		pushQueue(&priQueue, test_array[i]);
	}

	if(argc > 1){
		customNumber = atoi(argv[1]);
		if( customNumber > -500 && customNumber < 2000 ){
			pushQueue(&priQueue,customNumber);
		}
		else{
			pushQueue(&priQueue,-1);
		}
	}
	else{
		pushQueue(&priQueue,-1);
	}

	if(priQueue.empty()){
		cout << " [-] Priority Queue is empty. - Push method did not work! " << endl;
		return -1;
	}
	else{
		cout << " [+] Priority Queue has data. - Queue Size : " << priQueue.size() <<endl;
	}

	test_count = 2;
	for (int i=0; i<test_count; i++) {
		popQueue(&priQueue);
	}

	cout << " [+] Now, Top element of Priority Queue is " << priQueue.top() << endl;
	
	return 0;
}
