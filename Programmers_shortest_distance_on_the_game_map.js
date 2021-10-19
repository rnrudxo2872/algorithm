let visit;
let MAP;
let delPos = [[0,1],[0,-1],[1,0],[-1,0]];

function isValid(r,c) { 
    if(MAP.length - 1 < r || r < 0 || MAP[0].length - 1 < c || c < 0) return false;
    if(visit[r][c]) return false;
    if(MAP[r][c] === 0) return false;
    
    return true;
}

function bfs() {
    let Q = [[0,0,1]];
    visit[0][0] = true;
    
    while(Q.length > 0) {
        let [r,c,cnt] = Q.shift();
        if(r === MAP.length - 1 && c === MAP[0].length - 1) return cnt;
        
        for(let i = 0; i < 4; ++i) {
            let nR = r + delPos[i][0];
            let nC = c + delPos[i][1];
            
            if(!isValid(nR,nC)) continue;
            
            visit[nR][nC] = true;
            Q.push([nR,nC,cnt+1]);
        }
    }
    return -1;
}

function solution(maps) {
    visit = Array.from({length:maps.length}, () => Array.from({length:maps[0].length}, () => false));
    MAP = maps;
    
    return bfs();
}