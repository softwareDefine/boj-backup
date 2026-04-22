#include <bits/stdc++.h>

using namespace std;

int n;

int arr[100010];
int idx[100010];
int operation[100010];
bool flag; int cnt;
vector<pair<int,int>> ans;

bool chk(){
    for(int i = 1; i <= n; i++){
        if(operation[i] != i){
            return 1;
        }
    }
    while(ans.size() < 2){
        ans.push_back({1,1});
    }
    flag = 1;
    return 0;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        operation[i] = arr[i];
        idx[arr[i]] = i;
    }
    // 앞에서 뒤집는거
    while(chk() && cnt < 2){
        for(int i = 1; i <= n; i++){
            if(operation[i] != i){
                reverse(operation+i, operation+idx[i]+1);
                ans.push_back({i, idx[i]});
                break;
            }
        }
        cnt++;
    }
    // 뒤에서 뒤집는거
    if(!flag){
        cnt = 0;
        ans.clear();
        for(int i = 1; i <= n; i++){
            operation[i] = arr[i];
        }
        while(chk() && cnt < 2){
            for(int i = n; i >= 1; i--){
                if(operation[i] != i){
                    reverse(operation+idx[i], operation+i+1);
                    ans.push_back({idx[i], i});   
                    break;
                }
            }
            cnt++;
        }
    }
    for(auto &[s, e]: ans){
        cout << s << ' ' << e << '\n';
    }
}