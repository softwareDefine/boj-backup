#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;
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
            if(task < 0) task = -task;
            pq.push(-task);
            continue;
        }
        if(pq.empty()){
            cout << 0 << '\n';
        }else{
            int a = -pq.top();
            cout << -pq.top() << '\n';
            pq.pop();
        }
    }
    
}