/* 10846 큐*/
/*
문제
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/


//큐 후입선출 front rear (start rear) 
//front : 삭제되는 끝부분
//rear : 삽입되는 끝부분

#include <iostream>
#include <string>

using namespace std;

#define QUEUE_SIZE 10000 //큐 크기

int queue[QUEUE_SIZE];
int start=0;
int rear=0;

int empty() { //큐가 비어있는 경우 : start rear 가 같은경우
	if (start==rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int x) { //정수 x를 큐에 삽입
	queue[rear] = x; 
	rear++;
}

void pop() { //가장 앞에 있는 정수를 빼는
	if (empty() == 1) {//큐가 비었는지 먼저 확인
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