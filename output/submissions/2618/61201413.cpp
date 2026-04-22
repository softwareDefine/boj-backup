#include <iostream>

#define x first

#define y second

using int = long long;

using namespace std;

using point = pair<int,int>;

point acc[1010];

int dp[1010][1010];

int mmn = 9999999;

int mmnx;

int mmny;

int n,q;

inline int dist(point bef,point aft){

    return abs(aft.x-bef.x) + abs(aft.y - bef.y);

}

void dfs(int a, int b){

    if (a == q || b == q){

	return;}

    int go = max(a, b) + 1;

int da;

int db;

if(a==0){

da = abs(acc[go].x - acc[0].x) +

        abs(acc[go].y - acc[0].y);

}else{

da = abs(acc[go].x - acc[a].x) +

        abs(acc[go].y - acc[a].y);

}

if(b==0){

db = abs(acc[go].x - acc[1009].x) +

        abs(acc[go].y - acc[1009].y);

}else{

db = abs(acc[go].x - acc[b].x) +

        abs(acc[go].y - acc[b].y);

}

    int ret1 = dp[go][b] + da;

    int ret2 = dp[a][go] + db;

    if (ret1 > ret2)

    {

        cout << 2 << endl;

        dfs(a, go);

    }

    else

    {

        cout << 1 << endl;

        dfs(go, b);

    }

}

void main(){

	cin >> n >> q;

	for(int i=1;i<=n;i++){

		cin >> acc[i].x >> acc[i].y;

	}

for(int i=0;i<=n;i++){

for(int j=0;j<=n;j++){

dp[i][j] = 9999999;

}

}

acc[0] = {1,1};

acc[1009] = {n,n};

dp[1][0] = dist({1,1},acc[1]);

dp[0][1] = dist({n,n},acc[1]);

for(int i=2;i<=q;i++){

		for(int j=0;j<i-1;j++){

if(j==0){

dp[i][j] = min(dp[i][j],dp[i-1][j] + dist(acc[i-1],acc[i]));

dp[i][i-1] = min(dp[i][i-1],dp[j][i-1] + dist(acc[0],acc[i]));

dp[j][i] = min(dp[j][i],dp[j][i-1] + dist(acc[i-1],acc[i]));

dp[i-1][i] = min(dp[i-1][i],dp[i-1][j]+dist(acc[1009],acc[i]));

}else{

dp[i][j] = min(dp[i][j],dp[i-1][j] + dist(acc[i-1],acc[i]));

dp[i][i-1] = min(dp[i][i-1],dp[j][i-1] + dist(acc[j],acc[i]));

dp[j][i] = min(dp[j][i],dp[j][i-1] + dist(acc[i-1],acc[i]));

dp[i-1][i] = min(dp[i-1][i],dp[i-1][j]+dist(acc[j],acc[i]));

}

			

		}

	}

for(int i=q-1;i>=0;i--){

if(dp[q][i] < mmn){

mmn = dp[q][i];

mmnx = q;

mmny = i;

}

if(dp[i][q] < mmn){

mmn = dp[i][q];

mmnx = i;

mmny = q;

}

}

cout << mmn << '\n';

dfs(0,0);

}