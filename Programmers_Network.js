let visitArr;

let bfs = (arr,i) => {
    let tmp = [];
    tmp.unshift(i);

    while (tmp.length !== 0) {
        let curNum = tmp.shift();

        for (var i = 0; i < arr[curNum].length; i++){
            if (visitArr[arr[curNum][i]] === 1)
                continue;

            tmp.unshift(arr[curNum][i]);
            visitArr[arr[curNum][i]] = 1;
        }
    }
}

function solution(n, computers) {
    var answer = 0;

    let arr = new Array(n);
    visitArr = new Array(n);

    for (var i = 0; i < computers.length; i++){
        arr[i] = [];
        for (var j = 0; j < computers[i].length; j++){
            if (i === j || computers[i][j] === 0)
                continue;
            arr[i].push(j);
        }
    }
    for (var i = 0; i < n; i++){
        if (visitArr[i] === 1)
            continue;
        //console.log(i+"들어감!");
        bfs(arr,i);
        answer++;
    }

    // for (var i = 0; i < n; i++){
    //     console.log(`${i}번째 `,arr[i].length);
    //     for (var j = 0; j < arr[i].length; j++){
    //         console.log(arr[i][j]);
    //     }
    // }

    return answer;
}

console.log(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]));