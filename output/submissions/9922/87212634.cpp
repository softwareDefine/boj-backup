#include <bits/stdc++.h>

using namespace std;

int N,E;

int nSquared;

int magicSum;

int grid[25][25];

bool used[1000];

int rowSum[25], colSum[25];

int diagSum1, diagSum2;

// 남은 수 관리

// available: 남은 수들을 오름차순 정렬

// prefixSum: available의 prefix sum, min/max 합 계산에 사용

vector<int> available;

vector<long long> prefixSum;

// 빈 칸 리스트

struct Cell {

    int r,c;

    vector<int> candidates; // 이 칸에 들어갈 수 있는 후보 수

};

vector<Cell> emptyCells;

bool finalizeForcing(); // 강제 결정 수행

bool solveBacktrack();

bool updateDomains(); // 도메인 업데이트(강제결정, 가지치기)

// 남은 수로 만들 수 있는 최소합, 최대합 계산

inline long long getMinSum(int k) {

    // 남은 수 중 가장 작은 k개의 합

    // available가 오름차순

    if (k == 0) return 0;

    return prefixSum[k-1];

}

inline long long getMaxSum(int k) {

    // 남은 수 중 가장 큰 k개의 합

    // 가장 큰 k개는 끝에서 k개

    // prefixSum.back() - prefixSum[available.size()-k-1]

    int sz=(int)available.size();

    if (k == 0) return 0;

    return (prefixSum.back() - (sz-k-1>=0?prefixSum[sz-k-1]:0));

}

// min/max 가지치기

bool canCompleteLine(int currentSum, int cellsLeft) {

    // cellsLeft개의 칸으로 currentSum을 magicSum으로 맞출 수 있는지

    // 남은 수 중 cellsLeft개를 골라 (minSum <= target- currentSum <= maxSum)인지 검사

    long long need = magicSum - currentSum;

    // 최소합 <= need <= 최대합 이어야 함

    if (cellsLeft < 0 || cellsLeft > (int)available.size()) return false;

    long long mn = getMinSum(cellsLeft);

    long long mx = getMaxSum(cellsLeft);

    return (mn <= need && need <= mx);

}

bool checkAllLinesFeasible() {

    // 각 행/열/대각선에 대해, 남은 빈칸 수 파악 후 min/max 확인

    vector<int> rowEmpty(N,0), colEmpty(N,0);

    int d1Empty=0, d2Empty=0;

    // 빈칸 수 계산

    for (auto &cell: emptyCells) {

        if (grid[cell.r][cell.c]==0) {

            rowEmpty[cell.r]++;

            colEmpty[cell.c]++;

            if (cell.r == cell.c) d1Empty++;

            if (cell.r+cell.c==N-1) d2Empty++;

        }

    }

    for (int i=0; i<N; i++) {

        if (!canCompleteLine(rowSum[i], rowEmpty[i])) return false;

        if (!canCompleteLine(colSum[i], colEmpty[i])) return false;

    }

    if (!canCompleteLine(diagSum1,d1Empty)) return false;

    if (!canCompleteLine(diagSum2,d2Empty)) return false;

    return true;

}

// 강제 결정 적용

// 행(열, 대각선)에 N-1칸 채워졌으면 마지막 한 칸에 필수적으로 들어갈 값 결정

bool finalizeForcing() {

    bool changed = false;

    // 행

    vector<int> rowLeft(N,0), colLeft(N,0);

    vector<int> dleft(2,0); // diag

    // 빈칸 위치 추적

    // 각 행, 열, 대각선 남은칸 위치, 한 칸 남으면 강제결정

    vector<int> rowEmptyIdx(N,-1), colEmptyIdx(N,-1);

    int d1EmptyIdx=-1, d2EmptyIdx=-1;

    for (int i=0;i<N;i++){

        for (int j=0;j<N;j++){

            if (grid[i][j]==0) {

                rowLeft[i]++;

                colLeft[j]++;

                if (i==j) dleft[0]++;

                if (i+j==N-1) dleft[1]++;

            }

        }

    }

    // 행 강제결정

    for (int r=0; r<N; r++){

        if (rowLeft[r]==1) {

            // 마지막 한 칸 찾기

            int cpos=-1; 

            for (int j=0;j<N;j++){

                if (grid[r][j]==0){ cpos=j; break; }

            }

            int need = magicSum - rowSum[r];

            // need가 available에 있어야 함

            auto it = find(available.begin(), available.end(), need);

            if (it==available.end()) return false; // 불가능

            // 배치

            grid[r][cpos]=need;

            rowSum[r]+=need; colSum[cpos]+=need;

            if (r==cpos) diagSum1+=need;

            if (r+cpos==N-1) diagSum2+=need;

            available.erase(it);

            prefixSum.clear();

            prefixSum.resize(available.size());

            for (int i=0;i<(int)available.size();i++){

                prefixSum[i]=available[i]+(i>0?prefixSum[i-1]:0);

            }

            changed=true;

        }

    }

    // 열 강제결정

    for (int c=0; c<N; c++){

        if (colLeft[c]==1) {

            int rpos=-1;

            for (int i=0;i<N;i++){

                if (grid[i][c]==0){ rpos=i; break;}

            }

            int need = magicSum - colSum[c];

            auto it = find(available.begin(), available.end(), need);

            if (it==available.end()) return false;

            grid[rpos][c]=need;

            rowSum[rpos]+=need; colSum[c]+=need;

            if (rpos==c) diagSum1+=need;

            if (rpos+c==N-1) diagSum2+=need;

            available.erase(it);

            prefixSum.clear();

            prefixSum.resize(available.size());

            for (int i=0;i<(int)available.size();i++){

                prefixSum[i]=available[i]+(i>0?prefixSum[i-1]:0);

            }

            changed=true;

        }

    }

    // 대각선 강제결정

    // 주대각선

    if (dleft[0]==1) {

        int rpos=-1,cpos=-1;

        for (int i=0;i<N;i++){

            if (grid[i][i]==0) {rpos=i;cpos=i;break;}

        }

        int need = magicSum - diagSum1;

        auto it = find(available.begin(), available.end(), need);

        if (it==available.end()) return false;

        grid[rpos][cpos]=need;

        rowSum[rpos]+=need; colSum[cpos]+=need; diagSum1+=need;

        if (rpos+cpos==N-1) diagSum2+=need;

        available.erase(it);

        prefixSum.clear();

        prefixSum.resize(available.size());

        for (int i=0;i<(int)available.size();i++){

            prefixSum[i]=available[i]+(i>0?prefixSum[i-1]:0);

        }

        changed=true;

    }

    // 부대각선

    if (dleft[1]==1) {

        int rpos=-1,cpos=-1;

        for (int i=0;i<N;i++){

            int j=N-1-i;

            if (grid[i][j]==0){rpos=i;cpos=j;break;}

        }

        int need=magicSum - diagSum2;

        auto it = find(available.begin(), available.end(), need);

        if (it==available.end()) return false;

        grid[rpos][cpos]=need;

        rowSum[rpos]+=need; colSum[cpos]+=need; diagSum2+=need;

        if (rpos==cpos) diagSum1+=need;

        available.erase(it);

        prefixSum.clear();

        prefixSum.resize(available.size());

        for (int i=0;i<(int)available.size();i++){

            prefixSum[i]=available[i]+(i>0?prefixSum[i-1]:0);

        }

        changed=true;

    }

    if (changed) {

        // 강제결정 후에도 다시 불가능하지 않은지 체크

        if (!checkAllLinesFeasible()) return false;

        // 재귀적으로 계속 강제결정 시도 가능

        bool res = finalizeForcing();

        return res;

    }

    return true;

}

bool solveBacktrack() {

    // 모든 칸이 채워졌는지 확인

    {

        bool done=true;

        for (int i=0;i<N;i++){

            for (int j=0;j<N;j++){

                if (grid[i][j]==0) {done=false;break;}

            }

            if(!done) break;

        }

        if(done){

            // 최종검증

            for (int i=0; i<N; i++){

                if (rowSum[i]!=magicSum) return false;

                if (colSum[i]!=magicSum) return false;

            }

            if (diagSum1!=magicSum||diagSum2!=magicSum) return false;

            return true;

        }

    }

    // 가장 후보가 적은 칸 선택

    // 칸별 후보 계산 (여기서는 후보를 계산하지 않고, brute하게 available 순회)

    int best=-1;

    int bestSize=10000;

    for (int i=0;i<N;i++){

        for (int j=0;j<N;j++){

            if (grid[i][j]==0) {

                // 가능한 후보 계산

                int countCandidates=0;

                for (auto v: available) {

                    // 간단히 min/max 합 조건으로 prune하지 않고 그냥 후보 파악

                    // 여기서는 단순히 v넣었을 때 immediate 불가여부로 측정

                    // 더 정교하려면 실제로 넣었을 때 가능한지 체크 필요

                    countCandidates++;

                }

                if (countCandidates < bestSize) {

                    bestSize = countCandidates;

                    best = i*N+j;

                }

            }

        }

    }

    int r=best/N;

    int c=best%N;

    // 후보를 실제로 시도

    for (int i=0; i<(int)available.size(); i++){

        int val=available[i];

        int oldRow=rowSum[r], oldCol=colSum[c], oldD1=diagSum1, oldD2=diagSum2;

        if (oldRow+val>magicSum || oldCol+val>magicSum) continue;

        if (r==c && oldD1+val>magicSum) continue;

        if (r+c==N-1 && oldD2+val>magicSum) continue;

        // 넣어보고

        grid[r][c]=val;

        rowSum[r]+=val; colSum[c]+=val;

        if (r==c) diagSum1+=val;

        if (r+c==N-1) diagSum2+=val;

        int saveVal=val;

        available.erase(available.begin()+i);

        prefixSum.clear();

        prefixSum.resize(available.size());

        for (int k=0;k<(int)available.size();k++) prefixSum[k]=available[k]+(k>0?prefixSum[k-1]:0);

        if (!checkAllLinesFeasible()) {

            // 복구

            available.insert(available.begin()+i,saveVal);

            grid[r][c]=0;

            rowSum[r]=oldRow;colSum[c]=oldCol;diagSum1=oldD1;diagSum2=oldD2;

            continue;

        }

        if (finalizeForcing()) {

            if (solveBacktrack()) return true;

        }

        // 복구

        available.insert(available.begin()+i,saveVal);

        grid[r][c]=0;

        rowSum[r]=oldRow;colSum[c]=oldCol;diagSum1=oldD1;diagSum2=oldD2;

    }

    return false;

}

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cin>>N>>E;

    nSquared=N*N;

    for (int i=0;i<N;i++){

        for (int j=0;j<N;j++){

            grid[i][j]=0;

        }

    }

    vector<bool> taken(nSquared+1,false);

    for(int i=0;i<E;i++){

        int R,C,V; cin>>R>>C>>V;

        R--;C--;

        grid[R][C]=V;

        taken[V]=true;

    }

    magicSum = N*(nSquared+1)/2;

    for (int i=0;i<N;i++){

        rowSum[i]=0; colSum[i]=0;

    }

    diagSum1=0; diagSum2=0;

    // 초기합 체크

    for (int i=0;i<N;i++){

        for (int j=0;j<N;j++){

            int val=grid[i][j];

            if(val!=0) {

                rowSum[i]+=val; colSum[j]+=val;

                if (i==j) diagSum1+=val;

                if (i+j==N-1) diagSum2+=val;

                if (rowSum[i]>magicSum||colSum[j]>magicSum||diagSum1>magicSum||diagSum2>magicSum) {

                    cout<<"no\n";

                    return 0;

                }

            }

        }

    }

    for (int v=1; v<=nSquared; v++){

        if(!taken[v]) available.push_back(v);

    }

    sort(available.begin(), available.end());

    prefixSum.resize(available.size());

    for (int i=0;i<(int)available.size();i++){

        prefixSum[i]=available[i]+(i>0?prefixSum[i-1]:0);

    }

    // 초기 강제결정 수행

    if(!checkAllLinesFeasible()) {

        cout<<"no\n";

        return 0;

    }

    if(!finalizeForcing()) {

        cout<<"no\n";

        return 0;

    }

    bool can=solveBacktrack();

    cout<<(can?"yes":"no")<<"\n";

    return 0;

}