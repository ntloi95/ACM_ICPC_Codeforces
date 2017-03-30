import sys
sys.stdin = open('input.txt') 
test = input()
test = int(test)
for i in range(1, test):
    n = int(input())
    k = int(input())
    res = int(input())
    for j in range(2, n):
        a = int(input())
        res = (res**a)%k
    print (res)
