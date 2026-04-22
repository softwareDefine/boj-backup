#include <iostream>
using ll = long long; using namespace std;

string str; ll dp[2510][2510]; bool visited[2510][2510];

ll go(int start,int end){ 
if(start == end){ return dp[start][end] = 1;}
 if(visited[start][end]){ return dp[start][end]; }
 visited[start][end] = 1;
 bool flag = 0;
for(int i=start;i<=(start+end)/2;i++){ if(str[i] != str[end-i+start]){ flag = 1; } } 
if(!flag) return dp[start][end] = 1;
 ll cnt = 9999999; 
for(int i = start;i<end;i++){ cnt = min(cnt,go(start,i)+go(i+1,end)); } 
return dp[start][end] = cnt; 
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(nullptr); cin >> str; cout << go(0,str.length()-1); }