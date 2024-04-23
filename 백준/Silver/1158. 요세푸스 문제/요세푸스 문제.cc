#define _CRT_SECURE_NO_WARNINGS
#define MAX 5000
#include <stdio.h>

int queue[MAX];
int front, rear;
int n = 0, k = 0;

void push(int a) {
	queue[rear] = a;
	rear = (rear + 1) % n;
}

int pop() {
	front = (front + k - 1) % n;
	int ret = queue[front];
	for (int i = front; i < n; i++)
		queue[i] = queue[i + 1];
	n--;
	return ret;
}

int main() {
	int tmp = 0;
	scanf("%d", &n);
	tmp = n;
	for (int i = 1; i <= tmp; i++) {
		push(i);
	}
	scanf("%d", &k);
	printf("<");
	for (int i = 1; i <= tmp; i++) {
		if(!(n-1))
			printf("%d", pop());
		else
			printf("%d, ", pop());
	}
	printf(">");
}