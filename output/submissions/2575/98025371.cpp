#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll m;
ll splited[1100000];
ll divied[1100000];

ll split(int m) {
	if(splited[m]) {
		return splited[m];
	}
	if(m <= 3){
	    return splited[m] = 1;
	}
	if(m%2) {
		return splited[m] = split(m/2 +1) + split(m/2);
	} else {
        return splited[m] = split(m/2) + split(m/2);
	}
}

ll divd(int m) {
	if(divied[m]) {
		return divied[m];
	}
	if(m <= 4){
	    return divied[m] = 1;
	}
	int now = -1;
	for(int i=2;i*i<=m;i++){
	    if(m % i == 0){
	        now = i;
	    }
	}
	if(now == -1){
	    return divied[m] = 1;
	}else{
	    return divied[m] = divd(now) + divd(m/now);
	}
}

int main() {
	cin >> m;
	cout << split(m) << ' ';
	cout << divd(m);
}