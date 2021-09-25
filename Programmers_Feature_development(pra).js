function solution(progresses, speeds) {
    var answer = [0];
    
    let day = progresses.map((value,idx) => Math.ceil((100-value)/speeds[idx]));
    let maxDay = day[0];
    
    for(let i = 0, j = 0; i < day.length; ++i){
        if(maxDay >= day[i]) {
            answer[j] += 1;
            continue;
        }
        maxDay = day[i];
        j++; 
        answer.push(1);
    }
    
    return answer;
}