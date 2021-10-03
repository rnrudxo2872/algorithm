function getChar(str) {
    let ret = str.split('');
    for(let i = 0; i < 3 - str.length; ++i) {
        ret[ret.length] = str[str.length-1];
    }
    return ret
}

function solution(new_id) {
    //1~3
    let answer = new_id.toLowerCase().replace(/[^\w.-]/g,'').split('').reduce((ret,val) => {
        return ret[ret.length-1] === '.' && val === '.' ? ret : ret+val;
    })
    
    //4
    answer.length > 0 && answer[0] === '.' ? answer = answer.substring(1) : false;
    answer.length > 0 && answer[answer.length-1] === '.' ? answer = answer.substring(0,answer.length-1) : false;
    
    //5~6
    answer.length === 0 ? answer = 'a' : false;
    answer = answer.length > 15 ? answer.split('').splice(0,15).join('') : answer;
    answer.length > 0 && answer[answer.length-1] === '.' ? answer = answer.substring(0,answer.length-1) : false;
    
    //7
    if(answer.length < 3) answer = getChar(answer).join('');
    return answer
}