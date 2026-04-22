#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n,p;

vector<lint> vc;
priority_queue<lint> pq;
lint sum;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    for(int i=0;i<n;i++){
        lint a;
        cin >> a;
        vc.push_back(a);
    }
    for(int i=0;i<n;i++){
        if(pq.empty()){
            pq.push(-vc[i]);
            sum += vc[i];
        }else{
            lint last = 0;
            while(pq.size() && sum + pq.top() + vc[i] >= p && -pq.top() < vc[i]){
                    sum += pq.top();
                    last = pq.top();
                    pq.pop();
            }
            if(sum < p){
                pq.push(-vc[i]);
                sum += vc[i];
            }
            if(sum < p && last){
                pq.push(last);
                sum -= last;
            }
        }
        if(sum < p){
            cout << -1 << ' ';
        }else{
            cout << pq.size() << ' ';
        }
    }
}