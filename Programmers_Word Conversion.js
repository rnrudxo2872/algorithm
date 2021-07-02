let Target;
let Words;
let Q = [];
let visit;

const searchWord = () => {
    while(Q.length > 0) {
        const curNode = Q.shift();
        const curWord = curNode.word;
        const curLen = curNode.len;
        
        if(curWord === Target){
            return curLen;
        }
        
        for(var i = 0; i < Words.length; ++i){
            if(visit[i]){
                continue;
            }
            let cnt = 0;
            let nWord = Words[i];
            
            for(var j = 0; j < nWord.length; ++j){
                if(curWord[j] !== nWord[j]){
                    cnt++;
                }
                if(cnt > 1){
                    break;
                }
            }
            if(cnt != 1)
                continue;
            visit[i] = true;
            Q.push({word:nWord,len:curLen+1});
        }
    }
    return 0;
}

function solution(begin, target, words) {
    Q.push({word:begin, len:0});
    
    Target = target;
    Words = words;
    visit = Array.from({length:words.length}, () => false)
    
    return searchWord();
}