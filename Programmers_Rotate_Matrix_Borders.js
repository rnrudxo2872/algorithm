function solution(rows, columns, queries) {
    var answer = [];
    let board = [];
    
    for(let i = 0; i < rows + 1; i++) {
        let len = board.length;
        let base = i - 1;
        
        board[len] = []
        for(let j = 0; j < columns + 1; j++) {
            board[len][j] = base * columns + j;
        }
    }
    
    for(let i = 0; i < queries.length; i++) {
        const [y1, x1, y2, x2] = queries[i];
        let stack = [];
        
        for(let i = x1; i < x2; ++i) stack.push(board[y1][i]);
        for(let i = y1; i < y2; ++i) stack.push(board[i][x2]);
        for(let i = x2; i > x1; --i) stack.push(board[y2][i]);
        for(let i = y2; i > y1; --i) stack.push(board[i][x1]);
        
        answer.push(Math.min(...stack))
        stack.unshift(stack.pop());
        
        for(let i = x1; i < x2; ++i) board[y1][i] = stack.shift();
        for(let i = y1; i < y2; ++i) board[i][x2] = stack.shift();
        for(let i = x2; i > x1; --i) board[y2][i] = stack.shift();
        for(let i = y2; i > y1; --i) board[i][x1] = stack.shift();
    }
    
    return answer;
}