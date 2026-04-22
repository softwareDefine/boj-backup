#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

stack<char> frt;
stack<char> bck;

string letter;
int cur;
int m;

int main(){
    fastio;
    cin >> letter;
    cur = letter.size();
    for(int i=0;i<letter.length();i++){
        frt.push(letter[i]);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        char task;
        cin >> task;
        if(task == 'P'){
            char wletter;
            cin >> wletter;
            frt.push(wletter);
            cur++;
        }else if(task == 'L'){
            if(cur != 0){
                bck.push(frt.top());
                cur--;
                frt.pop();
            }
        }else if(task == 'D'){
            if(!bck.empty()){
                frt.push(bck.top());
                bck.pop();
                cur++;
            }
        }else{
            if(!frt.empty()){
                frt.pop();
                cur--;
            }
        }
    }
    while(!frt.empty()){
        bck.push(frt.top());
        frt.pop();
    }
    while(!bck.empty()){
        cout << bck.top();
        bck.pop();
    }
}