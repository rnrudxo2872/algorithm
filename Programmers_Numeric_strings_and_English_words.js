function getDic() {
    return {
        zero:0,
        one:1,
        two:2,
        three:3,
        four:4,
        five:5,
        six:6,
        seven:7,
        eight:8,
        nine:9,
    }
}

function solution(s) {
    var answer = [];
    
    const numberDic = getDic();
    let curStr = ''
    for(let i = 0; i < s.length; i++) {
        if(curStr.length !== 0 && numberDic[curStr] != null) {
                answer.push(numberDic[curStr])
                curStr = ''
        }
        if(/[0-9]/.test(s[i])) {
            answer.push(s[i])
            continue;
        }
        curStr += s[i];
    }
    curStr.length !== 0 ? answer.push(numberDic[curStr]) : false;
    return answer.join('')*1;
}

// // // //
function solution(s) {
    const numbers = ["zero","one","two","three","four","five","six","seven","eight","nine"];
    let answer = s;
    for(let i = 0; i < numbers.length; i++) {
        let arr = answer.split(numbers[i]);
        answer = arr.join(i)
    }
    return answer*1;
}