#include <bits/stdc++.h>

using namespace std;

int paper[200][200];
int cnt;
int x,y;
int n;

int main(){
    cin >> x >> y;
    cin >> n;
    for(int i=0;i<n;i++){
        char dir; int len;
        cin >> dir >> len;
        //len += 1;
        switch(dir){
            case 'U':
                while(len){paper[y++][x]+=1; len--;}
                break;
            case 'D':
                while(len){paper[y--][x]+=1; len--;}
                break;
            case 'R':
                while(len){paper[y][x++]+=1; len--;}
                break;
            case 'L':
                while(len){paper[y][x--]+=1; len--;}
                break;
        }
    }
    // for(int i=20;i>0;i--){
    //     for(int j=0;j<20;j++){
    //         cout << paper[i][j];
    //     }
    //     cout << '\n';
    // }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(paper[i][j] && paper[i+1][j] && paper[i][j+1]){
                int flag = 0;
                int width = 0,height = 0;
                int ny = i,nx = j;
                while(1){
                    if(!paper[i][nx]){
                        flag = 1;
                        break;
                    }
                    width++;
                    nx++;
                    if(paper[i+1][nx] && paper[i][nx]){
                        break;
                    }
                }
                if(flag){
                    continue;
                }
                while(1){
                    if(!paper[ny][j]){
                        flag = 1;
                        break;
                    }
                    height++;
                    ny++;
                    if(paper[ny][j+1] && paper[ny][j]){
                        break;
                    }
                }
                if(flag){
                    continue;
                }
                ny = i + height;
                nx = j;
                while(1){
                    if(!paper[ny][nx]){
                        flag = 1;
                        break;
                    }
                    nx++;
                    if(paper[ny-1][nx] && paper[ny][nx]){
                        break;
                    }
                }
                if(nx - j == width){
                    flag = 0;
                }else{
                    flag = 1;
                    continue;
                }
                ny = i;
                nx = j + width;
                while(1){
                    if(!paper[ny][nx]){
                        flag = 1;
                        break;
                    }
                    ny++;
                    if(paper[ny][nx-1] && paper[ny][nx]){
                        break;
                    }
                }
                if(ny - i == height){
                    flag = 0;
                }else{
                    flag = 1;
                    continue;
                }
                for(int a = i+1;a<i+height;a++){
                    for(int b=j+1;b<j+width;b++){
                        if(paper[a][b]){
                            flag =1;
                            break;
                        }
                    }
                    if(flag){break;}
                }
                if(flag){continue;}
                cnt++;
                cout << j << ' ' << i << '\n';
                cout << j+width << ' ' << i+height << '\n';
            }
        }
    }
    if(!cnt){
        cout << 0;
    }
}