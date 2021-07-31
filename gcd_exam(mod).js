function GCD(n1,n2){
    if(n2 === 0){
        return n1;
    }
    else {
        return GCD(n2,n1%n2)
    }
}

function solution(mod1, mod2, max_range) {
    let curMax = Math.floor(mod1 * mod2 / GCD(mod1,mod2));

    let ans1 = Math.floor(max_range / mod1);
    ans1 = ans1 - Math.floor(max_range / curMax)
    return ans1;
}