import sys

def build_pi(p: str):
    m = len(p)
    pi = [0] * m
    j = 0
    for i in range(1, m):
        while j > 0 and p[i] != p[j]:
            j = pi[j - 1]
        if p[i] == p[j]:
            j += 1
            pi[i] = j
        else:
            pi[i] = 0
    return pi

def kmp_count(p: str, s: str, pi):
    if not p:
        return 0
    m = len(p)
    j = 0
    cnt = 0
    for ch in s:
        while j > 0 and ch != p[j]:
            j = pi[j - 1]
        if ch == p[j]:
            if j == m - 1:
                cnt += 1
                j = pi[j]
            else:
                j += 1
    return cnt

def main():
    data = sys.stdin.read().split()
    it = iter(data)

    case_no = 0
    out_lines = []

    for n_token, pattern in zip(it, it):
        n = int(n_token)
        pi = build_pi(pattern)
        L = len(pattern)
        keep = max(L - 1, 0)

        # fibbo[i] = (front, middle, end)
        fibbo_front = [""] * (n + 2)
        fibbo_mid   = [""] * (n + 2)
        fibbo_end   = [""] * (n + 2)
        dp = [0] * (n + 2)

        fibbo_front[0] = "0"
        fibbo_end[0]   = "0"
        fibbo_mid[0]   = ""
        dp[0] = kmp_count(pattern, "0", pi)

        fibbo_front[1] = "1"
        fibbo_end[1]   = "1"
        fibbo_mid[1]   = ""
        dp[1] = kmp_count(pattern, "1", pi)

        for i in range(2, n + 1):
            # middle = tail(end[i-1], L-1) + head(front[i-2], L-1)
            tail = fibbo_end[i - 1][-keep:] if keep > 0 else ""
            head = fibbo_front[i - 2][:keep] if keep > 0 else ""
            fibbo_mid[i] = tail + head

            # front = head(front[i-1] + front[i-2], L-1)
            joined_front = fibbo_front[i - 1] + fibbo_front[i - 2]
            fibbo_front[i] = joined_front[:keep] if keep > 0 else ""

            # end = tail(end[i-1] + end[i-2], L-1)
            joined_end = fibbo_end[i - 1] + fibbo_end[i - 2]
            fibbo_end[i] = joined_end[-keep:] if keep > 0 else ""

            dp[i] = dp[i - 1] + dp[i - 2] + kmp_count(pattern, fibbo_mid[i], pi)

        case_no += 1
        out_lines.append(f"Case {case_no}: {dp[n]}")

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()
