function isValid(a) {
    let sum = a.reduce((stack, val) => stack+val, 0);
    return sum === 0 ? true : false;
}

function getDicSize(target, n) {
    for(let i = 0; i < n.length; ++i) target[target.length] = [];    
    return target;
}

function setConnection(dic, edges) {
    for(let i = 0; i < edges.length; i++) {
        const [x1, x2] = edges[i];
        
        dic[x1].push(x2);
        dic[x2].push(x1);
    }
}

function getVisit(visit, a) {
    for(let i = 0; i < a.length; ++i) visit[visit.length] = false;
}

function dfs(dic, visit, a) {
    let stack = [[0,-1]];
    let ret = 0n;
    
    while(stack.length) {
        const [node, parent] = stack.pop();
        
        if(visit[node]) {
            ret += BigInt(Math.abs(a[node]));
            a[parent] += a[node];
            a[node] = 0;
            
            continue;
        }
        
        visit[node] = true;
        stack.push([node, parent]);
        
        for(let i = 0; i < dic[node].length; ++i) {
            if(visit[dic[node][i]]) continue;
            
            stack.push([dic[node][i], node]);
        }
    }
    
    return ret;
}

function solution(a, edges) {
    let dic = [];
    let visit = [];
    
    if(!isValid(a)) return -1;
    getDicSize(dic, a);
    getVisit(visit, a);
    setConnection(dic, edges);
    
    let answer = dfs(dic, visit, a)
    
    return answer;
}