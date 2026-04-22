#include <bits/stdc++.h>

using namespace std;

int N,E;

int grid[25][25];

bool used[1000]; // 최대 N^2=25, 이보다 넉넉히

int magicSum;

vector<int> toFill; // 비어있는 칸 인덱스

int nSquared;

int filledCount = 0;

bool solveBacktrack(int idx, 

                    vector<int> &emptyCells, 

                    vector<int> &available, 

                    vector<int> &rowSum, 

                    vector<int> &colSum, 

                    int &diagSum1, 

                    int &diagSum2) {

    if (idx == (int)emptyCells.size()) {

        // 모두 채워짐

        // 최종적으로 rowSum, colSum, diagSum1, diagSum2 모두 magicSum이어야 함

        return true;

    }

    int cell = emptyCells[idx];

    int r = cell / N;

    int c = cell % N;

    for (int i = 0; i<(int)available.size(); i++){

        int val = available[i];

        if(val == -1) continue;

        int newRowSum = rowSum[r] + val;

        int newColSum = colSum[c] + val;

        

        // 가지치기: 

        // 만약 마지막 칸이 아닌데 이미 newRowSum>magicSum이면 불가능

        // 행이 다 찼으면 newRowSum == magicSum 이어야 함

        // 열도 마찬가지

        // 다각적인 가지치기 가능하지만 여기서는 기본 가지치기만

        // 해당 행이 마지막 칸이라면 이 행은 N칸 째인지를 체크

        // 빈칸이 몇 개 남았는지 세어볼 수도 있지만, 간단히 진행:

        

        // 행 완성여부 체크

        // 행에 몇 개의 빈칸이 남았는지 계산 귀찮으니 나중에 최종에서 검사하는 대신 

        // 매번 모든 행이 magicSum 넘어가진 않는지만 체크하자.

        if (newRowSum > magicSum || newColSum > magicSum) continue;

        // 대각선 체크

        int newDiagSum1 = diagSum1;

        int newDiagSum2 = diagSum2;

        if (r == c) {

            newDiagSum1 += val;

            if(newDiagSum1 > magicSum) continue;

        }

        if (r+c == N-1) {

            newDiagSum2 += val;

            if(newDiagSum2 > magicSum) continue;

        }

        // 할당

        grid[r][c] = val;

        int savedVal = available[i];

        available[i] = -1;

        int oldRowSum = rowSum[r];

        int oldColSum = colSum[c];

        int oldDiag1 = diagSum1;

        int oldDiag2 = diagSum2;

        rowSum[r] = newRowSum;

        colSum[c] = newColSum;

        diagSum1 = newDiagSum1;

        diagSum2 = newDiagSum2;

        if (solveBacktrack(idx+1,emptyCells,available,rowSum,colSum,diagSum1,diagSum2))

            return true;

        // 복구

        available[i] = savedVal;

        rowSum[r] = oldRowSum;

        colSum[c] = oldColSum;

        diagSum1 = oldDiag1;

        diagSum2 = oldDiag2;

    }

    return false;

}

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cin >> N >> E;

    nSquared = N*N;

    for (int i=0; i<N; i++) {

        for (int j=0; j<N; j++) {

            grid[i][j] = 0;

        }

    }

    // 읽기

    vector<bool> taken(nSquared+1,false);

    for (int i=0; i<E; i++){

        int R,C,V; cin>>R>>C>>V;

        R--;C--;

        grid[R][C] = V;

        taken[V] = true;

    }

    // 마방진 합

    magicSum = N*(nSquared+1)/2;

    // 사용안한 수 모으기

    vector<int> available;

    for (int v=1; v<=nSquared; v++){

        if(!taken[v]) available.push_back(v);

    }

    // 비어있는 칸 추적

    vector<int> emptyCells;

    for (int i=0; i<N; i++){

        for (int j=0; j<N; j++){

            if(grid[i][j]==0) emptyCells.push_back(i*N+j);

        }

    }

    // 초기 합

    vector<int> rowSum(N,0), colSum(N,0);

    int diagSum1=0, diagSum2=0;

    for (int i=0; i<N; i++){

        for (int j=0; j<N; j++){

            if(grid[i][j]!=0) {

                int val = grid[i][j];

                rowSum[i]+=val;

                colSum[j]+=val;

                if(rowSum[i]>magicSum || colSum[j]>magicSum){

                    // 이미 불가능

                    cout<<"no\n";

                    return 0;

                }

                if(i==j){

                    diagSum1+=val;

                    if(diagSum1>magicSum){

                        cout<<"no\n";

                        return 0;

                    }

                }

                if(i+j==N-1){

                    diagSum2+=val;

                    if(diagSum2>magicSum){

                        cout<<"no\n";

                        return 0;

                    }

                }

            }

        }

    }

    // 백트래킹 시도

    bool can = solveBacktrack(0,emptyCells,available,rowSum,colSum,diagSum1,diagSum2);

    cout<<(can?"yes":"no")<<"\n";

    return 0;

}