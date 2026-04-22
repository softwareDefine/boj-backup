n, q = map(int, input().split())
a = list(map(int, input().split()))

d = {}
g = {}

for i in range(1, n):
    diff = a[i] - a[i - 1]
    ratio = a[i] / a[i - 1]
    d[diff] = d.get(diff, 0) + 1
    g[ratio] = g.get(ratio, 0) + 1

for _ in range(q):
    x, v = map(int, input().split())
    
    if x > 1:
        diff = a[x] - a[x - 1]
        ratio = a[x] / a[x - 1]
        d[diff] -= 1
        g[ratio] -= 1
        if d[diff] == 0:
            del d[diff]
        if g[ratio] == 0:
            del g[ratio]
    
    if x < n:
        diff = a[x + 1] - a[x]
        ratio = a[x + 1] / a[x]
        d[diff] -= 1
        g[ratio] -= 1
        if d[diff] == 0:
            del d[diff]
        if g[ratio] == 0:
            del g[ratio]
    
    a[x] = v
    
    if x > 1:
        diff = a[x] - a[x - 1]
        ratio = a[x] / a[x - 1]
        d[diff] = d.get(diff, 0) + 1
        g[ratio] = g.get(ratio, 0) + 1
    
    if x < n:
        diff = a[x + 1] - a[x]
        ratio = a[x + 1] / a[x]
        d[diff] = d.get(diff, 0) + 1
        g[ratio] = g.get(ratio, 0) + 1
    
    if len(d) == 1 and next(iter(d.keys())) > 0:
        print("+")
    elif len(g) == 1 and next(iter(g.keys())) > 0 and next(iter(g.keys())) == int(next(iter(g.keys()))):
        print("*")
    else:
        print("?")