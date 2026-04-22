#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;
priority_queue<int> pq2;
int n;
int task;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){   
        cin >> task;
        if(task){
            if(task >0){
                pq.push(-task);
            }else{
                pq2.push(task);
            }
            continue;
        }
        if(pq.empty() && pq2.empty()){
            cout << 0 << '\n';
        }else{
            int a = pq.empty()?99999999:-pq.top();
            int b = pq2.empty()?99999999:pq2.top();
            if(abs(a) >= abs(b)){
                cout << b << '\n';
                pq2.pop();
            }else{
                cout << a << '\n';
                pq.pop();
            }
        }
    }
    
}