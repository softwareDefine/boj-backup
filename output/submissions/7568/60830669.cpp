#include <iostream>

using namespace std;

int num;
int cnt[53];
int xy[53][2];
int main()
{
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> xy[i][0];
        cin >> xy[i][1];
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i==j){
                continue;
            }
            if(xy[i][0]< xy[j][0] && xy[i][1] < xy[j][1]){
                    cnt[i]++;
            }
        }
    }
    for(int i=0;i<num;i++){
        cout << cnt[i]+1 <<" ";
    }
    return 0;
}
