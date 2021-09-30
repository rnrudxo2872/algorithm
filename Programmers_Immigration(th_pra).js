const binarySearch = (end, n, times) => {
    let start = 0;
    let mid = 0;
    while(start < end) {
        mid = Math.floor((start + end) / 2);
        let numbering = times.reduce((ret,val) => ret += Math.floor(mid/val),0);
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