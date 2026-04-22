import sys

def main():
    input = sys.stdin.readline

    n, k = map(int, input().split())
    current = list(map(int, input().split()))  # current[0..3]

    arr = [[] for _ in range(4)]
    point = [0] * 4
    ans = []

    for _ in range(n):
        choice, dx = input().split()
        dx = int(dx)
        arr[ord(choice) - ord('A')].append(dx)

    # sort descending
    for i in range(4):
        arr[i].sort(reverse=True)

    for _ in range(k):
        nxt = [0] * 4

        for chose in range(4):
            adding = arr[chose][point[chose]] if point[chose] < len(arr[chose]) else 0

            if chose == 0:
                nxt[chose] = adding * current[1] * current[2] * current[3]
            elif chose == 1:
                nxt[chose] = adding * current[0] * current[2] * current[3]
            elif chose == 2:
                nxt[chose] = adding * current[0] * current[1] * current[3]
            else:  # chose == 3
                nxt[chose] = adding * current[0] * current[1] * current[2]

        mmx = 0
        mmxidx = 0
        for i in range(4):
            if mmx < nxt[i]:
                mmx = nxt[i]
                mmxidx = i

        # (주의) C++ 코드처럼 arr[mmxidx][point[mmxidx]]를 그대로 접근함 (k가 유효하다는 가정)
        chosen_val = arr[mmxidx][point[mmxidx]]
        ans.append((chr(mmxidx + ord('A')), chosen_val))

        current[mmxidx] += chosen_val
        point[mmxidx] += 1

    out = []
    for a, b in ans:
        out.append(f"{a} {b}")
    print("\n".join(out))


if __name__ == "__main__":
    main()
