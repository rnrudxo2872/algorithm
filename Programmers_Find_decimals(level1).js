const sieveOfEratosthenes = (n) => {
    let arr = [];
    for(let i = 0; i < n + 1; i++) arr[arr.length] = true;
    
    for(let i = 2; i * i <= n; ++i){
        if(arr[i]){
            for(let j = i * i; j <= n; j += i) {
                arr[j] = false;
            }
        }
    }
    arr.splice(0,2);
    return arr.filter(val => val).length
}

const solution = (n) => sieveOfEratosthenes(n);