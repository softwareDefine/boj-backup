#include <bits/stdc++.h>

using namespace std;

int n;
int mp[200][200];
int prefix[200][200];
int mmx;

int main(){
    int n;
    cin >> n;
    for(int t=0;t<n;t++){
        int x,y;
        cin >> x >> y;
        for(int i=y;i<y+10;i++){
            for(int j=x;j<x+10;j++){
                mp[i][j] = 1;
            }
        }
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mp[i][j];
        }
    }
    for(int sRow=1;sRow<=100;sRow++){
        for(int eRow=sRow+1;eRow<=100;eRow++){
            for(int sColumn=1;sColumn<=100;sColumn++){
                for(int eColumn=sColumn+1;eColumn<=100;eColumn++){
                    int chker = prefix[eRow][eColumn] - prefix[eRow][sColumn-1] - prefix[sRow-1][eColumn] + prefix[sRow-1][sColumn-1]; 
                    if(((eRow-sRow+1)*(eColumn-sColumn+1)) == chker){
                        //cout << sRow << ' ' << eRow << "," << sColumn << ' ' << eColumn << '\n';
                        mmx = max(mmx,chker);
                    }
                }
            }
        }
    }
    cout << mmx;
}