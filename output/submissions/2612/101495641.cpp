#include <bits/stdc++.h>

using namespace std;

int n, m;
string str1, str2;

int dp[2010][2010];
pair<int, int> before[2010][2010];

string padding(string str){
    string tmp = "";
    for(int i = 0; i < 2*str.length()+1; i++){
        if(i % 2){
            tmp.push_back(str[i/2]);
        }else{
            tmp.push_back('0');
        }
    }
    return tmp;
}

typedef struct{
    int first;
    int second;
    int cnt;
}Node;

queue<Node> qu;

int ans;
pair<int,int> ansidx;
vector<char> dna1;
vector<char> dna2;

int main(){
    cin >> n; cin >> str1;
    cin >> m; cin >> str2;
    str1 = padding(str1);
    str2 = padding(str2);
    dp[1][1] = (str1[1] == str2[1]?3:0);
    for(int i = 0; i < 2010; i++){
        for(int j = 0; j < 2010; j++){
            before[i][j] = {-1, -1};
        }
    }
    for(int i = 1; i<= str1.size() + str2.size()-2; i++){
        for(int first = 0; first <= i; first++){
            int second = i - first;
            if(first < 2010 && second < 2010){
                if(first % 2 == 1 && second % 2 == 1){
                    if(first + 1 < str1.size() && second + 2 < str2.size() && dp[first+1][second+2] < dp[first][second] - 2){
                        dp[first+1][second+2] = max(dp[first+1][second+2], dp[first][second] - 2);
                        before[first+1][second+2] = {first,second};
                    }
                    if(first + 2 < str1.size() && second + 1 < str2.size() && dp[first+2][second+1] < dp[first][second] - 2){
                        dp[first+2][second+1] = max(dp[first+2][second+1], dp[first][second] - 2);
                        before[first+2][second+1] = {first,second};
                    }
                    if(first + 2 < str1.size() && second + 2 < str2.size() && dp[first+2][second+2] < dp[first][second]+ (str1[first+2] == str2[second+2]?3:-2)){
                        dp[first+2][second+2] = max(dp[first+2][second+2], dp[first][second]+ (str1[first+2] == str2[second+2]?3:-2));
                        before[first+2][second+2] = {first,second};
                    }
                }else if(first % 2 == 1 && second % 2 == 0){
                    if(first + 2 < str1.size() && dp[first+2][second] < dp[first][second] - 2){
                        dp[first+2][second] = max(dp[first+2][second], dp[first][second]-2);
                        before[first+2][second] = {first,second};
                    }
                    if(first + 1 < str1.size() && second + 1 < str2.size() && dp[first+1][second+1] < dp[first][second] - 2){
                        dp[first+1][second+1] = max(dp[first+1][second+1], dp[first][second]-2);
                        before[first+1][second+1] = {first,second};
                    }
                    if(first + 2 < str1.size() && second + 1 < str2.size() && dp[first+2][second+1] < dp[first][second]+ (str1[first+2] == str2[second+1]?3:-2)){
                        dp[first+2][second+1] = max(dp[first+2][second+1], dp[first][second]+ (str1[first+2] == str2[second+1]?3:-2));
                        before[first+2][second+1] = {first,second};
                    }
                }else if(first % 2 == 0 && second % 2 == 1){
                    if(second+2 < str2.size() && dp[first][second+2] < dp[first][second] - 2){
                        dp[first][second+2] = max(dp[first][second+2], dp[first][second]-2);
                        before[first][second+2] = {first,second};
                    }
                    if(first + 1 < str1.size() && second + 1 < str2.size() && dp[first+1][second+1] < dp[first][second] - 2){
                        dp[first+1][second+1] = max(dp[first+1][second+1],dp[first][second]-2);
                        before[first+1][second+1] = {first,second};
                    }
                    if(first + 1 < str1.size() && second + 2 < str2.size() && dp[first+1][second+2] < dp[first][second]+ (str1[first+1] == str2[second+2]?3:-2)){
                        dp[first+1][second+2] = max(dp[first+1][second+2],dp[first][second]+ (str1[first+1] == str2[second+2]?3:-2));
                        before[first+1][second+2] = {first,second};
                    }
                }
            }
        }
    }
    for(int i = 0; i < 2010; i++){
        for(int j = 0; j < 2010; j++){
            if(ans < dp[i][j]){
                ans = max(ans, dp[i][j]); 
                ansidx = {i, j};
            }
        }
    }
    const pair<int,int> undir = {-1, -1}; 
    while(ansidx != undir){
        if(dp[ansidx.first][ansidx.second]){
            if(ansidx.first % 2 == 1){
                dna1.push_back(str1[ansidx.first]);
            }
            if(ansidx.second % 2 == 1){
                dna2.push_back(str2[ansidx.second]);
            }   
        }
        ansidx = before[ansidx.first][ansidx.second];
    }
    cout << ans << '\n';
    reverse(dna1.begin(),dna1.end());
    reverse(dna2.begin(),dna2.end());
    for(auto &printer : dna1){
        cout << printer;
    }
    cout << '\n';
    for(auto &printer : dna2){
        cout << printer;
    }
}