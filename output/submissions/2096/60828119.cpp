#include <iostream>

using namespace std;

int n;
pair<long long,long long> dp[2][3];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
        long long a,b,c;
        cin >> a >> b >> c;
        if(i==0){
            dp[0][0] = {a , a };
	        dp[0][1] = { b,b};
	        dp[0][2] = { c,c};
            continue;
        }
        dp[i%2][0] = { min(dp[(i-1)%2][0].first,dp[(i - 1)%2][1].first) + a,max(dp[(i - 1)%2][0].second,dp[(i - 1)%2][1].second)+a };
		dp[i%2][1] = { min(min(dp[(i - 1)%2][0].first,dp[(i - 1)%2][1].first),dp[(i-1)%2][2].first)+b,max(max(dp[(i - 1)%2][0].second,dp[(i - 1)%2][1].second),dp[(i - 1)%2][2].second)+ b };
		dp[i%2][2] = { min(dp[(i - 1)%2][1].first,dp[(i - 1)%2][2].first)+ c,max(dp[(i - 1)%2][1].second,dp[(i - 1)%2][2].second)+ c};
        
	}
	
	for (int i = 1; i < n; i++) {
		
	}
	cout << max(max(dp[(n - 1)%2][0].second, dp[(n - 1)%2][1].second), dp[(n - 1)%2][2].second) << ' ';
	cout << min(min(dp[(n - 1)%2][0].first, dp[(n - 1)%2][1].first), dp[(n - 1)%2][2].first);
}