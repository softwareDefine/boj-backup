def solve():
    import sys
    data = sys.stdin.read().strip().split()
    n = int(data[0])
    tower = []
    sum_val = 0
    
    idx = 1
    for _ in range(n):
        now = int(data[idx])
        idx += 1
        
        while tower and now >= tower[-1]:
            sum_val += now - tower[-1]
            tower.pop()
        
        tower.append(now)
    
    bef = -1
    while tower:
        top_val = tower.pop()
        if bef == -1:
            bef = top_val
        else:
            sum_val += (top_val - bef)
            bef = top_val
    
    print(sum_val)

if __name__ == "__main__":
    solve()
