function bfs(board, first, flag) {
    const del = [[0, 1],[0, -1],[1, 0],[-1, 0]];
    const [i, j] = first;
    
    let max = {x: -1, y: -1};
    let min = {x: 51, y: 51};

    const location = [[i, j]];
    const q = [[i, j]];
    
    let flagNum = 1;
    
    while(q.length > 0) {
        const [x, y] = q.shift();

        max.x = Math.max(max.x, x);
        max.y = Math.max(max.y, y);
        min.x = Math.min(min.x, x);
        min.y = Math.min(min.y, y);

        for(const [delX, delY] of del) {

            const row = x + delX;
            const col = y + delY;

            if(row < 0 || col < 0) continue;    

            if(row >= board.length || col >= board.length) continue;

            if(board[row][col] === flag) continue;
            board[row][col] = flag;
            
            flagNum++;

            q.push([row, col]);
            location.push([row, col]);
        }
    }
    
    return ({ max, min, location, flagNum })
}

function GenSquareArr(arg, background, fill) {
    const result = [];
    
    for(const { max, min, location } of arg) {
        const width = max.y - min.y + 1;
        const height = max.x - min.x + 1;
        
        const size = width > height ? width : height;
        
        const tempBoard = Array.from({length: size}, () => Array(size).fill(background));
        for(const [row, col] of location) {
            tempBoard[row - min.x][col - min.y] = fill;
        }
        
        result.push(tempBoard);
    }
    return result;
}

function checkSquare(a, b) {
    const size = a.length;
    
    for(let i = 0; i < size; i++) {
        for(let j = 0; j < size; j++) {
            if(a[i][j] + b[i][j] !== 1) return false;
        }
    }
    return true;
}

function rotate(square) {
    let result = Array.from({length: square.length}, () => Array(square.length).fill(0));
    for(let i = 0; i < square.length; i++) {
        for(let j = 0; j < square[i].length; j++) {
            result[i][j] = square[square[i].length - 1 - j][i];
        }
    }
    return result;
}

function check(a, b) {
    let copyB = [...b];
    
    for(let k = 0; k < 4; k++) {
        if(checkSquare(a, copyB)) {
            return true
        };
        
        copyB = rotate(copyB);
    }
    return false;
}

function solution(gameBoard, table) {
    let answer = 0;
    
    const copyTable = [...table];
    const puzzle = [];
    for(let i = 0; i < copyTable.length; i++) {
        for(let j = 0; j < copyTable[i].length; j++) {
            if(copyTable[i][j] === 0) continue;
            copyTable[i][j] = 0;
            
            const result = bfs(copyTable, [i,j], 0);
            puzzle.push(result);
        }
    }
    
    const copyGameBoard = [...gameBoard];
    const emptyBoard = [];
    for(let i = 0; i < copyGameBoard.length; i++) {
        for(let j = 0; j < copyGameBoard[i].length; j++) {
            if(copyGameBoard[i][j] === 1) continue;
            copyGameBoard[i][j] = 1;
            
            emptyBoard.push(bfs(copyGameBoard, [i,j], 1));
        }
    }
    
    const reGenPuzzle = GenSquareArr(puzzle, 0, 1);
    const reGenBoard = GenSquareArr(emptyBoard, 1, 0);
    
    const mutatePuzzle = reGenPuzzle.map((item,i ) => [item, puzzle[i].flagNum]);
    const sVisited = Array(reGenBoard.length).fill(false);
    const visited = Array(mutatePuzzle.length).fill(false);
    
    for(let j = 0; j < reGenBoard.length; j++) {
        const square = reGenBoard[j];
        
        for(let i = 0; i < mutatePuzzle.length; i++) {
            if(visited[i] || sVisited[j]) continue;
            
            const [puzzleSquare, value] = mutatePuzzle[i];
            if(puzzleSquare.length !== square.length) continue;
            
            if(check(square, puzzleSquare)) {
                
                answer += value;
                sVisited[j] = true;
                visited[i] = true;
                continue;
            }   
        }
    }
    
    return answer;
}