#include<bits/stdc++.h>

using namespace std;

int n;
int ship[100010];
int m;
int cont[200010];
vector<int> allo[100010];
int last = -1;

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
        int mms = 9999999;
		for(int j=n-1;j>=0;j--){
			if(cont[i] <= ship[j] && mms >= allo[j].size()){
			    last = j;
			    mms = allo[j].size();
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