import sys

input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    a, b = map(int, input().split())
    last = (pow(a, b, 10) - 1) % 10 + 1
    out.append(str(last))

sys.stdout.write("\n".join(out))
