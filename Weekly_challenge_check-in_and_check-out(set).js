const solution = (enter, leave) => {
    let answer = Array.from({length:enter.length}, () => 0);
    let room = new Set();
    
    for(let i = 0, j = 0; j < leave.length; ++j){
        const curLeave = leave[j];
        
        while(!room.has(curLeave)){
            room.add(enter[i++]);
        }
        room.delete(curLeave);
        
        for(let item of room){
            answer[curLeave - 1]++;
            answer[item - 1]++;
        }
    }
    
    return answer;
}