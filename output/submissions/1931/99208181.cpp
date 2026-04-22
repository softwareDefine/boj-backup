#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vc;
int num;
int cnt;

int cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;
    for(int i=0;i<num;i++){
        int temps,tempf;
        cin >> temps >> tempf;
        vc.push_back({temps,tempf});
    }
    sort(vc.begin(),vc.end(),cmp);
    //vc.erase(unique(vc.begin(),vc.end()),vc.end());
    cnt++;
    int time = vc[0].second;
    int mysize = vc.size();
    for(int i=1;i<mysize;i++){
        if(time<=vc[i].first){
            time=vc[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
