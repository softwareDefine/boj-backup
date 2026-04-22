#include <cstdio>
#include <algorithm>
int n=0;
int a[1000000]={0};
int sum=-999999999;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);		
	}
	sort(a, a+n);
	for(int j=0;j<n;j++){
		if(a[j]*(n-j)>sum){
			sum=a[j]*(n-j);
		}
	}
	printf("%d",sum);
	return 0;
}