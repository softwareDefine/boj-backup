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
	sort(cont,cont+m,[&](int a,int b){return a > b;});
	for(int i=0;i<m;i++){
		last = -1;
		for(int j=n;j>=0;j--){
			if(cont[i] <= ship[j]){
			    last = j;
				chk = 1;
				break;
			}
		}
		if(last == -1){ cout << -1; break;}else{ allo[last].push_back(1);}
	}
	if(last != -1){
	int mmx = 0;
	for(int j=0;j<n;j++){
		mmx = max(mmx,int(allo[j].size()));
	}
	cout << mmx;
	}
}