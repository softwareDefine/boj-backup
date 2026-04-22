#include <iostream>

using ll = long long;
using namespace std;

int n;
string str;
int arr[100010];
vector<pair<char,int>> vc;
int main(){
	cin >> n;
	cin >> str;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(vc.empty()){
			vc.push_back({str[i],arr[i]};
		}else if(vc[vc.size()-1].first == str[i]){
			if(vc[vc.size()-1].second < arr[i]){
				vc.pop_back();
				vc.push_back(arr[i]);
			}
		}else{
			vc.push_back(arr[i]);
		}
	}
	for(int i=1;i<vc.size();i++){
		if(vc[i])dd
	}
}