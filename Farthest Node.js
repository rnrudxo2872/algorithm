let answer = 0;
let maxLen = 0;
let conn;
let visit;

const bfs = (start) => {
    const Q = [];
    Q.push(start);
    visit[start.num] = true;
    
    while(Q.length > 0){
        const curNode = Q.shift();
        const curNum = curNode.num;
        const curLen = curNode.len;
        
        if(maxLen === curLen){
            answer++;
        }
        
        if(maxLen < curLen){
            answer = 1;
            maxLen = curLen;
        }
        
        for(var i = 0; i < conn[curNum].length ; ++i){
            let nNum = conn[curNum][i];
            
            if(visit[nNum])
                continue;
            
            Q.push({num:nNum,len:curLen+1})
            visit[nNum] = true;
        }
    }
}

function solution(n, edge) {
    conn = Array.from({length:n+1}, () => []);
    visit = Array.from({length:n+1},() => false);
    
    for(var i = 0; i < edge.length; ++i){
        const A = edge[i][0];
        const B = edge[i][1];
        
        conn[A].push(B);
        conn[B].push(A);
    }
            
    bfs({num:1, len:0});
    
    return answer;
}