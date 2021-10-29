function calculateBoard(board) {
    let lastNum = ((board.length - 1) * board.length) / 2;
    let curNum = 1;
    let trigger = 0;
    let row = 0;
    let col = 1;
    let res = 0;

    while(curNum <= lastNum) {
        switch(trigger) {
            case 0:
                row++
                for(let i = 1; i < board.length - res; ++i) {
                    board[row++][col] = curNum++;
                }
                trigger = 1;
                break;
            case 1:
                row--;
                for(let i = 1; i < board.length - res - 1; ++i) {
                    board[row][++col] = curNum++;
                }
                trigger = 2;
                break;
            case 2:
                for(let i = 1; i < board.length - res - 2 ; ++i) {
                    board[--row][--col] = curNum++;
                }
                trigger = 0;
                res += 3;
                break;
        }
    }
}

function solution(n) {
    var answer = [];
    
    let board = [];
    for(let i = 0; i < n + 1; ++i) board[board.length] = i === 0 ? [] : new Array(i+1);
    
    calculateBoard(board);
    
    for(let i = 1; i < board.length; ++i) {
        board[i].shift();
        answer = [...answer, ...board[i]];
    }
    return answer;
}