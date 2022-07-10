/*9093
문제
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 
단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 
단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

*/

//getline cin.ignore 사용해야지
//테스트 케이스의 개수 T 첫째줄
//큰 for문으로 문장개수(테스트케이스)만큼 반복
//작은 for문으로 단어개수(str)만큼 반복 (거꾸로 출력)


#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


int main() {

	int t; //테스트 케이스
	int strn = 0; //작은 for문에서 사용할거임
	string str;

	cin >> t; //테스트케이스입력받기
	cin.ignore();//버퍼 강제로 비우기 .버퍼 무시


	for (int i = 0; i < t; i++) { //테스트 케이스만큼 반복
		getline(cin, str);//문장입력하기

		for (int j = 0; j < str.size(); j++) { //str 크기만큼 반복
			if (str[j] == ' ') //공백이면
			{
				for (int h = j - 1; h >= strn; h--) { //단어 거꾸로 출력
					cout << str[h];
				}
				cout << " ";
				strn = j + 1;
				
			}

		}
		for (int k = str.size() - 1; k>=strn;k--) //마지막 단어
			cout << str[k];
		cout << "\n";
	}
	return 0;
}


