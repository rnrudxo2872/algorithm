const INF = 999999999;

let answer = INF;
let dp = [];
let defaultNum;

let dynamicDfs = (target, current, cnt) => {
    if (cnt > 8)
        return;
    if (current === target) {
        answer = answer < cnt ? answer : cnt;
        return;
    }
    let oper = 0;
    for (var i = 1; i < 9; i++){
        oper = Math.floor((oper * 10) + defaultNum);

        dynamicDfs(target, current + oper, cnt + i);
        dynamicDfs(target, current - oper, cnt + i);
        if (current !== 0) {
            let mlu = Math.floor(current * oper);
            let div = Math.floor(current / oper);
            dynamicDfs(target, mlu, cnt + i);
            dynamicDfs(target, div, cnt + i);
        }
    }
}

function solution(N, number) {
    defaultNum = N;

    dynamicDfs(number, 0, 0);

    return answer === INF ? -1 : answer;
}

console.log(solution(5, 31168));