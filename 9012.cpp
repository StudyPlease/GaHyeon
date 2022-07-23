/* 9012 ��ȣ*/
/*
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�. 
�� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���. 
�� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. ���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. 
�׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�. 
���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�. 

�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�. 
*/

//���� �����ϴµ� �ð��� �����ɷ���

//�������� ( �Է� push  ) �Է� pop
//������ ��������� YES ������� ������ NO

#include <iostream>
#include <string>
using namespace std;

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

int push(char x) {

	if (top >= STACK_SIZE - 1)
		return -1;
	stack[++top] = x;
	return x;
}

int pop() {
	if (top < 0) 
		return -1;
	stack[top--] = NULL;
	return stack[top--];
}

int empty() { //������ ����ִ��� Ȯ��
	if (top < 0) { //top�� ������ ���
		return 1;
	}
	else {
		return 0;
	}
}

bool vps(string str) {

	bool result = true;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(')
			push(str[i]);
		else if (!empty() && str[i] == ')')
			pop();
		else if (empty() && str[i] == ')') {
			result = false;
			break;
		}
	}
	if (empty() && result)return true;
	else return false;
}

int main() {
	char str[STACK_SIZE];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (vps(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	
}

//�� �� �ϴ� �������� ����