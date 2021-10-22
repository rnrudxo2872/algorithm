function solution(n, path, order) {
    let order1 = Array.from({length: n}, () => null);
    let order2 = Array.from({length: n}, () => null);
    
    for(let i = 0; i < order.length; ++i) {
        const [pre, after] = order[i];
        
        order1[pre] = after;
        order2[after] = pre;
    }
    
    let graph = Array.from({length: n}, () => []);
    for(let i = 0; i < path.length; ++i) {
        const [x1,x2] = path[i];
        
        graph[x1].push(x2);
        graph[x2].push(x1);
    }
    
    let visit = Array.from({length: n}, () => 0)
    let stack = [0];
    
    while(stack.length) {
        const node = stack.pop();
        
        if(order2[node] != null) {
            visit[node] = -1; // 대기
            continue;
        }
        
        visit[node] = 1;
        order2[order1[node]] = null;
        order1[node] = null;
        
        for(let i = 0; i < graph[node].length; ++i) {
            const next = graph[node][i];
            
            if(visit[next] === 1) continue;
            if(order1[next] != null) {
                if(visit[order1[next]] === -1) {
                    stack.push(order1[next]);
                }
                
                order2[order1[next]] = null;
                order1[next] = null;
            }
            stack.push(next);
        }
    }
    
    for(let i = 0; i < visit.length; ++i) {
        if(visit[i] !== 1) return false;
    }
    return true;
}