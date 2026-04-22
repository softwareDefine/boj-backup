#include<bits/stdc++.h>

using namespace std;

int arr[300010];
int des1[20000];
int des2[20000];
int last1,last2;
int t;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        int n;
        int mmx = -99999999;
        last1 = 0; 
        last2 = 0;
        for(int i=0;i<20000;i++){
            des1[i] = 0;
            des2[i] = 0;
        }
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        des1[0] = arr[0];
        des2[0] = arr[0];
        for(int i=2;i<=n;i++){
            if(!(i%2)){
                des1[i/2] = arr[i-1];
                mmx=max(mmx,des1[i/2] - des1[i/2 - 1]);
                last1 = des1[i/2];
            }else{
                des2[i/2] = arr[i-1];
                mmx=max(mmx,des2[i/2]-des2[i/2-1]);
                last2 = des2[i/2];
            }
        }
        mmx = max(abs(last1-last2),mmx);
        cout << mmx << '\n';
    }
}