let TIMES;
let N;

const cmp = (a, b) => {
    return a - b
}

const getSum = (mid) => {
    let sum = 0;
    TIMES.forEach((value) => sum += Math.floor(mid/value))
    
    return sum
}

const binarySearch = (left, right) =>{
    let mid = 0;
    while(left < right){
        mid = Math.floor((left + right) / 2);
        
        //각 심사관 검사 할 수 있는 사람 수 * 각 심사관 검사 시간 = 총 걸린 시간
        const sum = getSum(mid);
        
        if(sum >= N){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return right;
}

function solution(n, times) {
    //오름차순 정렬
    TIMES = times.sort(cmp)
    N = n;
    
    const left = 0, right = times[times.length - 1] * n;
        
    return binarySearch(left, right);
}