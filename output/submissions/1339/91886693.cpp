#include<bits/stdc++.h>

using ll = long long;
using namespace std;

string word[30];
int n;

int change[30];
pair<ll,int> prior[30];

int cmp(pair<ll,int> &a , pair<ll,int> &b){
    return a > b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<30;i++){
        prior[i].second = i;
    }
    for(int i=0;i<n;i++){
        cin >> word[i];
        for(int j=0;j<word[i].size();j++){
            prior[word[i][j]-'A'].first += pow (10,(word[i].size()-j-1));
        }
    }
    sort(prior,prior+30,cmp);
    int cnt = 9;
    for(int i=0;i<10;i++){
        //cout << char(prior[i].second + 'A') << '\n'; 
        change[prior[i].second] = cnt--;
    }
    ll sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<word[i].size();j++){
            word[i][j]= change[word[i][j]-'A'] + '0';
        }
        sum += stoll(word[i]);
    }
    cout << sum;
}