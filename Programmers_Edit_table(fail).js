let table;
let curIdx;
let removeCache = [];

const upSearch = () => {
    const now = curIdx;
    for(var i = now; i > -1; i--) {
        if(table[i]) {
            return true;
        }
        curIdx--;
    }
    return false;
}

const downSearch = () => {
    const now = curIdx;
    for(var i = now; i < table.length; i++) {
        if(table[i]) {
            return true;
        }
        curIdx++;
    }
    return false;
}

const removeItem = () => {
    table[curIdx] = false;
    removeCache.push(curIdx);
    const isTrue = curIdx === table.length - 1 ? upSearch() : downSearch();
    isTrue ? false : upSearch();
}

const restoreItem = () => {
    return table[removeCache.pop()] = true;
}

const upIndex = (move) => {
    const now = 1;
    while(move !== 0) {
        curIdx -= now;
        table[curIdx] ? move-- : false;
    }
}

const downIndex = (move) => {
    const now = 1;
    while(move !== 0) {
        curIdx += now;
        table[curIdx] ? move-- : false;
    }
}

function solution(n, k, cmd) {
    var answer = '';
    
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