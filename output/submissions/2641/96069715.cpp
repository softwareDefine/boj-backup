#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[200];
int brr[200];
int ychk[200][100];
vector<int> vc;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i+n] = arr[i];
    }
    for(int i=1;i<=2*n;i++){
        if(arr[2*n-i] == 1){
            brr[i-1] = 3;
        }else if(arr[2*n-i] == 2){
            brr[i-1] = 4;
        }else if(arr[2*n-i] == 3){
            brr[i-1] = 1;
        }else{
            brr[i-1] = 2;
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> ychk[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<2*n;j++){
            int flag = 0;
            for(int k=0;k<n;k++){
                if(arr[j+k] != ychk[i][k]){
                    flag =1;
                    break;
                }
            }
            if(!flag){
                vc.push_back(i);
                break;
            }
            flag = 0;
            for(int k=0;k<n;k++){
                if(brr[j+k] != ychk[i][k]){
                    flag =1;
                    break;
                }
            }
            if(!flag){
                vc.push_back(i);
                break;
            }
        }
    }
    cout << vc.size() << '\n';
    for(auto i : vc){
        for(int j=0;j<n;j++){
            cout << ychk[i][j] << ' ';
        }
        cout << '\n';
    }
}