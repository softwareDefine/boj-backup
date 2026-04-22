#include <bits/stdc++.h>

using namespace std;

int n;
string mp[100];

int twoFriend[100];

int ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> mp[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){ continue; }
            if(mp[i][j] == 'Y'){
                twoFriend[i]++;
            }else{
                for(int k = 0; k < n; k++){
                    if(mp[i][k] == 'Y' && mp[k][j] == 'Y'){
                        twoFriend[i]++;
                        break;
                    }
                }
            }
        }
        ans = max(ans, twoFriend[i]);
    }
    cout << ans;
	return 0;
}