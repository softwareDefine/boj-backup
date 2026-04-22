#include <iostream>
#include <string>

using namespace std;

int n, m;
int cnt;
string a[210];
void change(int n,int m){
    for(int i = n;i>=0;i--){
	    for(int j=m;j>=0;j--){
	       if(a[i][j]=='1'){
	           a[i][j]='0';
	       }else if(a[i][j]=='0'){
	           a[i][j]='1';
	       }
	    }
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = n-1;i>=0;i--){
	    for(int j=m-1;j>=0;j--){
	       if(a[i][j]=='1'){
	           cnt++;
               change(i,j);
	       }
	    }
	}
	cout << cnt;
}