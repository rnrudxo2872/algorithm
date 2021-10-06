function solution(n, lost, reserve) {
    lost = lost.filter(val => {
        const find = reserve.indexOf(val);
        if(find === -1) return true;
        
        reserve.splice(find,1);
    })
    
    lost.sort((a,b) => a-b);
    reserve.sort((a,b) => a-b);
    
    return n - lost.filter(val => {
        const [pre,next] = [reserve.indexOf(val-1),reserve.indexOf(val+1)];
        if(pre === -1 && next ===-1) return true;
        if(pre !== -1) {
            reserve.splice(pre,1);
            return false;
        }
        reserve.splice(next,1)
        return false;
    }).length
}