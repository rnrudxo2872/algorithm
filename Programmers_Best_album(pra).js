const solution = (genres, plays) => {
    const dic = genres.reduce((ret,value,idx) => {
        ret[value] = (ret[value] | 0) + plays[idx]
        return ret
    },{}) 
    
    const resultDic = {};
    
    return genres.map((value, idx) => {
        return {genre:value, plays:plays[idx], idx}
    }).sort((a,b) => {
        if(a.genre !== b.genre) return dic[b.genre] - dic[a.genre];
        if(a.plays !== b.plays) return b.plays - a.plays;
        return a.idx - b.idx;
    }).filter((item) => {
        resultDic[item.genre] = (resultDic[item.genre] || [])
        
        if(resultDic[item.genre].length >= 2) return false;
        resultDic[item.genre].push(item);
        return true
    }).map((value) => value.idx)
}