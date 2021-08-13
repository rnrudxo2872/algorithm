function getGrade(sumMod){
    switch(sumMod){
        case 10:
            return 'A'
        case 9:
            return 'A';
        case 8:
            return 'B'
        case 7:
            return 'C'
        case 6:
            return 'D'
        case 5:
            return 'D'
        default:
            return 'F'
    }
}

function solution(scores) {
    let answer = ""

    for(var i = 0; i < scores.length; ++i){
        let sum = 0;
        let curMax = 0;
        let curMin = 100;

        let cntMax = 0;
        let cntMin = 0;

        for(var j = 0; j < scores[i].length; ++j){
            let curScore = scores[j][i];

            sum += curScore;

            if(curScore === curMax){
                cntMax++;
            }
            if(curScore === curMin){
                cntMin++;
            }

            if(curMax < curScore){
                curMax = curScore;
                cntMax = 0;
            }
            if(curMin > curScore){
                curMin = curScore;
                cntMin = 0;
            }
        }
        let divNum = scores.length;
        if((scores[i][i] === curMax && cntMax === 0) || (scores[i][i] === curMin && cntMin === 0)){
            sum -= scores[i][i];
            divNum -= 1;
        }
        const operNum = parseInt(parseInt(sum/divNum)/10);
        answer += getGrade(operNum);
    }
    return answer;
}