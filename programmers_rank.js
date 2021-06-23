function solution(n, results) {
    var answer = n;
    
    let a = [];
    
    for(let i = 0; i < n; i++){
        a[i] = [];
        for(let j = 0; j < n; j++){
            a[i][j] = null;
        }
    }
    
    results.map(item => {
        a[item[0]-1][item[1]-1] = true;
    })
    
    //console.log(a);
    
    for(let k = 0; k < n; k++){
        for(let i = 0; i < n; i++){
            for(let j = 0; j < n; j++){
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
    
    //console.log(a);
    
    for(let i = 0; i < n; i++){
        let cnt = 0;
        for(let j = 0; j < n; j++){
            if(a[i][j] || a[j][i])
                cnt++;
        }
        if(cnt !== n-1)
            answer--;
    }
    
    return answer;
}