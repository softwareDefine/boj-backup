#include<bits/stdc++.h>

using namespace std;

int n;
long long sum;
vector<pair<int,int>> status[20000];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        double a,b,c,d;
        cin >> a >> b >> c >> d;
        int startx = a*10;
        int endx = startx + c*10;
        int starty = b*10;
        int endy = starty + d*10;
        for(int j=startx;j<endx;j++){
            status[j].push_back({starty,endy});
        }
    }
    for(int i=0;i<=20000;i++){
        sort(status[i].begin(),status[i].end());
        if(!status[i].size()){continue;}
        int start = status[i][0].first;
        int end = status[i][0].second;
        for(int j=1;j<status[i].size();j++){
            if(end < status[i][j].first){
                sum += end - start;
                start = status[i][j].first;
                end = status[i][j].second;
                continue;
            }
            if(end< status[i][j].second  ){
                end = status[i][j].second;
            }
        }
        sum += end - start;
    }
    if(sum % 100){
        printf("%.2lf",sum/100.0);
    }else{
        cout << sum / 100;
    }
}