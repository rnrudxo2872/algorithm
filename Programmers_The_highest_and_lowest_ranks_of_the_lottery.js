const calcuRank = (fin) => {
    let ret;
    
    switch(fin){
        case 6:
            ret = 1;
            break;
        case 5:
            ret = 2;
            break;
        case 4:
            ret = 3;
            break;
        case 3:
            ret = 4;
            break;
        case 2:
            ret = 5;
            break;
        default:
            ret = 6;    
    }
    return ret;
}

function solution(lottos, win_nums) {
    var answer = [];
    let wildCard = 0;
    
    const fin = lottos.reduce((sum,cur) => {
        if(cur === 0){
            wildCard++;
            return sum;
        }
        return win_nums.indexOf(cur) !== -1 ? sum + 1 : sum 
    },0);
    answer[0] = calcuRank(fin+wildCard)
    answer[1] = calcuRank(fin);
    
    return answer;
}