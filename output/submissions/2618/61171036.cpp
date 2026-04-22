#include <iostream>

#define x first

#define y second

using namespace std;

using point = pair<int,int>;

point acc[1010];

int dp[1010][1010];

int n,q;

inline int dist(point bef,point aft){

    return abs(aft.x-bef.x) + abs(aft.y - bef.y);

}

int main(){

	cin >> n >> q;	for(int i=1;i<=n;i++){

		cin >> acc[i].x >> acc[i].y;

	}

dp[0][1] = dist({0,0},acc[1]);

dp[1][0] = dist({n,n},acc[1]);

	for(int i=2;i<=n;i++){

		for(int j=0;j<i-1;j++){

			dp[i][j] = dp[i-1][j] + dist(acc[i-1],acc[i]);

dp[i][i-1] = dp[j][i-1] + dist(acc[j],acc[i]);

dp[j][i] = dp[j][i-1] + dist(acc[i-1],acc[i]);

dp[i-1][i] = dp[i-1][j]+dist(acc[j],acc[i]);

		}

	}

for(int i)

}