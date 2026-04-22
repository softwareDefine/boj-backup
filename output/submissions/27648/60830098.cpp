#include <iostream>

using ll = long long;
using namespace std;

ll n,m,k;

int main(){
	cin >> n >> m >> k;
	if(n+m > k+1){
		cout << "NO";
	}else{
        cout << "YES" << '\n';
		for(int i=1;i<=n;i++){
			for(int j=i;j<i+m;j++){
				cout << j << ' ';
			}
			cout << '\n';
		}
	}
}