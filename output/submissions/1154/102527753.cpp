#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

int mp[2000][2000];

set<int> A;
set<int> B;

vector<int> tmp;

int Group;
int visited[2000];

void go(int now, int nowGroup){
    visited[now] = 1;
    for(int next = 1; next <= n; next++){
        if( now == next ){ continue; }
        if(!visited[next] && !mp[now][next]){
            if(nowGroup == 0){
                B.insert(next);
            }else{
                A.insert(next);
            }
        }
    }
    for(int next = 1; next <= n; next++){
        if( now == next ){ continue; }
        if(!visited[next] && !mp[now][next]){
            go(next, (nowGroup+1)%2);
        }
    }
}

int main() {
	cin >> n;
	while(1) {
		int u, v;
		cin >> u >> v;
		if(u == v && v == -1) { break; }
		mp[u][v] = mp[v][u] = 1;
	}
	if( n == 1 ){ cout << -1 << '\n'; return 0; }
	A.insert(1);
	visited[1] = 1;
	for(int j = 2; j <= n; j++){
	    if(!mp[1][j]){
	        B.insert(j);
	        Group = 1;
	    }
	}
	for(auto element : B){
	    if(!visited[element]){
	        go(element, Group);
	    }
	}
	for(int i = 2; i <= n; i++) {
		if(!visited[i]){
		    visited[i] = 1;
		    int used = 0;
		    for(auto element : A){
		        if(!mp[i][element]){
		           B.insert(i);
		           used = 1;
		        }
		    }
		    for(auto element : B){
		        if(!mp[i][element]){
		           if(used){
		               cout << -1 << '\n';
		               return 0;
		           }
		           A.insert(i);
		           used = 1;
		        }
		    }
		    if(!used){
		        A.insert(i);
		    }
		}
	}
	cout << 1 << '\n';
	for(auto element : A) {
		cout << element << ' ';
		if(B.empty() && element == 1){
		    cout << "-1\n";
		}
	}
	cout << "-1\n";
	if(!B.empty()){
    	for(auto element : B) {
    		cout << element << ' ';
    	}
    	cout << "-1\n";
	}
	return 0;
}