#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int i;
    int j;
    int color;
}Node;

int m, n;
queue<pair<int,int>> qu;

int main(){
    cin >> m >> n;
    cout << m*n*2 << '\n';
    if(m%2 && n%2){
        for(int i = 1; i <= m-2; i++){
            for(int j=2;j<=n;j++){
                if(i%2 == 1){
                    cout << i << ' ' << j << ' ' << 0 << '\n';
                    if(i==m-2 && j == n-1){
                        cout << i+1 << ' ' << j << ' ' << 0 << '\n';
                    }
                    cout << i << ' ' << j << ' ' << 1 << '\n';
                }else{
                    if(j % 2){
                        cout << i << ' ' << n-j+2 << ' ' << 1 << '\n';
                        cout << i << ' ' << n-j+2 << ' ' << 0 << '\n';
                    }else{
                        cout << i << ' ' << n-j+2 << ' ' << 0 << '\n';
                        cout << i << ' ' << n-j+2 << ' ' << 1 << '\n';
                    }
                }
            }
        }
        for(int i=n; i>=2;i--){
                if(i % n == 0){
                    if(i == n-1){
                        cout << m << ' ' << i << ' ' << 1 << '\n';
                        cout << m << ' ' << i << ' ' << 1 << '\n';
                        cout << m-1 << ' ' << i << ' ' << 0 << '\n';
                    }else{
                        cout << m-1 << ' ' << i << ' ' << 0 << '\n';
                        cout << m-1 << ' ' << i << ' ' << 1 << '\n';
                        cout << m << ' ' << i << ' ' << 1 << '\n';
                        cout << m << ' ' << i << ' ' << 0 << '\n';
                    }
                }else{
                    if(i == n){
                        cout << m-1 << ' ' << i << ' ' << 1 << '\n';
                        cout << m-1 << ' ' << i << ' ' << 0 << '\n';
                        cout << m << ' ' << i << ' ' << 0 << '\n';
                        cout << m << ' ' << i << ' ' << 1 << '\n';
                    }else{
                        cout << m << ' ' << i << ' ' << 1 << '\n';
                        cout << m << ' ' << i << ' ' << 0 << '\n';
                        cout << m-1 << ' ' << i << ' ' << 1 << '\n';
                        cout << m-1 << ' ' << i << ' ' << 0 << '\n';
                    }
                }
        }
        for(int i = m; i >= 1; i--){
            cout << i << ' ' << 1 << ' ' << 1 << '\n';
            cout << i << ' ' << 1 << ' ' << 0 << '\n';
        }
    }else if(m%2){
        for(int i = 1; i <= m-2; i++){
            for(int j=2;j<=n;j++){
                if(i%2 == 1){
                    cout << i << ' ' << j << ' ' << 0 << '\n';
                    cout << i << ' ' << j << ' ' << 1 << '\n';
                }else{
                    if(j % 2){
                        cout << i << ' ' << n-j+2 << ' ' << 1 << '\n';
                        cout << i << ' ' << n-j+2 << ' ' << 0 << '\n';
                    }else{
                        cout << i << ' ' << n-j+2 << ' ' << 0 << '\n';
                        cout << i << ' ' << n-j+2 << ' ' << 1 << '\n';
                    }
                }
            }
        }
        for(int i=n; i>=2;i--){
                if(i % n == 0){
                    cout << m-1 << ' ' << i << ' ' << 0 << '\n';
                    cout << m-1 << ' ' << i << ' ' << 1 << '\n';
                    cout << m << ' ' << i << ' ' << 1 << '\n';
                    cout << m << ' ' << i << ' ' << 0 << '\n';
                }else{
                    cout << m << ' ' << i << ' ' << 0 << '\n';
                    cout << m << ' ' << i << ' ' << 1 << '\n';
                    cout << m-1 << ' ' << i << ' ' << 0 << '\n';
                    cout << m-1 << ' ' << i << ' ' << 1 << '\n';
                }
        }
        for(int i = m; i >= 1; i--){
            cout << i << ' ' << 1 << ' ' << 1 << '\n';
            cout << i << ' ' << 1 << ' ' << 0 << '\n';
        }
    }else{
        for(int i = 1; i <= m; i++){
            for(int j=2;j<=n;j++){
                if(i%2 == 1){
                    cout << i << ' ' << j << ' ' << 0 << '\n';
                    cout << i << ' ' << j << ' ' << 1 << '\n';
                }else{
                    if(j % 2){
                        cout << i << ' ' << n-j+2 << ' ' << 1 << '\n';
                        cout << i << ' ' << n-j+2 << ' ' << 0 << '\n';
                    }else{
                        cout << i << ' ' << n-j+2 << ' ' << 0 << '\n';
                        cout << i << ' ' << n-j+2 << ' ' << 1 << '\n';
                    }
                }
            }
        }
        for(int i = m; i >= 1; i--){
            cout << i << ' ' << 1 << ' ' << 1 << '\n';
            cout << i << ' ' << 1 << ' ' << 0 << '\n';
        }
    }
}