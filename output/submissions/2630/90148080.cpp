#include<iostream>

using namespace std;

int n;

int arr[200][200];

pair<int,int> thing;

void DnC(int x,int y, int n){

	if(n==0){return;}	int cnt =0;

	for(int i=x;i<x+n;i++){

		for(int j=y;j<y+n;j++){

			if(arr[i][j]){

				cnt++;

			}

		}

	}

	if(cnt==0) {thing.second++;}

	else if(cnt==n*n){thing.first++;}

	else{

		DnC(x+n/2,y+n/2,n/2);

		DnC(x,y+n/2,n/2);

		DnC(x+n/2,y,n/2);

		DnC(x,y,n/2);

	}

}

int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	cin >> n;

	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++){

			cin >> arr[i][j];

		}

	}

	DnC(1,1,n);

	cout << thing.first << '\n' << thing.second;

}