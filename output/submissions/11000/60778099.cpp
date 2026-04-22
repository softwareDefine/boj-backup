#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> vc;
int n;
priority_queue<int> pq;

int cmp(pair<int,int> a,pair<int,int> b){
	return a.first < b.first;	
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >>b;
		vc.push_back({a,b});	
	}
	sort(vc.begin(),vc.end(),cmp);
	for(int i=0;i<n;i++){
		if(pq.empty()){
			pq.push(-vc[i].second);
			continue;
		}
		if(-pq.top() <= vc[i].first){
			pq.pop();
			pq.push(-vc[i].second);
		}else{
			pq.push(-vc[i].second);
		}
	}
	cout << pq.size();
}