#include <iostream>
#include <vector>

using namespace std;

int n;
int minpl[51000];
vector<int> vc[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i*i<=50000;i++){
        minpl[i*i] = 1; 
        vc[1].push_back(i*i);
    }
    for(auto& a : vc[1]){
        for(auto &b : vc[1]){
            if(a+b > 50000){
                break;
            }
            if(!minpl[a+b]) {
            minpl[a+b] = 2;
            }
            vc[2].push_back(a+b);
         }
    }
     for(auto& a : vc[1]){
        for(auto &b : vc[2]){
         if(a+b > 50000){
             break;
         }
            if(!minpl[a+b]) minpl[a+b] = 3;
             vc[3].push_back(a+b);
         }
     }
     for(auto& a : vc[1]){
         for(auto &b : vc[3]){
            if(a+b > 50000){
             break;
         }
             if(!minpl[a+b]) minpl[a+b] = 4;
             vc[4].push_back(a+b);
         }
     }
     for(auto& a : vc[2]){
         for(auto &b : vc[2]){
            if(a+b > 50000){
                break;
            }
             if(!minpl[a+b]) minpl[a+b] = 4;
             vc[4].push_back(a+b);
         }
     }
     cout << minpl[n];
}