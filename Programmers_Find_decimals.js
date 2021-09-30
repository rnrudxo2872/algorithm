const setDic = new Set();
let visit;

const isPrime = (n) => {
    if(n === 2 || n === 3) return true;
    if(n <= 1 || n % 2 === 0 || n % 3 === 0) return false;
    
    let div = 3;
    while(n > div){
        if(n % div === 0) return false;
        div += 2;
    }
    
    return true;
}

const dfs = (str,depth, numbers) => {
    if(depth === numbers.length + 1) return;
    
    if(str.length > 0 && isPrime(Number(str))){
        setDic.add(Number(str))
    }
    
    for(let i = 0; i < numbers.length; i++) {
        if(visit[i]) continue;
        
        visit[i] = true;
        dfs(str+numbers[i],depth+1,numbers)
        visit[i] = false;
    }
}

const solution = (numbers) => {
    visit = Array.from({length:numbers.length}, () => false);
    dfs('',0,numbers)
    return setDic.size;
}