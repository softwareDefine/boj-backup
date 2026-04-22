#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint t;
stack<char> st;
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> a >> b;
		lint suma = 0,sumb = 0;
		lint weight;
		bool added = 0;
		for(int i=0; i<a.size(); i++) {
			if(a[i] == '(') {
			    if(st.empty()){
			        weight = 1;
			    }else{
			        weight *= 2;
			    }
				st.push('(');
				added = 0;
			}
			else if(a[i] == ')') {
				if(!st.empty() && st.top() == '(') {
					st.pop();
					if(!added){
					    suma += weight;
					    added = 1;
					}
					weight /= 2;
				} else {
					break;
				}
			}
		}
		while(!st.empty()){st.pop();}
        weight = 0;
        for(int i=0; i<b.size(); i++) {
			if(b[i] == '(') {
			    if(st.empty()){
			        weight = 1;
			    }else{
			        weight *= 2;
			    }
				st.push('(');
				added = 0;
			}
			else if(b[i] == ')') {
				if(!st.empty() && st.top() == '(') {
					st.pop();
					if(!added){
					    sumb += weight;
					    added = 1;
					}
					weight /= 2;
				} else {
					break;
				}
			}
		}while(!st.empty()){st.pop();}
		if(suma > sumb){
		    cout << ">" << '\n';
		}else if(suma < sumb){
		    cout << "<" << '\n';
		}else{
		    cout << "=" << '\n';
		}
	}
}