#include <bits/stdc++.h>

using lint = long long;
using namespace std;

class Point{
  public:
    lint x, y;
    friend istream& operator>>(istream& is, Point& p){
        return is >> p.x >> p.y;
    }
    bool operator >(Point b){
        if(this->x == b.x){
            return this->y >= b.y;
        }
        return (this->x >= b.x);
    }
    bool operator <(Point b){
        if(this->x == b.x){
            return this->y <= b.y;
        }
        return (this->x <= b.x);
    }
};

class Line{
  public:
    Point u, v;
    friend istream& operator>>(istream& is, Line& l){
        return is >> l.u >> l.v;
    }
};

int ccw(Point a, Point b, Point c) {
	lint res = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
	return (res > 0) - (res < 0);
}

bool cross(Line a, Line b) {
	int ab = ccw(a.u, a.v, b.u)*ccw(a.u, a.v, b.v);
	int cd = ccw(b.u, b.v, a.u)*ccw(b.u, b.v, a.v);
	if (ab == 0 && cd == 0) {
		if (a.u > a.v) { swap(a.u, a.v); }
		if (b.u > b.v) { swap(b.u, b.v); }
		return !(a.v < b.u || a.u > b.v);
	}
	return ab <= 0 && cd <= 0;
}

int m, n;
int k;

Point s, e;

vector<Line> bus;
vector<int> edge[6000];

queue<pair<int,int>> qu;
int endSecure[6000];
bool visited[6000];

int main(){
    cin >> m >> n;
    cin >> k;
    bus.resize(k);
    for(auto &e : bus){
        int lineNumber;
        cin >> lineNumber >> e;
    }
    cin >> s >> e;
    for(int i = 0; i < k; i++){
        if(ccw(bus[i].u, bus[i].v, s) == 0){
            qu.push({i,0});
            visited[i] = 1;
        }
        if(ccw(bus[i].u, bus[i].v, e) == 0){
            endSecure[i] = 1;
        }
        for(int j = 0; j < k; j++){
            if(i == j){ continue; }
            if(cross(bus[i], bus[j])){
                edge[i].push_back(j);
            }
        }
    }
    while(!qu.empty()){
        auto [now, cnt] = qu.front();
        qu.pop();
        if(endSecure[now]){
            cout << cnt + 1;
            return 0;
        }
        for(auto &next : edge[now]){
            if(!visited[next]){
                qu.push({next, cnt+1});
                visited[next] = 1;
            }
        }
    }
}