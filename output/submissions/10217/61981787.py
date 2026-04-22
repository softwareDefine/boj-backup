import heapq

inf = 999999999

# 다음 향하는 위치, 비용, 시간
vc = [[] for _ in range(110)]
dp = [[inf] * 100010 for _ in range(110)]  # i번째 비용 j일 때 최소 시간
mmn = inf
t, n, m, k = 0, 0, 0, 0

def dijk(start, end):
    # 시간, 비용, 위치
    pq = []
    heapq.heappush(pq, (0, 0, start))
    dp[start][0] = 0

    while pq:
        time, cost, now = heapq.heappop(pq)
        if dp[now][cost] < time:
            continue
        
        for i in vc[now]:
            next_node = i[0]
            ncost = i[1][0]
            ntime = i[1][1]

            if cost + ncost > m:
                continue
            
            if dp[next_node][cost + ncost] > dp[now][cost] + ntime:
                dp[next_node][cost + ncost] = dp[now][cost] + ntime
                heapq.heappush(pq, (dp[now][cost] + ntime, cost + ncost, next_node))

def main():
    global mmn, t, n, m, k

    t = int(input())
    while t > 0:
        for i in range(110):
            vc[i].clear()
            for j in range(100010):
                dp[i][j] = inf

        n, m, k = map(int, input().split())
        for i in range(k):
            u, v, c, t = map(int, input().split())
            vc[u].append((v, (c, t)))

        dijk(1, n)
        mmn = inf
        for i in range(m + 1):
            mmn = min(dp[n][i], mmn)

        if mmn == inf:
            print("Poor KCM")
        else:
            print(mmn)
        
        t -= 1

if __name__ == "__main__":
    main()
