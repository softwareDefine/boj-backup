#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int main(){
    cin >> t;
    while(t--){
        int arr[5][5] = {0, };
        cin >> n;
        for(int i=0;i<4;i++){
            arr[i][0] += n/60;   
        }
        arr[0][0] += 1;
        arr[1][0] += 1;
        arr[0][2] += (60-n%60)/10;
        arr[1][2] += (60-n%60)/10;
        arr[0][2]+=1;
        arr[0][3]+=10- (60-n%60)%10;
        arr[1][4]+=(60-n%60)%10;
        arr[2][1] += (n%60)/10;
        arr[3][1] += (n%60)/10;
        arr[2][1]+=1;
        arr[2][4]+=10- (n%60)%10;
        arr[3][3]+=(n%60)%10;
        int sum =999999999;
        int nowidx[5] = {0 , };
        for(int i=0;i<4;i++){
            int tmpsum = 0;
            for(int j=0;j<5;j++){
                tmpsum += arr[i][j];
            }
            if(sum >= tmpsum){
                    int flag = 0;
                    if(sum == tmpsum){
                        for(int j=0;j<5;j++){
                            if(nowidx[j] > arr[i][j]){
                                flag = 1;
                                break;
                            }
                        }
                    }else{
                        sum = tmpsum;
                        flag =1;
                    }
                    if(flag){
                        //cout << 1;
                        for(int j=0;j<5;j++){
                            nowidx[j] = arr[i][j];
                        }
                    }
            }
            //cout << '\n';
        }
        //cout << '\n';
        for(int j=0;j<5;j++){
            cout << nowidx[j] << ' ';
        }
        cout << '\n';
    }
}