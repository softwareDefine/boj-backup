import sys
input = sys.stdin.buffer.readline
write = sys.stdout.write

def score(s: bytes) -> int:
    st = 0
    weight = 0
    added = False
    total = 0
    for ch in s:
        if ch == 40:  # '('
            if st == 0:
                weight = 1
            else:
                weight *= 2
            st += 1
            added = False
        elif ch == 41:  # ')'
            if st > 0:
                st -= 1
                if not added:
                    total += weight
                    added = True
                weight //= 2
            else:
                break
    return total

t = int(input())
for _ in range(t):
    a = input().rstrip(b'\r\n')
    b = input().rstrip(b'\r\n')

    suma = score(a)
    sumb = score(b)

    if suma > sumb:
        write('>\n')
    elif suma < sumb:
        write('<\n')
    else:
        write('=\n')
