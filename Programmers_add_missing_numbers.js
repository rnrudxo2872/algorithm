function solution(numbers) {
    let visit = [];
    
    for(let i = 0; i < 10; ++i) visit[visit.length] = false;
    numbers.reduce((_,val) => visit[val] = true, 0);
    return visit.reduce((ret,val,idx) => val ? ret : ret+idx,0);
}

/// /// ///
const solution = (nums) => 45 - nums.reduce((ret,val) => ret + val);