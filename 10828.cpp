/*10828
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
#define CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define STACK_SIZE 10000 //스택 최대 크기 10000

int stack[STACK_SIZE];
int top1 = -1;

void push(int x) { //정수 X를 스택에 넣는 함수	
		/*stack[top + 1] = x; //top+1에 입력받은 x 저장
		top += 1; */
	stack[++top1] = x;

}

/*void size() { //스택에 들어있는 정수의 개수 출력 저장된 정수의 개수 = top+1
		cout << top1+1 << endl;
}
*/

int empty() { //스택이 비어있는지 확인
	if (top1 < 0) { //top이 음수인 경우
		return 1;
	}
	else {
		return 0;
	}

}
void pop() { //스택에서 가장 위에 있는 정수를 빼고 출력, 만약 스택에 정수가 없다면 -1 출력
	if (empty() == 1) { //스택비어있을때
		cout << "-1" << endl;
	}
	else {
		cout << stack[top1] << endl; //현재 top에 저장된 정수 출력
		stack[top1--] = NULL; //top 초기화
	}
}
int top() {//가장위에있는 정수 출력
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

