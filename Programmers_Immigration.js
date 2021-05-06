let cmp = (one, two) => one - two;
let cnt = 0;

let binarySearch = (left, right, times, n) => {
    let mid
    while (left < right) {
        mid = Math.floor((left + right) / 2);
        cnt = 0;

        for (var i = 0; i < times.length; i++){
            cnt += Math.floor(mid / times[i]);
        }

        if (cnt >= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

function solution(n, times) {
    var answer = 0;
    
    times = times.sort(cmp);
    let Len = times.length;
    let left = 0, right = times[Len-1] * n;


    answer = binarySearch(left, right, times, n);

    return answer;
}

console.log(solution(6,[7, 10]));