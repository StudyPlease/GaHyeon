A, B, C=map(int,input().split()) #한번에 입력받는 방법 map 사용함

print((A+B)%C)
print(((A%C)+(B%C))%C)
print((A*B)%C)
print(((A%C)*(B%C))%C)
