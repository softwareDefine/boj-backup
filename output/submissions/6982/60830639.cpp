#include <iostream>

using ll = long long;
using namespace std;

int t;
string tree1, tree2;


pair<ll, ll> smallDnC1(int node, int depth) {
	//cout << "1 : " <<  node << '\n';
	if (tree1[node] == 'f') {
		return { 1024 / (1 << 2*depth) ,{node + 1} };
	}
	if (tree1[node] == 'e') {
		return { 0,{node + 1} };
	}
	pair <ll, ll> temp;
	ll szze = 0, nx = 0;
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			temp = smallDnC1(node + 1, depth + 1);
			szze += temp.first;
			nx = temp.second;
		}
		else {
			temp = smallDnC1(nx, depth + 1);
			szze += temp.first;
			nx = temp.second;
		}
	}
	return { szze,nx};
}
pair<ll, ll> smallDnC2(int node, int depth) {
	//cout << "2 : " << node << '\n';
	if (tree2[node] == 'f') {
		return { 1024 / (1 << depth*2) ,{node + 1} };
	}
	if (tree2[node] == 'e') {
		return { 0,{node + 1} };
	}
	pair <ll, ll> temp;
	ll szze = 0, nx = 0;
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			temp = smallDnC2(node + 1, depth + 1);
			szze += temp.first;
			nx = temp.second;
		}
		else {
			temp = smallDnC2(nx, depth + 1);
			szze += temp.first;
			nx = temp.second;
		}
	}
	return { szze,nx };
}

pair<ll,pair<ll,ll>> DnC(int node1,int node2, int depth) {
	//cout << node1 << ' ' << node2 << '\n';
	pair <ll, pair<ll, ll>> temp;
	ll szze = 0, nx1 = 0, nx2 = 0;
	if (tree1[node1] == 'f' || tree2[node2] == 'f') {
		if ((tree1[node1] == 'f' || tree1[node1] == 'e') && (tree2[node2] == 'f' || tree2[node2] == 'e')) {
			return { 1024 / (1 << depth * 2) ,{node1 + 1,node2 + 1} };
		}
		else if (tree2[node2] == 'f') {
			pair<ll, ll> temp = smallDnC1(node1, depth);
			return { 1024 / (1 << depth * 2) ,{temp.second,node2 + 1} };
		}
		else {
			pair<ll, ll> temp = smallDnC2(node2, depth);
			return { 1024 / (1 << depth * 2) ,{node2 + 1,temp.second} };
		}
	}
	if (tree1[node1] == 'p' && tree2[node2] == 'e') {
		pair<ll, ll> temp = smallDnC1(node1, depth);
		return { temp.first ,{temp.second,node2+1} };
	}
	else if (tree1[node1] == 'e' && tree2[node2] == 'p') {
		pair<ll, ll> temp = smallDnC2(node2, depth);
		return { temp.first ,{node1 + 1, temp.second} };
	}
	else if (tree1[node1] == 'e' && tree2[node2] == 'e') {
		return { 0,{node1 + 1,node2 + 1} };
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				temp =  DnC(node1 + 1, node2 + 1, depth + 1);
				szze += temp.first;
				nx1 = temp.second.first;
				nx2 = temp.second.second;
			}
			else {
				temp = DnC(nx1, nx2, depth+1 );
				szze += temp.first;
				nx1 = temp.second.first;
				nx2 = temp.second.second;
			}
		}
	}
	return { szze,{nx1+1,nx2+1}};
}


int main()
{
	cin >> t;
	while (t--) {
		cin >> tree1;
		cin >> tree2;
		cout << "There are " << DnC(0, 0, 0).first << " black pixels." << '\n';
	}
}