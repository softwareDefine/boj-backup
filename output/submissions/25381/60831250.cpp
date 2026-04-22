#include <iostream>
#include <string.h>



using namespace std;
char a[500010];
int cnt[4];
int use[4];

int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    int l = strlen(a);
    for (int i = 0; i < l; i++) {
        cnt[a[i] - 'A']++;
    }
    for (int i = 0; i < l; i++) {
        if (a[i] == 'A' && cnt[0] > 0 && cnt[1] > 0) {
            use[1]++;
            ans++;
            cnt[1]--;
            cnt[a[i] - 'A']--;
        }
        else if (a[i] == 'B' && cnt[1] > 0 && cnt[2] > 0) {
            use[2]++;
            ans++;
            cnt[2]--;
            cnt[a[i] - 'A']--;
        }
        else {
            if (use[a[i] - 'A'] > 0) {
                use[a[i] - 'A']--;
            }
            else {
                cnt[a[i] - 'A']--;
            }
        }
    }
    cout << ans;
}