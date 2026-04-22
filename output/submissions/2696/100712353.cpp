#include <bits/stdc++.h>

using lint = long long;
using namespace std;

priority_queue<lint> under, over;

int t;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        lint n;
        while(under.size()){
            under.pop();
        }
        while(over.size()){
            over.pop();
        }
        cin >> n;
        cout << n/2 + 1 << '\n';
        for(int i = 1; i <= n; i++){
            lint element;
            cin >> element;
            if( i % 2 == 1){
                if( i == 1 ){
                    over.push(-element);
                }else{
                    if(-(over.top()) <= element){
                        over.push(-element);
                    }else if((under.empty() || under.top() <= element) && -(over.top()) >= element){
                        over.push(-element);
                    }else if(under.top() > element){
                        under.push(element);
                        over.push(-(under.top()));
                        under.pop();
                    }
                }
                cout << -over.top() << ' ';
            }else{
                if(-(over.top()) <= element){
                    over.push(-element);
                    under.push(-(over.top()));
                    over.pop();
                }else if((under.empty() || under.top() <= element) && -(over.top()) >= element){
                    under.push(element);
                }else if(under.top() > element){
                    under.push(element);
                }
            }
        }
        cout << '\n';
    }
}