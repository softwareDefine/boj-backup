#include <iostream>
#include <math.h>

using namespace std;

pair<int,int> pr[17];

double w[17][17];

double dp[17][17][65536];

int n;

double mmn = 99999999;

int main(){

	cin >> n;	for(int i=0;i<n;i++){

		cin >> pr[i].first >> pr[i].second;

	}

	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){

			for(int k=0;k<(1<<n);k++){

				dp[i][j][k] = 99999999;

			}

			w[i][j] = sqrt((pr[i].first-pr[j].first)*(pr[i].first-pr[j].first) +  (pr[i].second-pr[j].second)*(pr[i].second-pr[j].second));

		}

		dp[i][i][0] = 0;

		dp[i][i][(1<<i)] = 0;

	}

	for(int i=0;i<n;i++){

		for(int k=0;k<(1<<n);k++){

		for(int j=0;j<n;j++){

			if((k & (1<<j))==0){

			for(int s=0;s<n;s++){

				if(!w[s][j]){ continue; }

				dp[i][j][k|(1<<j)] = min(dp[i][j][k|(1<<j)],dp[i][s][k]+w[s][j]);

				}

			}

		}

		}

	}

	for(int i=0;i<n;i++){

	//	cout << dp[i][i][(1<<n)-1];

		mmn = min(dp[i][i][(1<<n)-1],mmn);

	//	printf("%.6lf\n",sq);

	}

	printf("%.6lf\n",mmn);

}