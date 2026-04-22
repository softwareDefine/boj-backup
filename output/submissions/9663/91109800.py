n = int(input())
vc = []  # 지금까지 놓은 퀸의 좌표 리스트 (튜플 형태)
cnt = 0   # 해의 개수를 저장할 변수

def go(now):
    global cnt
    for i in range(1, n+1):
        for j in range(1, n+1):
            safe = True
            for (x, y) in vc:
                # 현재 (i, j)에 놓을 수 없는 경우: 같은 행, 같은 열, 혹은 대각선에 있는 경우
                if abs(x - i) == abs(y - j) or x == i or y == j:
                    safe = False
                    break
            if safe:
                if now == n:
                    cnt += 1
                    return
                vc.append((i, j))
                go(now + 1)
                vc.pop()

go(1)
print(cnt)
