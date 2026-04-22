def solve():
    import sys
    input_data = sys.stdin.read().strip().split()
    
    n = int(input_data[0])
    tower = []
    sum_val = 0
    
    idx = 1
    for _ in range(n):
        now = int(input_data[idx])
        idx += 1
        
        # 스택의 top이 현재 값보다 작거나 같으면 pop하면서 차이를 sum에 더해줌
        while tower and now >= tower[-1]:
            sum_val += now - tower[-1]
            tower.pop()
        
        tower.append(now)
    
    bef = -1
    # 남은 스택에 대해 이전 값과의 차이를 sum에 계속 더해줌
    while tower:
        top_val = tower.pop()
        if bef == -1:
            bef = top_val
        else:
            sum_val += abs(top_val - bef)
            bef = top_val
    
    print(sum_val)

if __name__ == "__main__":
    solve()
