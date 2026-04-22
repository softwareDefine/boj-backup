#include <bits/stdc++.h>

using namespace std;
vector<int> row;
vector<int> column;

int r,c;
int n;
int dir,line;
int mmx = 0;

int main(){
	cin >> c >> r;
	cin >> n;
	row.push_back(0);
	column.push_back(0);
	for(int i=0;i<n;i++){
	    cin >> dir >> line;
		if(!dir){
		    row.push_back(line);
		}else{
		    column.push_back(line);
		}
	}
	row.push_back(r);
	column.push_back(c);
	sort(row.begin(),row.end());
	sort(column.begin(),column.end());
	for(int i=0;i<row.size()-1;i++){
	    for(int j=0;j<column.size()-1;j++){
	        mmx = max(mmx, (row[i+1]-row[i])*(column[j+1]-column[j]));
	    }
	}
	cout << mmx;
}