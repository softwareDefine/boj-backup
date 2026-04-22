#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint h1, w1;
lint h2, w2;

lint dp[60][60];

lint ans = 99999999999;

lint go(lint width, lint height){
    if(width == 0 || height == 0){ return dp[width][height] = 0; }
    if(dp[width][height] != 99999999999){ return dp[width][height];}
    for(int i = 1; i < width; i++){
        dp[width][height] = min(dp[width][height], go(i, height) + go(width-i, height));
    }
    for(int i = 1; i < height; i++){
        dp[width][height] = min(dp[width][height], go(width, i) + go(width, height-i));
    }
    if(width >= height && width % height == 0){
        dp[width][height] = min(dp[width][height], width/height);
    }
    if(height >= width && height % width == 0){
        dp[width][height] = min(dp[width][height], height/width);
    }
    return dp[width][height];
}

int main(){
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            dp[i][j] = 99999999999;
        }
    }
    cin >> h1 >> w1 >> h2 >> w2;
    for(int i = 0; i <= w1-w2; i++){
        ans = min(ans, go(i, h1) + go(w1-w2-i, h2) + go(w1-i, h1-h2));
    }
    for(int i = 0; i <= h1-h2; i++){
        ans = min(ans, go(w1, i) + go(w1-w2, h1-i) + go(w2 ,h1-h2-i));
    }
    cout << ans;
}