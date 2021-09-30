const getTime = (times,mid) => {
    let sum = 0;
    for(let i = 0; i < times.length; i++) {
        sum += Math.floor(mid / times[i]);
    }
    return sum;
}

const binarySearch = (end, n, times) => {
    let start = 0;
    let mid = 0;
    while(start < end) {
        mid = Math.floor((start + end) / 2);
        let numbering = getTime(times,mid);
        if(numbering >= n) {
            end = mid;
            continue;
        }
        start = mid + 1;
    }
    
    return end;
}

const solution = (n, times) => {
    times.sort((a,b) => a-b);
    return binarySearch(times[times.length-1] * n, n, times);
}