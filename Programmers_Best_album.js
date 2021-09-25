const cmp = (a,b) => {
    if(a[0] > b[0])
        return -1;
    if(a[0] < b[0])
        return 1;
    if(a[1] < b[1])
        return -1;
    if(a[1] > b[1])
        return 1;
    return 0;
}

const solution = (genres, plays) => {
    var answer = [];
    
    const cret = {};
    const tmp = [];
    
    const tt = genres.reduce((ret,cur,idx) => {
        ret[cur] = (ret[cur] || []);
        ret[cur].push([plays[idx],idx])
        
        cret[cur] = (cret[cur] | 0) + plays[idx];
        return ret
    },{})
    
    Object.keys(tt).reduce((_,value) => {
        tt[value] = tt[value].sort(cmp)
    },{})
    
    for(const item in cret){
        tmp.push([item, cret[item]]);
    }
    
    tmp.sort((a, b) => b[1] - a[1])
    
    tmp.reduce((_,value) => {
        answer.push(tt[value[0]][0][1]);
        if(tt[value[0]].length > 1){
            answer.push(tt[value[0]][1][1]);    
        }
    },{})
    
    return answer;
}