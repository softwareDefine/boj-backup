#include <stack>
#include <cstdio>

using namespace std;

int a=0,b[1000000],mi;

int main(){
	stack<int>st;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
	scanf("%d",&b[i]);
	if(b[i]==0) st.pop();
	else st.push(b[i]);	
	}
	while(st.size()!=0){
		mi=mi+st.top();
		st.pop();	
	}
	printf("%d",mi);

	return 0;
}