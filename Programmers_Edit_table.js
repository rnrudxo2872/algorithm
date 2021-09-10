let table;
let list;
let curIdx;
let removeCache = [];

const removeItem = () => {
    table[curIdx] = false;
    const [pre,next] = list[curIdx];
    
    removeCache.push([curIdx,pre,next]);
    if(next === -1){
        if(pre !== -1)
            list[pre][1] = next;
        curIdx = pre;
        return;
    }
    pre !== -1 ? list[pre][1] = next : false;
    list[next][0] = pre;
    curIdx = next;
}

const restoreItem = () => {
    const [index, pre, next] = removeCache.pop();
    table[index] = true;
    
    if(pre !== -1){
        list[pre][1] = index;
    }
    if(next !== -1){
        list[next][0] = index;
    }
}

const upIndex = (move) => {
    for(var i = 0; i < move; i++){
        curIdx = list[curIdx][0];
    }
}

const downIndex = (move) => {
    for(var i = 0; i < move; i++){
        curIdx = list[curIdx][1];
    }
}

function solution(n, k, cmd) {
    var answer = '';
    
    list = Array.from({length:n}, (value, index) => [index-1, index+1]);
    list[n-1][1] = -1;
    table = Array.from(Array(n),() => true);
    curIdx = k;
    
    cmd.forEach((item) => {
        if(item[0] === 'C'){
            removeItem();
        }else if(item[0] === 'Z'){
            restoreItem();
        }else {
            const divItem = item.split(' ');
            divItem[0] === 'U' ? upIndex(Number(divItem[1])) : downIndex(Number(divItem[1]));
        }
    })
    table.forEach(item => item ? answer += 'O' : answer += 'X')
    return answer;
}