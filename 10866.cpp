/*10866
����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

*/


#define CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//�� ���� ���ϱⰡ ���� ��ƴ�
//
const int mx = 1000005;
int deque[2 * mx + 1];

//���� ó���� ���� ����Ű�°� ���� �־�� ��.
int first = mx;
int last = mx;

int empty() { //���� ����ִٸ� 1, �ƴϸ� 0 ���
	if (first==last)
		return 1;
	else return 0;
}

void push_front(int x) {//���� x�� ���� �տ� ����
	deque[--first] = x;
}
void push_back(int x) {//���� x�� ���� �ڿ� ����

	deque[++last] = x;

}

void pop_front() { //���� �տ� �ִ� ���� ���� ���,�ƹ��͵� ������ -1
	if (empty()==1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[first] << endl;
		deque[first] = NULL;
		first++;
	}
}

void pop_back() {//���� �ڿ� �ִ� ���� ���� ���, �ƹ��͵� ������ -1
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
//void size() { //�� ũ�� ���
//	if (empty()==1) {
//		cout << "0" << endl;
//	}
//	else {
//		cout << last - first + 1 << endl;
//	}
//
//}

void front() {//�Ǿ� ���� ��� ���ٸ� -1 (��ǻ� print_front)
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[first] << endl;
	}
}

void back() {//�ǵ� ���� ��� ���ٸ� -1 (��ǻ� print_back)
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		cout << deque[last] << endl;
	}
}

void main() {
	int n; //��� ���� ����
	cin >> n;

	for (int i = 0; i < n; i++) {//��ɰ�����ŭ�ݺ�
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