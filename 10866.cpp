/*10866
문제
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/


#define CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//덱 개수 정하기가 제일 어렵다
//
const int mx = 1000005;
int deque[2 * mx + 1];

//덱은 처음과 끝을 가리키는게 각각 있어야 함.
int first = mx;
int last = mx;

int empty() { //덱이 비어있다면 1, 아니면 0 출력
	if (first==last)
		return 1;
	else return 0;
}

void push_front(int x) {//정수 x를 덱의 앞에 저장
	deque[--first] = x;
}
void push_back(int x) {//정수 x를 덱의 뒤에 저장

	deque[++last] = x;

}

void pop_front() { //가장 앞에 있는 수를 빼고 출력,아무것도 없으면 -1
	if (empty()==1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[first] << endl;
		deque[first] = NULL;
		first++;
	}
}

void pop_back() {//가장 뒤에 있는 수를 빼고 출력, 아무것도 없으면 -1
	if (empty()==1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[last] << endl;
		deque[last] = NULL;
		last--;
	}
}
//
//void size() { //덱 크기 출력
//	if (empty()==1) {
//		cout << "0" << endl;
//	}
//	else {
//		cout << last - first + 1 << endl;
//	}
//
//}

void front() {//맨앞 정수 출력 없다면 -1 (사실상 print_front)
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[first] << endl;
	}
}

void back() {//맨뒤 정수 출력 없다면 -1 (사실상 print_back)
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[last] << endl;
	}
}

void main() {
	int n; //명령 개수 저장
	cin >> n;

	for (int i = 0; i < n; i++) {//명령개수만큼반복
		string order;
		cin >> order;

		if (order == "push_front") {
			int x;
			cin >> x;
			push_front(x);
		}
		else if (order == "push_back") {
			int x;
			cin >> x;
			push_back(x);
		}
		else if (order == "pop_front") {
			pop_front();
		}
		else if (order == "pop_back") {
			pop_back();
		}
		else if (order == "size") {
			if (empty() == 1) {
				cout << "0" << endl;
			}
			else {
				cout << last - first << endl;
			}
		}
		else if (order == "empty") {
			cout << empty() << endl;
		}
		else if (order == "front") {
			front();
		}
		else if (order == "back") {
			back();
		}
	}
}