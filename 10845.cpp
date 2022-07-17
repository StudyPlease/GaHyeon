/* 10846 ť*/
/*
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/


//ť ���Լ��� front rear (start rear) 
//front : �����Ǵ� ���κ�
//rear : ���ԵǴ� ���κ�

#include <iostream>
#include <string>

using namespace std;

#define QUEUE_SIZE 10000 //ť ũ��

int queue[QUEUE_SIZE];
int start=0;
int rear=0;

int empty() { //ť�� ����ִ� ��� : start rear �� �������
	if (start==rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int x) { //���� x�� ť�� ����
	queue[rear] = x; 
	rear++;
}

void pop() { //���� �տ� �ִ� ������ ����
	if (empty() == 1) {//ť�� ������� ���� Ȯ��
		cout << "-1" << endl;
	}
	else {	
		start++;
		cout << queue[start - 1] << endl;
		queue[start - 1] = NULL;
	}
}

//void size() {
//
//
//}


int front() {
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		return queue[start];
	}
}
int back() {
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		return queue[rear-1];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (order == "pop") {
			pop();
		}
		else if (order == "size") {
			cout << rear - start << endl;
		}
		else if (order == "empty") {
			cout << empty() << endl;
		}
		else if (order == "front") {
			cout << front() << endl;
		}
		else if (order == "back") {
			cout << back() << endl;
		}
	}
	return 0;
}