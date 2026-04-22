#include <bits/stdc++.h>
using namespace std;

int n;
string s;

// len 번째까지 채워진 s 에서, 인접 길이 k 블록이 반복인지 검사
bool isRepeat(int len, int k) {
    for(int i = 0; i < k; i++)
        if(s[len - i] != s[len - k - i])
            return false;
    return true;
}

// len 위치에 채워나가기. 성공 시 true 반환 → 즉시 중단
bool dfs(int len) {
    if (len == n) {
        cout << s << "\n";
        return true;
    }
    for (char c = '1'; c <= '3'; c++) {
        s[len] = c;
        bool bad = false;
        for (int k = 1; k*2 <= len+1; k++) {
            if (isRepeat(len, k)) { bad = true; break; }
        }
        if (!bad && dfs(len+1))
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    s.resize(n);
    dfs(0);
    return 0;
}
