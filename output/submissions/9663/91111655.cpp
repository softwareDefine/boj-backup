#include <iostream>
#include <vector>
using namespace std;

int n;
long long cnt = 0;

// (r, c)에 퀸을 놓았을 때, 해당 퀸이 공격하는 칸들을 2로 표시하는 함수
void markAttacks(vector<vector<int>>& board, int r, int c) {
    int N = board.size();
    // 해당 행 전체 (퀸이 있는 칸은 그대로 1)
    for (int j = 0; j < N; j++)
        if(board[r][j] == 0) board[r][j] = 2;
    
    // 해당 열 전체
    for (int i = 0; i < N; i++)
        if(board[i][c] == 0) board[i][c] = 2;
    
    // 대각선 방향들 (4방향)
    // 좌상향
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 0) board[i][j] = 2;
    
    // 우상향
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
        if(board[i][j] == 0) board[i][j] = 2;
    
    // 좌하향
    for (int i = r, j = c; i < N && j >= 0; i++, j--)
        if(board[i][j] == 0) board[i][j] = 2;
    
    // 우하향
    for (int i = r, j = c; i < N && j < N; i++, j++)
        if(board[i][j] == 0) board[i][j] = 2;
}

// row 행에 퀸을 놓기 위한 재귀 함수
// 현재까지의 board 상태를 값으로 전달(복사)하여 이전 상태에 영향을 주지 않도록 함
void solve(int row, vector<vector<int>> board) {
    if(row == n) {  // 모든 행에 퀸을 놓았다면 하나의 해 발견
        cnt++;
        return;
    }
    
    // row 행의 각 열을 탐색
    for (int col = 0; col < n; col++){
        // 해당 칸이 0이면 (즉, 공격받지 않는다면) 퀸을 놓을 수 있음
        if(board[row][col] == 0){
            vector<vector<int>> newBoard = board; // 현재 상태 복사
            newBoard[row][col] = 1;                // 퀸을 놓음 (1로 표시)
            markAttacks(newBoard, row, col);       // 해당 퀸이 공격하는 칸들을 2로 표시
            solve(row + 1, newBoard);              // 다음 행으로 진행
        }
    }
}

int main(){
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0)); // n x n 체스판 초기화 (모두 0)
    solve(0, board);
    cout << cnt;
    return 0;
}
