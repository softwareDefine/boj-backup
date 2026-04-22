#include <bits/stdc++.h>
using namespace std;

static int H[105][105], V_[105][105];
static int PH[105][105], PV[105][105];
static int HH[105][105], VV[105][105];

inline int sumRowH(int y, int l, int r_ex){
    if(l>=r_ex) return 0;
    l=max(l,1); r_ex=min(r_ex,100);
    return PH[y][r_ex-1]-PH[y][l-1];
}
inline int sumColV(int x, int l, int r_ex){
    if(l>=r_ex) return 0;
    l=max(l,1); r_ex=min(r_ex,100);
    return PV[x][r_ex-1]-PV[x][l-1];
}
inline int rectSumHH(int y1,int y2_ex,int x1,int x2_ex){
    if(y1>=y2_ex||x1>=x2_ex) return 0;
    y1=max(y1,1); y2_ex=min(y2_ex,101);
    x1=max(x1,1); x2_ex=min(x2_ex,101);
    return HH[y2_ex-1][x2_ex-1]-HH[y1-1][x2_ex-1]-HH[y2_ex-1][x1-1]+HH[y1-1][x1-1];
}
inline int rectSumVV(int x1,int x2_ex,int y1,int y2_ex){
    if(x1>=x2_ex||y1>=y2_ex) return 0;
    x1=max(x1,1); x2_ex=min(x2_ex,101);
    y1=max(y1,1); y2_ex=min(y2_ex,101);
    return VV[x2_ex-1][y2_ex-1]-VV[x1-1][y2_ex-1]-VV[x2_ex-1][y1-1]+VV[x1-1][y1-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sx,sy,n;
    if(!(cin>>sx>>sy)) return 0;
    cin>>n;

    int x=sx,y=sy;
    for(int i=0;i<n;i++){
        char d; int len; cin>>d>>len;
        if(d=='R'){ for(int k=0;k<len;k++) H[y][x+k]=1; x+=len; }
        else if(d=='L'){ for(int k=1;k<=len;k++) H[y][x-k]=1; x-=len; }
        else if(d=='U'){ for(int k=0;k<len;k++) V_[x][y+k]=1; y+=len; }
        else if(d=='D'){ for(int k=1;k<=len;k++) V_[x][y-k]=1; y-=len; }
    }

    for(int yy=1;yy<=100;yy++)
        for(int xx=1;xx<=100;xx++)
            PH[yy][xx]=PH[yy][xx-1]+H[yy][xx];

    for(int xx=1;xx<=100;xx++)
        for(int yy=1;yy<=100;yy++)
            PV[xx][yy]=PV[xx][yy-1]+V_[xx][yy];

    for(int yy=1;yy<=100;yy++)
        for(int xx=1;xx<=100;xx++){
            HH[yy][xx]=H[yy][xx]+HH[yy-1][xx]+HH[yy][xx-1]-HH[yy-1][xx-1];
            VV[xx][yy]=V_[xx][yy]+VV[xx-1][yy]+VV[xx][yy-1]-VV[xx-1][yy-1];
        }

    long long bestArea=(1LL<<60);
    int ax=0,ay=0,bx=0,by=0;
    bool found=false;

    for(int y1=1;y1<=99;y1++){
        for(int y2=y1+1;y2<=100;y2++){
            int h=y2-y1;
            for(int x1=1;x1<=99;x1++){
                for(int x2=x1+1;x2<=100;x2++){
                    int w=x2-x1;
                    if(sumRowH(y1,x1,x2)!=w) continue;
                    if(sumRowH(y2,x1,x2)!=w) continue;
                    if(sumColV(x1,y1,y2)!=h) continue;
                    if(sumColV(x2,y1,y2)!=h) continue;
                    int interiorH=rectSumHH(y1+1,y2,x1,x2);
                    int interiorV=rectSumVV(x1+1,x2,y1,y2);
                    if(interiorH||interiorV) continue;
                    long long area=1LL*w*h;
                    if(area<bestArea){
                        bestArea=area;
                        ax=x1; ay=y1; bx=x2; by=y2;
                        found=true;
                    }
                }
            }
        }
    }

    if(!found) cout<<0<<"\n";
    else{
        cout<<ax<<" "<<ay<<"\n";
        cout<<bx<<" "<<by<<"\n";
    }
    return 0;
}
