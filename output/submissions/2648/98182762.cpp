#include <bits/stdc++.h>
using namespace std;

int paper[205][205];
int cnt;
int x,y;
int n;
int mmn = 1000000;
pair<int,int> mmnidx;
pair<int,int> mmnidx2;

static int H[105][105], V_[105][105];

bool find_one_side_rect_and_print() {
    int bestLen = INT_MAX;
    int ax=0, ay=0, bx=0, by=0;
    bool found = false;

    for (int Y = 1; Y <= 99; Y++) {
        int X = 1;
        while (X <= 100) {
            if (H[Y][X] && H[Y+1][X]) {
                int X2 = X;
                while (X2 <= 100 && H[Y][X2] && H[Y+1][X2]) X2++;
                int L = X2 - X;
                if (L >= 1) {
                    if (V_[X][Y] && V_[X+L][Y]) {
                        if (L < bestLen) {
                            bestLen = L;
                            ax = X; ay = Y;
                            bx = X + L; by = Y + 1;
                            found = true;
                        }
                    }
                }
                X = X2;
            } else {
                X++;
            }
        }
    }

    for (int X = 1; X <= 99; X++) {
        int Y = 1;
        while (Y <= 100) {
            if (V_[X][Y] && V_[X+1][Y]) {
                int Y2 = Y;
                while (Y2 <= 100 && V_[X][Y2] && V_[X+1][Y2]) Y2++;
                int L = Y2 - Y;
                if (L >= 1) {
                    if (H[Y][X] && H[Y+L][X]) {
                        if (L < bestLen) {
                            bestLen = L;
                            ax = X; ay = Y;
                            bx = X + 1; by = Y + L;
                            found = true;
                        }
                    }
                }
                Y = Y2;
            } else {
                Y++;
            }
        }
    }

    if (!found) return false;

    cout << ax << " " << ay << "\n";
    cout << bx << " " << by << "\n";
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> y;
    cin >> n;

    int cx = x, cy = y;

    for(int i=0;i<n;i++){
        char dir; int len;
        cin >> dir >> len;

        if (dir == 'U') {
            int t = len;
            while(t){ paper[cy++][cx] += 1; t--; }
            for (int k = 0; k < len; k++) V_[cx][y + k] = 1;
            y += len;
        } else if (dir == 'D') {
            int t = len;
            while(t){ paper[cy--][cx] += 1; t--; }
            for (int k = 1; k <= len; k++) V_[cx][y - k] = 1;
            y -= len;
        } else if (dir == 'R') {
            int t = len;
            while(t){ paper[cy][cx++] += 1; t--; }
            for (int k = 0; k < len; k++) H[cy][x + k] = 1;
            x += len;
        } else if (dir == 'L') {
            int t = len;
            while(t){ paper[cy][cx--] += 1; t--; }
            for (int k = 1; k <= len; k++) H[cy][x - k] = 1;
            x -= len;
        }
    }

    if (find_one_side_rect_and_print()) return 0;

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
                if(flag){
                    continue;
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
                if(flag){
                    continue;
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
                if(mmn > width*height){
                    mmn = width*height;
                    mmnidx = {j,i};
                    mmnidx2 = {j+width,i+height};
                }
            }
        }
    }

    if(mmn == 1000000){
        cout << 0;
    }else{
        cout << mmnidx.first << ' ' << mmnidx.second << '\n';
        cout << mmnidx2.first << ' ' << mmnidx2.second << '\n';
    }
    return 0;
}
