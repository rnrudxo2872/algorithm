let Stones;
let K;

const executeJump = (Friends) => {
    let flag = true;
    let cnt = 0;
    
    for(var i = 0; i < Stones.length; ++i){
        if(Stones[i] <= Friends)
            cnt++;
        else
            cnt = 0;
        if(cnt >= K){
            flag = false;
            break;
        }
    }
    return flag;
}

const binarySearch = (left, right) => {
    let mid;
    
    while(left < right){
        mid = Math.floor((left+right) / 2);
        
        if(executeJump(mid)){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return right;
}

function solution(stones, k) {
    var answer = 0;
    Stones = stones;
    K = k;
    
    const left = 0, right = 200000000;
    
    return binarySearch(left,right);
}