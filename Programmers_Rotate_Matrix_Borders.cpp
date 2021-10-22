#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int board[rows+1][columns+1];
    
    for(int i = 0; i < rows; i++) {
        int base = columns * i;
        
        for(int j = 1; j < columns + 1; j++) {
            board[i][j] = base + j;
        }
    }
    
    for(int i = 0; i < queries.size(); i++) {
        vector<int> stack;
        
        int x1 = queries[i][0] - 1;
        int y1 = queries[i][1];
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3];
        
        for(int k = y1; k < y2; k++) stack.push_back(board[x1][k]);
        for(int k = x1; k < x2; k++) stack.push_back(board[k][y2]);
        for(int k = y2; k > y1; k--) stack.push_back(board[x2][k]);
        for(int k = x2; k > x1; k--) stack.push_back(board[k][y1]);
        
        int tail = stack[stack.size()-1];
        int min_tail = tail;
        stack.pop_back();
        
        for(int k = x1 + 1; k < x2; k++) {
            int tmp = stack[stack.size()-1];
            board[k][y1] = tmp;
            min_tail = min_tail > tmp ? tmp : min_tail;
            stack.pop_back();
        }
        
        for(int k = y1; k < y2; k++) {
            int tmp = stack[stack.size()-1];
            board[x2][k] = tmp;
            min_tail = min_tail > tmp ? tmp : min_tail;
            stack.pop_back();
        }
        
        for(int k = x2; k > x1; k--) {
            int tmp = stack[stack.size()-1];
            board[k][y2] = tmp;
            min_tail = min_tail > tmp ? tmp : min_tail;
            stack.pop_back();
        }
        
        for(int k = y2; k > y1; k--) {
            int tmp = stack[stack.size()-1];
            board[x1][k] = tmp;
            min_tail = min_tail > tmp ? tmp : min_tail;
            stack.pop_back();
        }
        
        board[x1][y1] = tail;
        answer.push_back(min_tail);
    }
    
    return answer;
}