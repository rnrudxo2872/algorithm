function bfs(edge) {
    let visit = Array.from({length:edge[0].length+1}, () => false);
    let Q = [1];
    let ret = 1;
    visit[1] = true;
    
    while(Q.length > 0) {
        let curVal = Q.shift();
        
        for(let i = 0; i < edge[curVal].length; i++) {
            if(!visit[i] && edge[curVal][i]) {
                visit[i] = true;
                Q.push(i);
                ret++;
            }
        }
    }
    
    return ret;
}

function solution(n, wires) {
    var answer = Number.MAX_VALUE;
    let edge = [];
    for(let i = 0 ; i < n + 1; i++) edge[edge.length] = Array.from({length:n+1},() => false);
    
    for(let i = 0; i < wires.length; i++) {
        const [e1,e2] = wires[i];
        edge[e1][e2] = true;
        edge[e2][e1] = true;
    }
    
    for(let i = 0; i < wires.length; i++) {
        const [e1,e2] = wires[i];
        edge[e1][e2] = false;
        edge[e2][e1] = false;
        
        let section = bfs(edge)
        
        edge[e1][e2] = true;
        edge[e2][e1] = true;
        answer = answer > Math.abs(n - (2*section)) ? Math.abs(n - (2*section)) : answer;
    }
    
    return answer;
}