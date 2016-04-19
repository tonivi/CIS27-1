#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Queue {
	int queueSize;
	int front;
	int rear;
	int currentSize;
	int* intArray;
};

typedef struct Queue Queue;

void enqueue(int, Queue*);
void dequeue(Queue* old);
int isEmpty(Queue* old);
int isFull(Queue* old);
void empty(Queue* old);
void print(Queue*);
void menu01();

int main() {
	menu01();


	return 0;

}

void enqueue(int val, Queue* q) {
	if (isFull(q)) {
		printf("\nThis queue is full!\n");
	} else {
		if (q->rear == (q->queueSize - 1)) {
			q->rear = 0;
		} else {
			q->rear++;
		}
		q->currentSize++;
		q->intArray[q->rear] = val;
	}

	return;
}

void dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("\nThis is an empty queue!\n");
	} else {
		q->front = (q->front + 1) % q->queueSize;
		q->currentSize--;
	}

	return;

}

int isEmpty(Queue* q) {
	if (q->currentSize)
		return 0;
	else
		return 1;
}

int isFull(Queue* q) {
	if (q->currentSize == q->queueSize)
		return 1;
	else
		return 0;
}

void empty(Queue* q) {
	q->front = q->queueSize - 1;
	q->rear = q->queueSize - 1;
	q->currentSize = 0;

	return;
}

void print(Queue* q) {
	int i;

	for (i = 0; i < q->currentSize; i++) {
		printf("[%d]", q->intArray[i]);
	}

	return;
}

void menu01() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	int option;
	int qSize;
	int val;
	int i;

	do {
		printf(
			"**********************************\n"
			"*         MENU – Radix Sort      *\n"
			"* 1. Creating / Updating series  *\n"
			"* 2. Calling sortRadixYourName() *\n"
			"* 3. Displaying series           *\n"
			"* 4. Quit                        *\n"
			"**********************************\n"
			"Select the option (1 through 4): ");
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			printf("Enter the size: ");
			scanf_s("%d", &qSize);			
			q->queueSize = qSize;
			q->intArray = (int *)malloc(sizeof(int) * q->queueSize);
			empty(q);

			for (i = 0; i < q->queueSize; i++) {
				printf("Enter the value: ");
				scanf_s("%d", &val);
				enqueue(val, q);
			}

			print(q);
			break;
		case 2:
			printf("Calling sortRadix");
		case 3:
			print(q);
			break;
		}
	} while (option != 4);
}