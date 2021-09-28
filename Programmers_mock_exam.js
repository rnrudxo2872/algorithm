function solution(answers) {
    const patterns = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5],[3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    let cnt = [0,0,0];
    
    const max = answers.reduce((ret,cur,idx) => {
       let sIdx = [idx%patterns[0].length,idx%patterns[1].length,idx%patterns[2].length] ;
        cnt[0] += patterns[0][sIdx[0]] === cur ? 1 : 0;
        cnt[1] += patterns[1][sIdx[1]] === cur ? 1 : 0;
        cnt[2] += patterns[2][sIdx[2]] === cur ? 1 : 0;
        return Math.max(cnt[0],Math.max(cnt[1],cnt[2]))
    },0)
    
    return cnt.map((value,index) => {
        if(max === value) return index + 1
    }).filter(value => value ? true : false);
}