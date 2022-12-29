// 금과 은 운반하기
function solution(a, b, g, s, w, t) {
    const MAXIMUM = 10e14 * 4
    let start = 0;
    let result = MAXIMUM, end = MAXIMUM;
    
    while(start <= end) {
        let mid = Math.floor((start + end) / 2);
        let gold = 0;
        let silver = 0;
        let add = 0;
        
        for(let i = 0; i < s.length; ++i) {
            let curGold = g[i];
            let curSilver = s[i];
            let curWeight = w[i];
            let curTime = t[i];
            
            const ROTATE_TIME = curTime * 2;
            
            let moveCount = Math.floor(mid / ROTATE_TIME);
            if(mid % ROTATE_TIME >= curTime) {
                moveCount += 1;
            }
            
            const maxDeliver = curWeight * moveCount;
            gold += Math.min(curGold, maxDeliver);
            silver += Math.min(curSilver, maxDeliver);
            add += Math.min(curGold + curSilver, maxDeliver);
        }
        
        if(gold >= a && silver >= b && add >= a + b) {
            end = mid - 1;
            result = Math.min(result, mid);
            continue;
        }
        start = mid + 1;
    }
    
    return result;
}