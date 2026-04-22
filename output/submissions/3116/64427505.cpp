#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace  std;

int n,a,b,c;
vector<pair<int,pair<int,int>>> vc;
vector<pair<int,int>> fd[2000010];
// time , 좌표
struct line{
    int a,b,c;
};
bool check(int x,int y, pair<int,pair<int,int>> &v){
    int flag = 0;
    switch(v.first){
        case 1:
            if(x > v.second.first){
                flag =1;
            }
            break;
        case 2:
            if(y < v.second.second){
                flag =1;
            }
            break;
        case 3:
            if(x < v.second.first){
                flag =1;
            }
            break;
        case 4:
            if(x < v.second.first){
                flag = 1;
            }
            break;
        case 5:
            if(x < v.second.first){
                flag = 1;
            }break;
        case 6:
            if(y > v.second.second){
                flag =1;
            }
            break;
        case 7:
            if(x > v.second.first){
                flag =1;
            }
            break;
        case 8:
            if(x > v.second.first){
                flag =1;
            }break;
    }
    return !flag;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        vc.push_back({c,{a,b}});
    }
    for(int i=0;i<n;i++){
        line f;
        if(vc[i].first == 1 || vc[i].first == 5){
            f.a = 1;
            f.b = 1;
            f.c = -vc[i].second.first - vc[i].second.second ;
        }else if(vc[i].first == 2 || vc[i].first == 6){
            f.a = 1;
            f.b = 0;
            f.c = -vc[i].second.first;
        }else if(vc[i].first == 3 || vc[i].first == 7){
            f.a = -1;
            f.b = 1;
            f.c = +vc[i].second.first - vc[i].second.second;
        }else{
            f.a = 0;
            f.b = 1;
            f.c = -vc[i].second.second;
        }
        for(int j=i+1;j<n;j++){
            line g;
            if(vc[j].first == 1 || vc[j].first == 5){
                g.a = 1;
                g.b = 1;
                g.c = -vc[j].second.first - vc[j].second.second ;
            }else if(vc[j].first == 2 || vc[j].first == 6){
                g.a = 1;
                g.b = 0;
                g.c = -vc[j].second.first;
            }else if(vc[j].first == 3 || vc[j].first == 7){
                g.a = -1;
                g.b = 1;
                g.c = vc[j].second.first - vc[j].second.second;
            }else {
                g.a = 0;
                g.b = 1;
                g.c = -vc[j].second.second;
            }
            if(f.a*g.b - g.a*f.b == 0){
                int time = 0;
                int x= 0 , y=0;
                int flag = 0;
                if(vc[i].second.first == vc[j].second.first && vc[i].second.second == vc[j].second.second){
                    fd[0].push_back({x,y});
                    continue;
                }
                if(vc[i].first   != vc[j].first ){
                    if(vc[i].first % 4 == 0){
                        if(vc[i].second.second == vc[j].second.second){
                            if(abs(vc[i].second.first-vc[j].second.first)%2==0){
                                time = abs(vc[i].second.first-vc[j].second.first)/2;
                                x = (vc[i].second.first + vc[j].second.first)/2;
                                y = vc[i].second.second;
                            }else{
                                flag =1;
                            }
                        }else{
                            flag =1;
                        }
                    }else if(vc[i].first % 4 == 1){
                        if(f.a == g.a && f.b == g.b && f.c == g.c){
                            if((vc[i].second.first + vc[j].second.first)%2 ==0 && (vc[i].second.second + vc[j].second.second)%2 ==0){
                                time = abs(vc[i].second.first-vc[j].second.first)/2;
                                x= (vc[i].second.first+ vc[j].second.first)/2;
                                y = (vc[i].second.second+vc[j].second.second)/2;
                            }else{
                                flag =1;
                            }
                        }else{
                            flag =1;
                        }
                    }else if(vc[i].first % 4 == 2){
                        if(vc[i].second.first == vc[j].second.first){
                            if(abs(vc[i].second.second-vc[j].second.second)%2==0){
                                time = abs(vc[i].second.second-vc[j].second.second)/2;
                                x = vc[i].second.first;
                                y = (vc[i].second.second + vc[j].second.second)/2;
                            }else{
                                flag =1;
                            }
                        }else{
                            flag =1;
                        }
                    }else{
                        if(f.a == g.a && f.b == g.b && f.c == g.c){
                            if((vc[i].second.first + vc[j].second.first)%2 ==0 && (vc[i].second.second + vc[j].second.second)%2 ==0){
                                time = abs(vc[i].second.first-vc[j].second.first)/2;
                                x= (vc[i].second.first+ vc[j].second.first)/2;
                                y = (vc[i].second.second+vc[j].second.second)/2;
                            }else{
                                flag =1;
                            }
                        }else{
                            flag =1;
                        }
                    }
                }else{
                    flag =1;
                }
                if(!flag && check(x,y,vc[i]) && check(x,y,vc[j])){
                    fd[time].push_back({x,y});
                }
                continue;
            }else{
                int mmx = 0;
                int mmx2 = 0;
                int x= -(f.c * g.b - f.b * g.c)/(f.a*g.b - g.a*f.b);
                int y = -(f.a * g.c - f.c*g.a)/(f.a*g.b - g.a*f.b);
                mmx = max(abs(vc[i].second.first-x),abs(vc[i].second.second-y));
                mmx2 = max(abs(vc[j].second.first-x),abs(vc[j].second.second - y));
                if(mmx == mmx2 && check(x,y,vc[i])&& check(x,y,vc[j])){
                    fd[mmx].push_back({x,y});
                }
            }
        }
    }
    int mmx = 0;
    int mmf = 0;
    for(int i=0;i<2000010;i++){
        if(!fd[i].empty()){
            sort(fd[i].begin(),fd[i].end(),[&](auto a,auto b){
                return a < b;
            });
            int cnt = 0;
            for(int j=0;j<fd[i].size()-1;j++){
                if(fd[i][j].first == fd[i][j+1].first && fd[i][j].second == fd[i][j+1].second){
                    cnt++;
                }else{
                    cnt = 0;
                }
                if(mmx < cnt+1){
                    mmx = cnt+1;
                    mmf = i;
                }
            }
        }

    }
    for(int i=1;i<=5000;i++){
        if(i*(i-1)/2 == mmx){
            mmx = i;
            break;
        }
    }
    cout << mmx << '\n' << mmf;
}