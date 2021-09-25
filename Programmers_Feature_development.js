function solution(progresses, speeds) {
    var answer = [];
    
    let day = 0;
    
    progresses.forEach((value,idx) => {
        const consum = Math.ceil((100 - value) / speeds[idx]);
        if(day < consum){
            day = consum;
            answer.push(1);
            return;
        }
        answer[answer.length - 1] += 1;
    })
    
    return answer;
}