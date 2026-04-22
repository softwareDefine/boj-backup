#include <iostream>

using namespace std;

int x1,y1,x2,y2;
int mmp[110][110];
int S;

int main()
{
    for(int i=0;i<4;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int p = x1;p<x2;p++){
            for(int q = y1;q <y2;q++){
                mmp[q][p]++;
            }
        }
    }
    for(int p=1;p<=100;p++){
        for(int q=1;q<=100;q++){
            if(mmp[q][p]){
                S++;
            }
        }
    }
    cout << S;
    return 0;
}