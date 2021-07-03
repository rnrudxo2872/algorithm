let Board;
let Q = [];
let visit;
let answer = 25 * 25 * 700;

const delPoint = [[0,-1],[1,0],[0,1],[-1,0]];

function isValid(x,y,cost){
    if(Board.length - 1 < x || x < 0 || Board[0].length - 1 < y || y < 0){
        return false;
    }
    if(visit[y][x] !== 0 && visit[y][x] < cost){
        return false;
    }
    if(Board[y][x] === 1){
        return false;
    }
    return true;
}

function BFS() {
    while(Q.length > 0){
        const curNode = Q.shift();
        const curCost = curNode.cost;
        const curDir = curNode.dir;
        const curX = curNode.x;
        const curY = curNode.y;
        
        if(curY === Board.length - 1 && curX === Board[0].length - 1){
            answer = answer > curCost ? curCost : answer;
            continue;
        }
        
        for(var i = 0; i < 4; ++i){
            const nX = curX + delPoint[i][0];
            const nY = curY + delPoint[i][1];
            let nCost = curCost;
            let nDir = i;
            
            if(curDir !== nDir){
                nCost += 600;
            }else{
                nCost += 100;
            }
            
            if(!isValid(nX,nY,nCost)){
                continue;
            }
            
            visit[nY][nX] = nCost;
            Q.push({
                cost:nCost,
                dir:nDir,
                x:nX,
                y:nY
            })
        }
        
    }
}

function solution(board) {
    
    Board = board;
    visit = Array.from(Array(board.length), () => Array(board[0].legnth).fill(0));
    
    //0 위, 1 오, 2 아래, 3 왼
    for(var i = 1; i < 3; i++){
        Q.push({
        cost:0,
        dir:i,
        x:0,
        y:0
        })
    }
    
    visit[0][0] = 0;
    
    BFS();
    
    return answer;
}