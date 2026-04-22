import math

number = int(input())

def find(a):
    start = 0
    end = pow(10,100)
    while start != end:
        mid = (start + end + 1) // 2
        if pow(2, a) * (2 * mid - 1) + pow(2, a + 1) - 2 <= number:
            start = mid
        else:
            end = mid - 1
    return start

cnt, res, finder = 1, 0, 0
if number < 4:
    print(number)
else:
    while True:
        if cnt % 2 == 0:
            res += find(cnt)
        finder = find(cnt)
        cnt += 1
        if finder == 0:
            break
    res += number//2
    now = 2
    cnt = 0
    while now <= number:
        if now <= number and cnt % 2 == 0:
            res += 1
        cnt += 1
        now = now * 2 + 2
    print(res)