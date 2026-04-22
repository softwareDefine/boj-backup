#include <iostream>

#include <vector>

using ll = int;

using namespace std;

int n,q;

vector<pair<int,ll>> vc[300010];

int dist[300010];

int up[300010][22];

int distup[300010][22];

int go[300010];

int tree[1300000];

int parent[300010];

bool visited[300010];

int depth[300010];

int base;

int nnxt,cost;

void dfs(int now){

 visited[now] = 1;

	for(auto &i : vc[now]){		nnxt = i.first;cost = i.second;

		if(!visited[nnxt]){

			depth[nnxt] = depth[now]+1;

			visited[nnxt] = 1;

			parent[nnxt] = now;

			dist[nnxt] = cost;

			dfs(nnxt);

		}

	}	

}

int lca(int u,int v){

	if(u == v){return u;}

	if(depth[u] < depth[v]){

		swap(u,v);	

	}

	for(int i=base;i>=0;i--){

		if(up[u][i] && depth[up[u][i]] >= depth[v]){

			u = up[u][i];

		}	

	}

	if(u==v){return u;}

	for(int i=base;i>=0;i--){

		if(up[u][i] && up[v][i] && up[u][i]!=up[v][i]){

			u = up[u][i];

			v = up[v][i];	

		}

	}

	u = parent[u];

	return u;

}

struct seg{

	ll init(int start,int end, ll node){

		if(start ==end){

			return tree[node] = go[start]; 

		}

		int mid = (start+end)/2;

		return tree[node] = max(init(start,mid,node*2),init(mid+1,end,node*2+1));	

	}

	ll query(int start,int end,int left,int right,ll node){

		if( right < start || end < left){

			return 0;

		}

		if(left<= start && end <= right){

			return tree[node];

		}

		int mid = (start+end)/2;

		return max(query(start,mid,left,right,node*2),query(mid+1,end,left,right,node*2+1));

	}

};

seg s1;

int main(){

ios_base::sync_with_stdio(0);

    cin.tie(nullptr); cout.tie(nullptr);

		cin >> n >> q;

if(n==1){

for(int i=0;i<q;i++) {

 int u,v;

cin >> u >>v;

cout << 0 << '\n';

}

}else{

		for(int i=0;i<n-1;i++){

int u,v,c;

			cin >> u >> v >> c;

			vc[u].push_back({v,c});

			vc[v].push_back({u,c});

		}

		visited[1] =1;

		dfs(1);

		for(int i=1;i<=n;i++){

			up[i][0] = parent[i];

			distup[i][0] = dist[i];

		}

		for(base=0;(1<<base)<=n;base++);

		for(int j=1;(1<<j)<=n;j++){

			for(int i=1;i<=n;i++){

				if(up[i][j-1]){

					up[i][j] = up[up[i][j-1]][j-1];

					distup[i][j] = distup[i][j-1];

					if(up[i][j]){

						distup[i][j] = max(distup[i][j],distup[up[i][j-1]][j-1]);

					}

				}	

			}

		}

int comon =0,chk=0,u=0,v=0;

		for(int i=1;i<n;i++){

			u = i,v = i+1;

comon = lca(u,v);

 

chk = 0;

			for(int j=base;j>=0;j--){

				if(up[u][j] && depth[up[u][j]]>=depth[comon]){

					chk = max(chk,distup[u][j]);

					u= up[u][j];

			}

                }

			for(int j=base;j>=0;j--){

				if(up[v][j] && depth[up[v][j]]>=depth[comon]){

					chk = max(chk,distup[v][j]);

					v = up[v][j];

			}

                }

			go[i] = chk;

                }

		s1.init(1,n-1,1);

		for(int i=0;i<q;i++){

			int st,ed;

			cin >> st >> ed;

			cout << s1.query(1,n-1,st,ed-1,1) << '\n';

		}

}

}