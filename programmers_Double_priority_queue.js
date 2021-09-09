let Q = [];

function findInsertPos(num) {
    let start = 0;
    let end = Q.length - 1;
    let mid = 0;
    
    while(start < end){
        mid = Math.floor((start + end)/2);
        
        if(Q[mid] <= num) {
            end = mid;
        }else {
            start = mid + 1;
        }
    }
    return end;
}

function inputQueue (num) {
    if(Q.length === 0){
        Q.push(num);
        return;
    }
    
    let judge = Array.from(Array(2), () => false);
    if(num > Q[0]) {
        judge[0] = true;
    }
    if(num < Q[Q.length-1]) {
        judge[1] = true;
    }
    
    if(!judge[0] && !judge[1]){
        const idx = findInsertPos(num);
        Q.splice(idx,0,num);
        return;
    }
    if(judge[0]){
        Q.unshift(num);
        return;
    }
    if(judge[1]){
        Q.push(num);
        return;
    }
}

function solution(operations) {
    operations.map((element) => element.split(' ')).map(([oper, num]) => {
            if(oper === 'I') {
                inputQueue(Number(num));
            }
            if(oper === 'D'){
                Number(num) === -1 ? Q.pop() : Q.shift();
            }
        })
    
    return Q.length === 0 ? [0,0] : [Q[0],Q[Q.length - 1]];
}