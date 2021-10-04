function solution(n) {
    let answer = [];
    let dic = ['4','1','2']
    
    while(n > 0) {
        answer.unshift(dic[n%3]);
        n = n % 3 === 0 ? n/3 -1 : Math.floor(n/3);
    }
    
    return answer.join('');
}