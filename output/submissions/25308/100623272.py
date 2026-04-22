import sys
import math

lint = int  # 그냥 의미상만 맞춰둔 거

used = [0] * 20
arr = [0] * 20
vc = []
cnt = 0


def ccw(a, b, c):
    # a, b, c 는 (x, y) 튜플
    return ((b[0] - a[0]) * (c[1] - a[1]) -
            (c[0] - a[0]) * (b[1] - a[1])) >= 0


def go(now):
    global cnt

    if now == 8:
        vc.append(arr[0])
        vc.append(arr[1])
        for i in range(8):
            if ccw(
                (0, arr[vc[i]]),
                (arr[vc[i + 1]] / math.sqrt(2.0),
                 arr[vc[i + 1]] / math.sqrt(2.0)),
                (arr[vc[i + 2]], 0)
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


def main():
    data = list(map(int, sys.stdin.read().split()))
    for i in range(min(8, len(data))):
        arr[i] = data[i]
    go(0)
    print(cnt)


if __name__ == "__main__":
    main()
