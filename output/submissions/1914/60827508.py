import math

def han(from_, to, ex, idx):
    if idx < 1:
        return
    han(from_, ex, to, idx-1)
    print(from_, to)
    han(ex, to, from_, idx-1)

n = int(input())
if n > 20:
    print((1<<n) - 1)
else:
    print((1<<n) - 1)
    han(1, 3, 2, n)