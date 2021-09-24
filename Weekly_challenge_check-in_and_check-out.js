function solution(enter, leave) {
    var answer = Array.from({length:enter.length + 1}, () => 0);
    
    let store = [];
    let enterIdx = 0;
    let leaveIdx = 0;
    
    while(enterIdx < enter.length || leaveIdx < leave.length){
        let curEnter = enter[enterIdx];
        let curLeave = leave[leaveIdx];
        
        let searchResult = store.indexOf(curLeave);
        if(searchResult === -1){
            store.push(curEnter)
            
            enterIdx++;
            continue;
        }
        
        store.splice(searchResult,1);
        leaveIdx++;
        
        answer[curLeave] += store.length;
        store.forEach(value => answer[value]++)
    }
    
    answer.splice(0,1)
    return answer;
}