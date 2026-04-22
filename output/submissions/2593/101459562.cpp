#include <bits/stdc++.h>

using namespace std;

int n, m;

typedef struct{
    int myElevator;
    int myFloor;
    int cnt;
}Node;

vector<int> floar[200000];
pair<int,int> elevator[200];

int usedElev[200];
int before[200];
int visitedFloor[200000];

queue<Node> qu;

vector<int> ans;

int s, e;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        elevator[i] = {x, y};
        for(int j = x; j <= n; j+= y){
            floar[j].push_back(i);
        }
    }
   cin >> s >> e;
   for(auto &element : floar[s]){
       usedElev[element] = 1;
       before[element] = -1;
       qu.push({element, s, 0});
   }
   visitedFloor[s] = 1;
   while(!qu.empty()){
       auto [myElevator, myFloor, cnt] = qu.front();
       qu.pop();
       auto [x, y] = elevator[myElevator];
       for(int i = x; i <= n; i+= y){
        if(i == e){
            cout << cnt + 1 << '\n';
            int element = myElevator;
            do{
                ans.push_back(element);
            }while((element = before[element]) != -1);
            break;
        }
        if(!visitedFloor[i]){
            for(auto nextElevator : floar[i]){
                if(!usedElev[nextElevator]){
                    qu.push({nextElevator, i, cnt+1});
                    before[nextElevator] = myElevator; 
                    usedElev[nextElevator] = 1;
                }
            }
            visitedFloor[i] = 1;
        }
       }
   }
   if(ans.empty()){
       cout << -1;
        return 0;   
   }
   reverse(ans.begin(),ans.end());
   for(auto &element : ans){
       cout << element << '\n';
   }
}