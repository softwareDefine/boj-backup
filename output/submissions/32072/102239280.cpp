#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<int> childern[310000];

priority_queue<int> childernVal[310000];

int val[310000];

int valToNum[310000];

int parent[310000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        int pi;
        cin >> pi;
        childern[pi].push_back(i);
        parent[i] = pi;
    }
    for(int i = 1; i <= n; i++){
        cin >> val[i];
        valToNum[val[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        for(auto next : childern[i]){
            childernVal[i].push(-val[next]);
        }
    }
    for(int i = 1; i <= 5; i++){
        cout << val[1] << '\n';
        val[1] = 0;
        int now = 1, next = 0;
        while(!childernVal[now].empty() && childernVal[now].top() != -999999){
            int mmnVal = -childernVal[now].top();
            next = valToNum[mmnVal];
            if(now != 1){
                int swap1 = childernVal[parent[now]].top();
                int swap2 = childernVal[parent[next]].top();
                childernVal[parent[now]].pop();
                childernVal[parent[now]].push(swap2);
                childernVal[parent[next]].pop();
                childernVal[parent[next]].push(swap1);
            }else{
                childernVal[now].pop();
                childernVal[now].push(0);
            }
            swap(val[now], val[next]);
            valToNum[val[now]] = now;
            valToNum[val[next]] = next;
            now = next;
        }
        if(now != 1){
            childernVal[parent[now]].pop();
            childernVal[parent[now]].push(-999999);
            val[now] = 999999;
        }
    }
    return 0;
}