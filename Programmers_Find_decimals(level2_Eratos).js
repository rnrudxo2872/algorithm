let retSet = new Set();
let visit = [];
let arr = [];

const sieveOfEratosthenes = (n) => {
    for(let i = 0; i < n+1; i++) arr[arr.length] = true;
    
    for(let i = 2; i * i <= n; ++i) {
        if(arr[i]){
            for(let j = i * i; j <= n; j += i){
                arr[j] = false;
            }
        }
    }
    
    arr[0] = false;
    arr[1] = false;
}

const dfs = (str,depth,numbers) => {
    if(depth > numbers.length) return;
    if(str.length > 0) retSet.add(Number(str))
    
    for(let i = 0; i < numbers.length; ++i){
        if(visit[i]) continue;
        visit[i] = true;
        dfs(str+numbers[i], depth+1, numbers);
        visit[i] = false;
    }
}

const solution = (numbers) => {
    for(let i = 0; i < numbers.length; ++i) visit[visit.length] = false;
    dfs('',0,numbers);
    
    let setToArr = [...retSet].sort((a,b) => b-a);
    sieveOfEratosthenes(setToArr[0]);
    return setToArr.filter(val => arr[val]).length;
}