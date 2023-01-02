function solution(board, skill) {
    const row = board.length;
    const col = board[0].length;
    const prefixArr = Array.from({length: row + 1}, () => Array(col + 1).fill(0));
    
    for(const [type, r1, c1, r2, c2, degree] of skill) {
        const isAttack = type === 1;
        
        prefixArr[r1][c1] += isAttack ? -degree : degree;
        prefixArr[r1][c2 + 1] += isAttack ? degree : -degree;
        prefixArr[r2 + 1][c1] += isAttack ? degree : -degree;
        prefixArr[r2 + 1][c2 + 1] += isAttack ? -degree : degree;
    }
    
    let sum = 0;
    
    for(let i = 0; i < row + 1; i++) {
        sum = 0;
        
        for(let j = 0; j < col + 1; j++) {
            sum += prefixArr[i][j];
            prefixArr[i][j] = sum;
        }
    }
    
    for(let i = 0; i < col + 1; i++) {
        sum = 0;
        
        for(let j = 0; j < row + 1; j++) {
            sum += prefixArr[j][i];
            prefixArr[j][i] = sum;
        }
    }
    
    let answer = 0;
    for(let i = 0; i < row; i++) {
        for(let j = 0; j < col; j++) {
            board[i][j] > -prefixArr[i][j] && answer++;
        }
    }
    
    return answer;
}