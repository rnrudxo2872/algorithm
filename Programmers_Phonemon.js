const solution = (nums) => {
    let answer = [];
    let max = nums.length / 2;
    
    for(let i = 0; i < nums.length; i++) {
        if(answer.length !== max) {
            answer.includes(nums[i]) ? false : answer.push(nums[i])
            continue;
        }
        return answer.length;
    }
    return answer.length;
}

//
const solution = (nums) => Math.min(nums.reduce((ret,val) => {
    ret.includes(val) ? false : ret.push(val)
    return ret
},[]).length, nums.length / 2)

//
const solution = (nums) => {
    let newSet = [...new Set(nums)];
    return Math.min(newSet.length, nums.length / 2);
}