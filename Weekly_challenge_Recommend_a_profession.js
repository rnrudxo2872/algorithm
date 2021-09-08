function solution(table, languages, preference) {
    var answer = 'ZZZZZZZ';
    let maxScore = 0;
    table.map(str => str.split(' '))
        .map(element => { 
            let sub = element.shift();
            let score = 0;
            const subjects = [...element]

            languages.forEach((item, idx) => {
                const subIdx = subjects.indexOf(item);
                score += subIdx !== -1 ? preference[idx] * (subjects.length-subIdx) : 0;
            })
            if(maxScore < score){
                maxScore = score;
                answer = sub;
            }
            if(maxScore === score && sub < answer){
                    maxScore = score;
                    answer = sub;
            }
            return {sub,score}
    })
    return answer;
}