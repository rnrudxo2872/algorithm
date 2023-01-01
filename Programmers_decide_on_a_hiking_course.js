function solution(n, paths, gates, summits) {
    const graph = Array(n + 1).fill(1).map(() => []);
    for(let i = 0; i < paths.length; ++i) {
        const [start, end, w] = paths[i];
        
        graph[start].push([end, w]);
        graph[end].push([start, w]);
    }
    for(const summit of summits) {
        graph[summit] = [];
    }
    
    let pathWMap = Array(n + 1).fill(Infinity);
    let q = [];
    for(const gate of gates) {
        pathWMap[gate] = -1;
        q.push(gate);
    }
    
    
    while(q.length > 0) {
        const current = q.shift();
        
        for(const [next, w] of graph[current]) {
            const maxW = Math.max(w, pathWMap[current]);
            
            if(pathWMap[next] > maxW) {
                pathWMap[next] = maxW;
                q.push(next);
            }
        }
    }
    
    return summits.map(summit => [summit, pathWMap[summit]]).sort((a, b) => {
        if(a[1] === b[1]) {
            return a[0] - b[0];
        }
        return a[1] - b[1];
    })[0]
}