#include<bits/stdc++.h>

using namespace std;

int n;
int ship[100010];
int m;
int cont[200010];
vector<int> allo[100010];
int chk = 0;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> ship[i];
	}
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> cont[i];	
	}
	sort(ship,ship+n);
	sort(cont,cont+m);
	for(int i=0;i<n;i++){
		chk = 0;
		for(int j=0;j<m;j++){
			if(cont[i] <= ship[j]){
				if(j+1 < m && allo[j].size() > allo[j+1].size() ){
					continue;
				}
				allo[j].push_back(cont[i]);
				chk = 1;
				break;
			}
		}
		if(!chk){ cout << -1;}
	}
	if(chk){
	int mmx = 0;
	for(int j=0;j<m;j++){
		mmx = max(mmx,int(allo[j].size()));
	}
	cout << mmx;
	}
}