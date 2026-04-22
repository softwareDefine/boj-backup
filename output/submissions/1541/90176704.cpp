#include <bits/stdc++.h>

using namespace std;

char a[50];
string num;
int allsum;
int cnt = 0;
int inminu;

int main(){
	scanf("%s", a);
	int size = strlen(a);
	for (int i = 0; i <= size; i++){
		if (a[i] == '-' || a[i] == '+' || i== size){
			if (inminu){
				allsum -= stoi(num);
				num = "";
			}
			else{
				allsum += stoi(num);
				num = "";
			}
		}
		else{
			num += a[i];
		}
		if (a[i]=='-'){
			inminu = 1;
		}
	}
	printf("%d", allsum);
}