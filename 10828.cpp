/*10828
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/
#define CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define STACK_SIZE 10000 //���� �ִ� ũ�� 10000

int stack[STACK_SIZE];
int top1 = -1;

void push(int x) { //���� X�� ���ÿ� �ִ� �Լ�	
		/*stack[top + 1] = x; //top+1�� �Է¹��� x ����
		top += 1; */
	stack[++top1] = x;

}

/*void size() { //���ÿ� ����ִ� ������ ���� ��� ����� ������ ���� = top+1
		cout << top1+1 << endl;
}
*/

int empty() { //������ ����ִ��� Ȯ��
	if (top1 < 0) { //top�� ������ ���
		return 1;
	}
	else {
		return 0;
	}

}
void pop() { //���ÿ��� ���� ���� �ִ� ������ ���� ���, ���� ���ÿ� ������ ���ٸ� -1 ���
	if (empty() == 1) { //���ú��������
		cout << "-1" << endl;
	}
	else {
		cout << stack[top1] << endl; //���� top�� ����� ���� ���
		stack[top1--] = NULL; //top �ʱ�ȭ
	}
}
int top() {//���������ִ� ���� ���
	int return_top = stack[top1];
	if (empty() == 1) {
		return -1;
	}
	else {
		return return_top;
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
			cout << top1 + 1 << endl;
		}
		else if (order == "empty") {
			cout << empty() << endl;
		}
		else if (order == "top") {
			cout << top() << endl;
		}
	}
	return 0;
}

