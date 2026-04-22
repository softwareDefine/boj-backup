def main():
    import sys
    input = sys.stdin.readline
    n = int(input().strip())
    arr = list(map(int, input().split()))
    
    if n >= 2:
        thmmn = arr[0] + arr[3] + arr[4]
        thmmn = min(thmmn, arr[0] + arr[2] + arr[4])
        thmmn = min(thmmn, arr[0] + arr[1] + arr[2])
        thmmn = min(thmmn, arr[0] + arr[1] + arr[3])
        thmmn = min(thmmn, arr[1] + arr[2] + arr[5])
        thmmn = min(thmmn, arr[1] + arr[3] + arr[5])
        thmmn = min(thmmn, arr[2] + arr[4] + arr[5])
        thmmn = min(thmmn, arr[3] + arr[4] + arr[5])
       
        twmmn = 999999999999999
        for i in range(6):
            if i == 0 or i == 5:
                continue
            twmmn = min(twmmn, arr[0] + arr[i])
        for i in range(6):
            if i == 1 or i == 4:
                continue
            twmmn = min(twmmn, arr[1] + arr[i])
        for i in range(6):
            if i == 2 or i == 3:
                continue
            twmmn = min(twmmn, arr[2] + arr[i])
        arr.sort()
        onmmn = arr[0]
        
        result = (5 * (n - 2) ** 2 + 4 * (n - 2)) * onmmn + (8 * (n - 2) + 4) * twmmn + 4 * thmmn
        print(result)
    else:
        arr.sort()
        result = sum(arr[:5])
        print(result)
        
if __name__ == '__main__':
    main()
