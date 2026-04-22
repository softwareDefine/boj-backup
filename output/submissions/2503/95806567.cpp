#include <bits/stdc++.h>

using namespace std;

int q;
int arr[200][3];
int cnt;

int main()
{
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                int flag =0;
                for(int p=0;p<q;p++){
                    int strike = 0;
                    int ball = 0;
                    int first = arr[p][0]/100;
                    int second = arr[p][0]%100/10;
                    int third = arr[p][0]%10;
                    if(i == first){
                        first = 0;
                        strike++;
                    }
                    if(j == second){
                        second = 0;
                        strike++;
                    }
                    if(k == third){
                        third = 0;
                        strike++;
                    }
                    if(first){
                        if(i == second){
                            //second = 0;
                            ball++;
                        }
                        if(i == third){
                            //third = 0;
                            ball++;
                        }
                    }
                    if(second){
                        if(j == first){
                            ball++;
                            //first = 0;
                        }
                        if(j == third){
                            ball++;
                            //third = 0;
                        }
                    }
                    if(third){
                        if(k == first){
                            ball++;
                            //first = 0;
                        }
                        if(k == second){
                            ball++;
                            //second = 0;
                        }
                    }
                    if(strike != arr[p][1] || ball != arr[p][2]){
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}