#include <bits/stdc++.h>

using namespace std;

int n;

typedef struct {
    pair<int,int> point1;
    pair<int,int> point2;
}line;

int sum,mmx;
vector<line> vc;
vector<int> cnt(51);

bool checker(line b,line a){
    if(b.point1.first == b.point2.first){
        if(a.point1.first == b.point2.first  && a.point1.first == a.point2.first){
            int chch =0;
            if(b.point1.second < a.point1.second && a.point1.second < b.point2.second){
                chch++;
            }
            if(b.point1.second < a.point2.second && a.point2.second < b.point2.second){
                chch++;
            }
            if(chch == 1){
                return 1;
            }
            return 0;
        }
    }else if(b.point2.second == b.point1.second){
        if(a.point1.second == b.point2.second && a.point1.second == a.point2.second){
            int chch =0;
            if(b.point1.first < a.point1.first && a.point1.first < b.point2.first){
                chch++;
            }
            if(b.point1.first < a.point2.first && a.point2.first < b.point2.first){
                chch++;
            }
            if(chch == 1){
                return 1;
            }
            return 0;
        }
    }
    if(a.point1.first == a.point2.first){
    if(b.point1.first == a.point2.first && b.point1.first == b.point2.first){
        int chch = 0;
        if(a.point1.second < b.point1.second && b.point1.second < a.point2.second){
            chch++;
        }
        if(a.point1.second < b.point2.second && b.point2.second < a.point2.second){
            chch++;
        }
        if(chch == 1){
            return 1;
        }
        return 0;
    }
}else if(a.point2.second == a.point1.second){
    if(b.point1.second == a.point2.second && b.point1.second == b.point2.second){
        int chch = 0;
        if(a.point1.first < b.point1.first && b.point1.first < a.point2.first){
            chch++;
        }
        if(a.point1.first < b.point2.first && b.point2.first < a.point2.first){
            chch++;
        }
        if(chch == 1){
            return 1;
        }
        return 0;
    }
}

    int c=  (b.point2.second-b.point1.second)*(a.point1.first -b.point2.first) + (b.point2.second - a.point1.second)*(b.point2.first-b.point1.first); 
    int d = (b.point2.second-b.point1.second)*(a.point2.first -b.point2.first) +(b.point2.second - a.point2.second)*(b.point2.first-b.point1.first);
    return c * d < 0;
}

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
            
            a = b;
            b= 51;
            
        }else{
            
            a =b;
            b= 0;
        }
        if(c == 3){
            c = 0;
        }else if(c== 4){
            c = 51;
        }else if(c==2){
            
            c = d;
            d = 51;
        }else{
            
            c =d;
            d = 0;
        }
        vc.push_back({{a,b},{c,d}});
    }
    for(int i=0;i<vc.size();i++){
        for(int j=0;j<vc.size();j++){
            if(i==j){continue;} 
            if(checker(vc[i],vc[j])){
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
    cout << (sum+1)/2 << '\n' << mmx;
}