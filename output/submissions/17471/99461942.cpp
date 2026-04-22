#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 999999999;

int people[20];
vector<int> edge[20];
int district[20];
int parent[20];
vector<int> st;

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}

void go(int now) {
    if(now == n+1){
        iota(parent,parent+20,0);
        st.clear();
        int redSum = 0; int blueSum = 0;
        for(int i=1;i<=n;i++){
            if(district[i]){
                redSum += people[i];
                for(auto element : edge[i]){
                    if(district[element] == district[i]){
                        parent[find(i)] = find(element);
                    }
                }
            }else{
                blueSum += people[i];
                for(auto element : edge[i]){
                    if(district[element] == district[i]){
                        parent[find(i)] = find(element);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            st.push_back(find(i));
        }
        sort(st.begin(),st.end());
        st.erase(unique(st.begin(),st.end()),st.end());
        if(st.size() == 2){
            ans = min(ans,abs(redSum-blueSum));
        }
        return;
    }
	district[now] = 0;
	go(now+1);
	district[now] = 1;
	go(now+1);
}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> people[i];
	}
	for(int u = 1; u <= n; u++) {
		int m;
		cin >> m;
		while(m--) {
			int v;
			cin >> v;
			edge[u].push_back(v);
		}
	}
	go(1);
	if(ans == 999999999){ cout << -1; return 0; }
	cout << ans;
}