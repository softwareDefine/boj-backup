#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n,p;

vector<int> vc;
priority_queue<int> pq;
lint sum;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        vc.push_back(a);
    }
    for(int i=0;i<n;i++){
        if(sum < p){
            pq.push(-vc[i]);
            sum += vc[i];
        }else{
            //lint last = -1;
            while(sum + pq.top() + vc[i] >= p){
                sum += pq.top();
                //last = pq.top();
                pq.pop();
            }
            //pq.push(last);
            //sum -= last;
            pq.push(-vc[i]);
            sum += vc[i];
        }
        if(sum < p){
            cout << -1 << ' ';
        }else{
            cout << pq.size() << ' ';
        }
    }
}