/* 9012 괄호*/
/*
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 
그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 
예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 
*/

//문제 이해하는데 시간이 오래걸렸음

//스택으로 ( 입력 push  ) 입력 pop
//스택이 비어있으면 YES 비어있지 않으면 NO

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

int empty() { //스택이 비어있는지 확인
	if (top < 0) { //top이 음수인 경우
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

//와 나 일단 오류수정 못해