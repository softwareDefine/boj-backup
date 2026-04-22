#include <bits/stdc++.h>

using namespace std;

prioriy_queue<int> under, over;

int t;

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n/2 + 1;
        for(int i = 1; i <= n; i++){
            int element;
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
    }
}