#include<bits/stdc++.h>

using namespace std;

int arr[20][20];
int mp[7];

void go(int i, int j,int pos){
    switch(pos){
        case 1:{
            if(i-1 >= 0 && arr[i-1][j]){
                if(mp[5]){
                    if(arr[i-1][j] != mp[5]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[5] = arr[i-1][j];
                    go(i-1, j, 5);
                }
            }
            if(j-1 >= 0 && arr[i][j-1]){
                if(mp[4]){
                    if(arr[i][j-1] != mp[4]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[4] = arr[i][j-1];
                    go(i, j-1, 4);
                }
            }
            if(j+1 < 6 && arr[i][j+1]){
                if(mp[2]){
                    if(arr[i][j+1] != mp[2]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[2] = arr[i][j+1];
                    go(i, j+1, 2);
                }
            }
            if(i+1 < 6 && arr[i+1][j]){
                if(mp[6]){
                    if(arr[i+1][j] != mp[6]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[6] = arr[i+1][j];
                    go(i+1, j, 6);
                }
            }
            break;
        }
        case 2:{
            if(i-1 >= 0 && arr[i-1][j]){
                if(mp[5]){
                    if(arr[i-1][j] != mp[5]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[5] = arr[i-1][j];
                    go(i-1, j, 5);
                }
            }
            if(j-1 >= 0 && arr[i][j-1]){
                if(mp[1]){
                    if(arr[i][j-1] != mp[1]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[1] = arr[i][j-1];
                    go(i, j-1, 1);
                }
            }
            if(j+1 < 6 && arr[i][j+1]){
                if(mp[3]){
                    if(arr[i][j+1] != mp[3]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[3] = arr[i][j+1];
                    go(i, j+1, 3);
                }
            }
            if(i+1 < 6 && arr[i+1][j]){
                if(mp[6]){
                    if(arr[i+1][j] != mp[6]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[6] = arr[i+1][j];
                    go(i+1, j, 6);
                }
            }
            break;
        }
        case 3:{
            if(i-1 >= 0 && arr[i-1][j]){
                if(mp[5]){
                    if(arr[i-1][j] != mp[5]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[5] = arr[i-1][j];
                    go(i-1, j, 5);
                }
            }
            if(j-1 >= 0 && arr[i][j-1]){
                if(mp[2]){
                    if(arr[i][j-1] != mp[2]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[2] = arr[i][j-1];
                    go(i, j-1, 2);
                }
            }
            if(j+1 < 6 && arr[i][j+1]){
                if(mp[4]){
                    if(arr[i][j+1] != mp[4]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[4] = arr[i][j+1];
                    go(i, j+1, 4);
                }
            }
            if(i+1 < 6 && arr[i+1][j]){
                if(mp[6]){
                    if(arr[i+1][j] != mp[6]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[6] = arr[i+1][j];
                    go(i+1, j, 6);
                }
            }
            break;
        }
        case 4:{
            if(i-1 >= 0 && arr[i-1][j]){
                if(mp[5]){
                    if(arr[i-1][j] != mp[5]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[5] = arr[i-1][j];
                    go(i-1, j, 5);
                }
            }
            if(j-1 >= 0 && arr[i][j-1]){
                if(mp[3]){
                    if(arr[i][j-1] != mp[3]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[3] = arr[i][j-1];
                    go(i, j-1, 3);
                }
            }
            if(j+1 < 6 && arr[i][j+1]){
                if(mp[1]){
                    if(arr[i][j+1] != mp[1]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[1] = arr[i][j+1];
                    go(i, j+1, 1);
                }
            }
            if(i+1 < 6 && arr[i+1][j]){
                if(mp[6]){
                    if(arr[i+1][j] != mp[6]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[6] = arr[i+1][j];
                    go(i+1, j, 6);
                }
            }
            break;
        }
        case 5:{
            if(i-1 >= 0 && arr[i-1][j]){
                if(mp[4]){
                    if(arr[i-1][j] != mp[4]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[4] = arr[i-1][j];
                    go(i-1, j, 4);
                }
            }
            if(j-1 >= 0 && arr[i][j-1]){
                if(mp[1]){
                    if(arr[i][j-1] != mp[1]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[1] = arr[i][j-1];
                    go(i, j-1, 1);
                }
            }
            if(j+1 < 6 && arr[i][j+1]){
                if(mp[3]){
                    if(arr[i][j+1] != mp[3]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[3] = arr[i][j+1];
                    go(i, j+1, 3);
                }
            }
            if(i+1 < 6 && arr[i+1][j]){
                if(mp[6]){
                    if(arr[i+1][j] != mp[2]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[2] = arr[i+1][j];
                    go(i+1, j, 2);
                }
            }
            break;
        }
        case 6:{
            if(i-1 >= 0 && arr[i-1][j]){
                if(mp[2]){
                    if(arr[i-1][j] != mp[2]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[2] = arr[i-1][j];
                    go(i-1, j, 2);
                }
            }
            if(j-1 >= 0 && arr[i][j-1]){
                if(mp[1]){
                    if(arr[i][j-1] != mp[1]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[1] = arr[i][j-1];
                    go(i, j-1, 1);
                }
            }
            if(j+1 < 6 && arr[i][j+1]){
                if(mp[3]){
                    if(arr[i][j+1] != mp[3]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[3] = arr[i][j+1];
                    go(i, j+1, 3);
                }
            }
            if(i+1 < 6 && arr[i+1][j]){
                if(mp[4]){
                    if(arr[i+1][j] != mp[4]){
                        cout << 0;
                        exit(0);
                    }
                }else{
                    mp[4] = arr[i+1][j];
                    go(i+1, j, 4);
                }
            }
            break;
        }
    }
}

int main(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6 ; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6 ; j++){
            if(arr[i][j] == 1){
                go(i, j, 1);
                break;
            }
        }
    }
    cout << mp[3];
}