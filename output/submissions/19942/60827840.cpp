#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <deque>
#include <stack>

using namespace std;

int N;
typedef struct diet{
	int p;
	int f;
	int s;
	int v;
	int c;
}diet;
diet Want;
diet Food[16];
int check[16];
vector<int> Select_number;
int mini_cost = 987654321;
vector<int> mini_number;

bool up_want(diet A, diet B){
	if(A.p >= B.p && A.f >= B.f && A.s >= B.s && A.v >= B.v) return true;
	else return false;
}

bool cmp(vector<int> A, vector<int> B){
	for(int i = 0; i < min(A.size(), B.size()); i++){
		if(A[i] > B[i]) return false;
		else if(A[i] < B[i]) return true;
	}
	return true;
}

void Select_Food(int start, int cnt, int now){
	if(cnt == now){
		diet now_select = {0,0,0,0,0};
		for(int i = 0; i < Select_number.size(); i++){
			int x = Select_number[i];
			now_select.p += Food[x].p;
			now_select.f += Food[x].f;
			now_select.s += Food[x].s;
			now_select.v += Food[x].v;
			now_select.c += Food[x].c;
		}
		if(up_want(now_select, Want)){
			if(mini_cost > now_select.c){
				mini_cost = now_select.c;				
                mini_number.clear();
				mini_number = Select_number;
			}	
			else if(mini_cost == now_select.c){
				if(!cmp(mini_number, Select_number)){
					mini_number.clear();
					mini_number = Select_number;
				}
			}
		}
	}
	else{
		for(int i = start; i <= N; i++){
			if(check[i] == 0){
				check[i] = 1;
				Select_number.push_back(i);
				Select_Food(i,cnt,now+1);
				Select_number.pop_back();
				check[i] = 0;
			}
		}
	}
}

void solve() {
	for(int i = 1; i <= N; i++){
		Select_Food(1,i,0);
	}
	if(mini_cost == 987654321) cout << "-1";
	else{
		cout << mini_cost << "\n";
		for(int i = 0; i < mini_number.size(); i++){
			cout << mini_number[i] << " ";
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> Want.p >> Want.f >> Want.s >> Want.v;
	for(int i = 1; i <= N; i++){
		cin >> Food[i].p >> Food[i].f >> Food[i].s >> Food[i].v >> Food[i].c;
	}
	solve();
	return 0;
}