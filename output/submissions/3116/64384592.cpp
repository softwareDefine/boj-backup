#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace  std;

int n,a,b,c;
vector<pair<int,pair<int,int>>> vc;
map<pair<int,pair<int,int>>,int> mp;
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
int binary_search_for_n(int x) {

    int left = 1, right = x;

    while (left <= right) {

        int mid = (left + right) / 2;

        int formula_result = mid * (mid - 1) / 2;

        if (formula_result == x) {

            return mid;

        } else if (formula_result < x) {

            left = mid + 1;

        } else {

            right = mid - 1;

        }

    }

    return -1;  

}
int main(){
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
                if( vc[i].second.first == vc[j].second.first){
                 if(abs((vc[i].second.second-vc[j].second.second)) % 2 == 0){
                         mp[{abs(vc[i].second.second-vc[j].second.second)/2,{vc[i].second.first,(vc[i].second.second+vc[j].second.second)/2}}]++;
                 }
                }else if( vc[i].second.second == vc[j].second.second){
                    if(abs((vc[i].second.first-vc[j].second.first)) % 2 == 0){
                            mp[{abs(vc[i].second.first-vc[j].second.first)/2,{(vc[i].second.first+vc[j].second.first)/2,vc[i].second.second}}]++;
                       
                    }
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
                        mp[{mmx,{x,y}}]++;
                }
            }
        }
    }
    int mmx = 0;
    int mmf = 0;
    for(auto &i : mp){
        if( mmx < i.second){
            mmx = i.second;
            mmf = i.first.first;
        }
    }
    mmx = binary_search_for_n(mmx);
    cout << mmx << '\n' << mmf;
}