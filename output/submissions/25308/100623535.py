import sys
import math

input = sys.stdin.readline

arr = []
while len(arr) < 8:
    arr.extend(map(float, input().split()))
arr = arr[:8]

used = [0] * 8
vc = []
cnt = 0
rt2 = math.sqrt(2.0)


def ccw(a, b, c):
    # a, b, c : (x, y)
    return ((b[0] - a[0]) * (c[1] - a[1])
            - (c[0] - a[0]) * (b[1] - a[1])) >= 0


def go(now):
    global cnt

    if now == 8:
        # 첫 두 점을 뒤에 한 번 더 붙여서 v[i], v[i+1], v[i+2]를 i=0..7까지 보기 위함
        vc.append(vc[0])
        vc.append(vc[1])

        for i in range(8):
            if ccw(
                (0.0, arr[vc[i]]),
                (arr[vc[i + 1]] / rt2, arr[vc[i + 1]] / rt2),
                (arr[vc[i + 2]], 0.0),
            ):
                vc.pop()
                vc.pop()
                return

        vc.pop()
        vc.pop()
        cnt += 1
        return

    for i in range(8):
        if not used[i]:
            used[i] = 1
            vc.append(i)
            go(now + 1)
            vc.pop()
            used[i] = 0


go(0)
print(cnt)
