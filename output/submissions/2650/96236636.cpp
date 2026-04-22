#include <bits/stdc++.h>

using namespace std;

int n;

typedef struct {
    pair<int,int> point1;
    pair<int,int> point2;
}line;

int sum,mmx;
vector<line> vc;
vector<int> cnt;

int main(){
    
    cin >> n;
    for(int i=0;i<(n/2);i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
          if(a == 3){
            a = 0;
        }else if(a== 4){
            a = 51;
        }else if(a==2){
            a =b;
            b= 0;
        }else{
            a = b;
            b= 51;
        }
        if(c == 3){
            c = 0;
        }else if(c== 4){
            c = 51;
        }else if(c==2){
            c =d;
            d = 0;
        }else{
            c = d;
            d = 51;
        }
        vc.push_back({{a,b},{c,d}});
    }
    for(int i=0;i<vc.size();i++){
        for(int j=0;j<vc.size();j++){
            if(i==j){continue;}    
            if((((vc[i].point2.second-vc[i].point1.second)/(double)(vc[i].point2.first-vc[i].point1.first))*((vc[j].point2.second-vc[j].point1.second)/(double)(vc[j].point2.first-vc[j].point1.first)))<0){
                cnt[i]++;
            } 
        }
    }
    for(auto i : cnt){
        sum+=i; 
        if(i > mmx){
            mmx = i;
        }
    }
    cout << sum << '\n' << mmx;
}