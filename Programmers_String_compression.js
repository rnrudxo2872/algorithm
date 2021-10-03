function solution(s) {
    var answer = Number.MAX_VALUE;
    
    let cnt = 1;
    while(cnt < Math.floor(s.length / 2) + 1) {
        let curWord = s.substr(0,cnt);
        let curLen = cnt;
        let num = 0;
        
        for(let i = 0; i < s.length; i += cnt) {
            if(curWord === s.substr(i,cnt)) {
                num++;
                continue;
            }
            
            curLen += (num === 0 || num === 1) ? 0 : Math.floor(num / 10) === 0 ? 1 : (num+"").length;
            curWord = s.substr(i,cnt)
            curLen += curWord.length;
            
            num = 1;
        }
        curLen += (num === 0 || num === 1) ? 0 : Math.floor(num / 10) === 0 ? 1 : (num+"").length;
    
        if(answer > curLen) {
            answer = curLen;
        }
        
        cnt++;
    }
    
    return answer === Number.MAX_VALUE ? s.length : answer;
}