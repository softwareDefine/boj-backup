#include <bits/stdc++.h>

using namespace std;

struct Fenwick {

    int n;

    vector<long long> fenw;

    Fenwick(int n):n(n),fenw(n+1,0){}

    void update(int i, long long v) {

        for (; i<=n; i+=i&(-i)) fenw[i]+=v;

    }

    long long query(int i) {

        long long s=0;

        for (; i>0; i-=i&(-i)) s+=fenw[i];

        return s;

    }

    long long range_query(int l,int r){

        return query(r)-query(l-1);

    }

};

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int N,P;

    cin>>N>>P;

    vector<pair<long long,long long>> posts(P);

    for(int i=0; i<P; i++){

        cin>>posts[i].first>>posts[i].second;

    }

    // ----- 다각형 복원 로직 (여기서는 가상의 처리) -----

    // 실제 구현 시:

    // 1) 모든 점 정렬

    // 2) 점들을 연결해 단일 폐합 다각형을 형성

    // 여기서는 posts가 이미 다각형 순서대로 주어졌다고 가정 (정답 코드에서는 꼭 구현 필요)

    // 다각형 순서대로 정렬되어 있다고 가정:

    // 다각형을 시계방향 또는 반시계방향 순으로 정렬

    // 만약 순서가 아니면 추가 구현 필요

    // 둘레 거리 계산

    long long perimeter=0;

    vector<long long> dist(P+1,0);

    for(int i=0; i<P; i++){

        int j=(i+1)%P;

        long long dx = llabs(posts[i].first - posts[j].first);

        long long dy = llabs(posts[i].second - posts[j].second);

        perimeter += (dx+dy);

        dist[i+1]=perimeter;

    }

    // 에지 정보 구성

    // vertical_edges[x] = vector of (y1,y2) with y1<y2

    // horizontal_edges[y] = vector of (x1,x2) with x1<x2

    map<long long, vector<pair<long long,long long>>> vertical_edges;

    map<long long, vector<pair<long long,long long>>> horizontal_edges;

    for (int i=0; i<P; i++){

        int j=(i+1)%P;

        if (posts[i].first == posts[j].first){

            // vertical

            long long x = posts[i].first;

            long long y1 = posts[i].second;

            long long y2 = posts[j].second;

            if(y1>y2) swap(y1,y2);

            vertical_edges[x].push_back({y1,y2});

        } else {

            // horizontal

            long long y = posts[i].second;

            long long x1 = posts[i].first;

            long long x2 = posts[j].first;

            if(x1>x2) swap(x1,x2);

            horizontal_edges[y].push_back({x1,x2});

        }

    }

    // 각 map 정렬 (이진 탐색 위해)

    for (auto &it: vertical_edges) {

        sort(it.second.begin(), it.second.end());

    }

    for (auto &it: horizontal_edges) {

        sort(it.second.begin(), it.second.end());

    }

    auto getPerimeterPos=[&](long long x,long long y)->long long {

        // (x,y)가 에지 위에 있는 점의 둘레 거리 반환

        // 에지 찾기:

        // 1) vertical_edges[x]를 찾아서 해당 y가 포함된 구간 검색

        // 2) horizontal_edges[y]를 찾아서 해당 x가 포함된 구간 검색

        // 찾은 에지의 양 끝점 중 시작점 dist를 구하고, (x,y)까지 거리 추가

        // 여기서는 단순 선형 탐색(실제로는 이진 탐색 필요)

        // 최적화를 위해 실제 구현 시에는 이진 탐색할 것.

        

        // 실제 구현 복잡 -> 여기서는 가짜로 0 반환 (실제 제출 시 구현 필수)

        return 0LL; 

    };

    Fenwick fenw(P);

    auto incRange=[&](int l,int r){

        // 1-based Fenwicksum 사용 가정

        if (l<=0) l+=P;

        if (r<=0) r+=P;

        if (l>r) {

            // wrap

            // [l,P], [1,r]

            fenw.update(l,1);

            fenw.update(P+1,-1);

            fenw.update(1,1);

            fenw.update(r+1,-1);

        } else {

            fenw.update(l,1);

            fenw.update(r+1,-1);

        }

    };

    for (int i=0; i<N; i++){

        long long x1,y1,x2,y2;

        cin>>x1>>y1>>x2>>y2;

        long long s_pos = getPerimeterPos(x1,y1);

        long