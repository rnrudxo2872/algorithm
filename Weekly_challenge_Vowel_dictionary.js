const WORD = ['A','E','I','O','U']

let dictionary = {};
let curIdx = 1;

function dfs (str,depth) {
    if(depth >= 6){
        return;
    }
    
    for(var i = 0; i < WORD.length; i++) {
        const curStr = str + WORD[i];
        dictionary[curStr] = curIdx;
        curIdx++;
        dfs(curStr, depth + 1);
    }
}

function solution(word) {
    dfs('',1);
    
    const answer = dictionary[word];
    
    return answer;
}