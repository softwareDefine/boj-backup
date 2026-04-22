#define fastio cin.tie()->sync_with_stdio(0)
#include<bits/stdc++.h>

using namespace std;

int t;
int n;
bool chk;
string p,arr;
bool rev;
deque<int> dq;

int main(){
    fastio;
    cin >> t;
    for(int i=0;i<t;i++){
        rev = 0;
        chk = 0;
        cin >> p;
        cin >> n;
        char gwalo,gwalc,comma;
        cin >> gwalo;
        for(int i=0;i<n;i++){
            int num;
            cin >> num;
            dq.push_back(num);
            if(i!=n-1){
                cin >> comma;
            }
        }
        cin >> gwalc;
        for(int i=0;i<p.size();i++){
            if(p[i] == 'R') {rev = !rev; continue;}
            if(dq.empty()){
                cout << "error" << '\n';
                chk = 1;
                break;
            }
            if(rev){
                dq.pop_back();
            }else{
                dq.pop_front();
            }
        }
        if(!chk){
            cout << '[';
            while (!dq.empty())
            {
                if(rev){
                    cout << dq.back();
                    if(dq.size() !=1){
                        cout << ',';
                    }
                    dq.pop_back();
                }else{
                    cout << dq.front();
                    if(dq.size() !=1){
                        cout << ',';
                    }
                    dq.pop_front();
                }
            }
            cout << ']' << '\n';
        }
    }
}