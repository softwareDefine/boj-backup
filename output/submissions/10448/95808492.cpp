#include <bits/stdc++.h>

using namespace std;

int tr[2000];

int t;

int main(){

	for(int i=1;i<=1000;i++){tr[i] = i*(i+1)/2;}	
    cin >> t;
    while(t--){

		int n;

		cin >> n;
        int i=0;
		for(i=1;i<=300;i++){

			for(int j=1;j<=300;j++){

				for(int k=1;k<=300;k++){

					if(n==tr[i]+tr[j]+tr[k]){

						i =1000;

						j = 1000;

						k = 1000;

					}

				}

			}

		}

		if(i==1001){

			cout << 1;

		}else{

			cout << 0;

		}

		cout << '\n';

	}

}