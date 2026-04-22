#include <bits/stdc++.h>

using namespace std;

int n;
int u,v,w,x,y;
int mp[100][100];
int onebon[100][100];
int visited[100][100];
int visited2[100][100];
int visited3[100][100];
int chkmp[100][100];

vector<pair<int,int>> ans;

void bfs(int si,int sj) {
	queue<pair<int,int>> qu;
	visited[si][sj] = 1;
	qu.push({si,sj});
	while(!qu.empty()) {
		int i = qu.front().first;
		int j = qu.front().second;
		qu.pop();
		if(i+1<=n && mp[i+1][j] == 1 && !visited[i+1][j]) {
			visited[i+1][j] = 1;
			qu.push({i+1,j});
		}
		if(i-1 >= 1 && mp[i-1][j] == 1 && !visited[i-1][j]) {
			visited[i-1][j] = 1;
			qu.push({i-1,j});
		}
		if(j+1<=n && mp[i][j+1] == 1 && !visited[i][j+1]) {
			visited[i][j+1] = 1;
			qu.push({i,j+1});
		}
		if(j-1>=1 && mp[i][j-1] == 1 && !visited[i][j-1]) {
			visited[i][j-1] = 1;
			qu.push({i,j-1});
		}
	}
}

pair<int,int> bfs2(int si,int sj) {
    int mmni = 9999999, mmnj = 9999999;
	queue<pair<int,int>> qu2;
	visited2[si][sj] = 1;
	qu2.push({si,sj});
	while(!qu2.empty()) {
		int i = qu2.front().first;
		int j = qu2.front().second;
		qu2.pop();
		mmni = min(mmni,i);
		mmnj = min(mmnj,j);
		if(i+1<=n && onebon[i+1][j] == 1 && !(visited2[i+1][j])) {
			visited2[i+1][j] = 1;
			qu2.push({i+1,j});
		}
		if(i-1 >= 1 && onebon[i-1][j] == 1 && !(visited2[i-1][j])) {
			visited2[i-1][j] = 1;
			qu2.push({i-1,j});
		}
		if(j+1<=n && onebon[i][j+1] == 1 && !(visited2[i][j+1])) {
			visited2[i][j+1] = 1;
			qu2.push({i,j+1});
		}
		if(j-1>=1 && onebon[i][j-1] == 1 && !(visited2[i][j-1])) {
			visited2[i][j-1] = 1;
			qu2.push({i,j-1});
		}
	}
	return {mmni,mmnj};
}

bool fitter(int i,int j) {
	for(int a=1; a<=n; a++) {
		for(int b=1; b<=n; b++) {
			chkmp[a][b] = mp[a][b];
			visited3[a][b] = 0;
		}
	}
	vector<int> vc;
	for(int a = 0; i+a <= n && mp[i+a][j+0] != 0; a++) {
		int cnt = 0;
		for(int b=0; j+b <= n && mp[i+a][j+b] != 0; b++) {
			cnt++;
		}
		vc.push_back(cnt);
	}
	if(vc.size() <= 1) {
		return 0;
	}
	int start = 0;
	for(int k=0; k<vc.size()-1; k++) {
		if(vc[0] == vc[k]) {
			start++;
		}
		if(vc[k] < vc[k+1]) {
			return 0;
		}
	}
	if(j+w+y > n+1 || i+start+x > n+1) {
		return 0;
	}
	for(int a=i+start;a<i+start+x;a++){
    	for(int b=j+w; b<j+w+y; b++) {
            if(chkmp[a][b]){
                return 0;
            }
            chkmp[a][b] = 1;
    	}
    }
    if(i+start+x+v > n+1 || j+u > n+1){
        return 0;
    }
    for(int a=i+start+x;a<i+start+x+v;a++){
    	for(int b=j; b<j+u; b++) {
            if(chkmp[a][b]){
                return 0;
            }
            chkmp[a][b] = 1;
    	}
    }
    for(int a=i;a<i+start+x+v;a++){
        for(int b=j;b<j+u;b++){
            if(!chkmp[a][b]){
                return 0;
            }
        }
    }
    return 1;
    queue<pair<int,int>> qu3;
    int chhk = 0;
    while(!qu3.empty()){qu3.pop();}
	visited3[i][j] = 1;
	qu3.push({i,j});
	while(!qu3.empty()) {
		int l = qu3.front().first;
		int m = qu3.front().second;
		qu3.pop();
		chhk++;
		if(l+1<=n && chkmp[l+1][m] == 1 && !(visited3[l+1][m])) {
			visited3[l+1][m] = 1;
			qu3.push({l+1,m});
		}
		if(l-1 >= 1 && chkmp[l-1][m] == 1 && !(visited3[l-1][m])) {
			visited3[l-1][m] = 1;
			qu3.push({l-1,m});
		}
		if(m+1<=n && chkmp[l][m+1] == 1 && !(visited3[l][m+1])) {
			visited3[l][m+1] = 1;
			qu3.push({l,m+1});
		}
		if(m-1>=1 && chkmp[l][m-1] == 1 && !(visited3[l][m-1])) {
			visited3[l][m-1] = 1;
			qu3.push({l,m-1});
		}
	}
	return (chhk == (start+x+v)*u);
}
int main() {
	cin >> n;
	cin >> u >> v >> w >> x >> y;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> mp[i][j];
			onebon[i][j] = mp[i][j];
		}
	}
	// l ( l k0)m% )
	for(int t=0;t<=3;t++){
    	for(int i=1; i<=n; i++) {
    		for(int j=1; j<=n; j++) {
    			if(!visited[i][j] && mp[i][j]) {
    				if(fitter(i,j)) {
    				    int ti = i;
    				    int tj = j;
    				    for(int k=0;k<t;k++){
    				        int tti=n-tj+1;
    				        int ttj = ti;
    				        ti = tti;
    				        tj = ttj;
    				    }
    				    ans.push_back(bfs2(ti,tj));
    				}
    				bfs(i,j);
    			}
    		}
    	}
    	for(int i=1;i<=n;i++){
    	    for(int j=1;j<=n;j++){
    	        chkmp[i][j] = mp[n-j+1][i];
    	    }
    	}
    	for(int i=1;i<=n;i++){
    	    for(int j=1;j<=n;j++){
    	        mp[i][j] = chkmp[i][j];
    	        visited[i][j] = 0;
    	        visited2[i][j] = 0;
    	    }
    	}
	}
	sort(ans.begin(), ans.end());
ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << '\n';
	for(auto element : ans){
	    cout << element.first << ' ' << element.second << '\n';
	}
}