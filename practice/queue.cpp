#include <iostream>

using namespace std;

struct queue{
	int rear, front, size;
	int *array;
	queue(int s): size{s}, front{0} {
		array = new int(size);
		rear = size-1;
	}
};

void enqueue(queue *q, int num){
	if(!fullQueue(q)){
		if(q->rear == q->size - 1) q->rear = 0;
		q[q->rear] = 
	}
}

int dequeue(queue *q){

}

int main(){
	queue *q = new queue(20);


	return 1;
}