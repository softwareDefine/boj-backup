#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint h1, w1;
lint h2, w2;

lint dp[60][60];
lint dp2[60][60][60][60];

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

lint ans(lint width, lint height, lint width2, lint height2){
    lint &tmp = dp2[width][height][width2][height2];
    for(int i = 1; i < width-width2; i++){
        tmp = min(tmp, ans(width-i, height, width2, height2) + go(i, height));
    }
    for(int i = 1; i < height-height2; i++){
        tmp = min(tmp, ans(width, height-i, width2, height2) + go(width, i));
    }
    for(int j = 1; j < width2; j++){
        tmp = min(tmp, ans(width-j, height, width2-j, height2) + go(j, height-height2));
    }
    for(int j = 1; j < height2; j++){
        tmp = min(tmp, ans(width, height-j, width2, height2-j) + go(width-width2, j));
    }
    tmp = min(tmp, go(width-width2, height2) + go(width, height-height2));
    return tmp;
}

int main(){
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            dp[i][j] = 99999999999;
        }
    }
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            for(int k = 0; k < 60; k++){
                for(int l = 0; l < 60; l++){
                    dp2[i][j][k][l] = 99999999999;
                }
            }
        }
    }
    cin >> h1 >> w1 >> h2 >> w2;
    cout << ans(w1, h1, w2, h2);
}