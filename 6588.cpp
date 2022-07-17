//6588


/*1742년, 독일의 아마추어 수학가 크리스티안 골드바흐는 레온하르트 오일러에게 다음과 같은 추측을 제안하는 편지를 보냈다.

4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
예를 들어 8은 3 + 5로 나타낼 수 있고, 3과 5는 모두 홀수인 소수이다. 또, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 이다.

이 추측은 아직도 해결되지 않은 문제이다.

백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오.*/

/*
각 테스트 케이스에 대해서, n = a + b 형태로 출력한다. 
이때, a와 b는 홀수 소수이다. 숫자와 연산자는 공백 하나로 구분되어져 있다. 
만약, n을 만들 수 있는 방법이 여러 가지라면, b-a가 가장 큰 것을 출력한다. 
또, 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우에는 "Goldbach's conjecture is wrong."을 출력한다.
*/

//소수 : 약수가 1과 자기 자신밖에 없는 수(단, 1보다 큰 자연수)
//2 3 5 7 . . . 문제에서는 홀수 소수를 원하는데 짝수는 2밖에 없음
//3부터 홀수이면서 소수
//그 중 두수의 차이가 가장 큰거 골라내기

//1588도 꼭 해라

#include <iostream>
#include <cmath>

using namespace std;

#define max 1000000

bool primearr[max];

//소수판별함수
void prime() {
	//에라토스체네스의 체
	primearr[0] = true; //0 1 은 소수아니니까
	primearr[1] = true;
	//2부터 시작 어떤 수의 배수인 수는 지우기
	for (int i = 2; i < sqrt(max); i++) { 
		if (primearr[i]) //이미 true로 바꾼건 빼고
			continue;
		for (int j = i + i; j < max; j += i) {//
			primearr[j] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	prime();
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		
		for (int i = 3; i < max; i += 2) { //홀수 소수 3부터 홀수만
			if (n - i <= 0) {
				cout << "Goldbach's conjecture is wrong." << endl;
				break;
			}
			else if (!primearr[i] && !(primearr[n - i])) { //둘다 f이면
				cout << n << "=" << i << "+" << n - i << endl;
				break;
			}
		}
	}
}
