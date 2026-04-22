#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;

int n,r;
int cnt;
int m;
vector<int> vi;
double dist[400][400];
double ndist[400][400];
double ntc,tc;
int k;

int main(){
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            dist[i][j] = 9999999;
            ndist[i][j] = 9999999;
        }
    }
    cin >> n >> r;
    for(int i=0;i<n;i++){
        string city;
        cin >> city;
        if(mp.find(city) == mp.end()){
            mp.insert({city,cnt++});
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        string city;
        cin >> city;
        vi.push_back(mp[city]);
    }
    cin >> k;
    for(int i=0;i<k;i++){
        string trans,city1,city2;
        double cost;
        cin >> trans >> city1 >> city2 >> cost;
        if(trans == "Mugunghwa" || trans  == "ITX-Saemaeul" || trans == "ITX-Cheongchun"){
            ndist[mp[city1]][mp[city2]] = 0;
            ndist[mp[city2]][mp[city1]] = 0;
        }else if(trans == "S-Train" || trans == "V-Train"){
            ndist[mp[city1]][mp[city2]] = min(ndist[mp[city1]][mp[city2]],cost/2.0);
            ndist[mp[city2]][mp[city1]] = min(ndist[mp[city2]][mp[city1]],cost/2.0);
        }else{
            ndist[mp[city1]][mp[city2]] = min(ndist[mp[city1]][mp[city2]],cost);
            ndist[mp[city2]][mp[city1]] = min(ndist[mp[city2]][mp[city1]],cost);
        }
        dist[mp[city1]][mp[city2]] = min(dist[mp[city1]][mp[city2]],cost);
        dist[mp[city2]][mp[city1]] = min(dist[mp[city2]][mp[city1]],cost);
    }
    n = mp.size();
    for(int k2=0;k2<n;k2++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ndist[i][j] = min(ndist[i][j],ndist[i][k2] + ndist[k2][j]);
                dist[i][j] = min(dist[i][j],dist[i][k2] + dist[k2][j]);
            }
        }
    }
    for(int i=0;i<m-1;i++){
        ntc += ndist[vi[i]][vi[i+1]];
        tc += dist[vi[i]][vi[i+1]];
    }
    ntc += r;
    if(tc <= ntc){
        cout << "No";
    }else{
        cout << "Yes";
    }
}