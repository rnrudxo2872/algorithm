const cmp = (a,b) => {
    return Number(`${b}${a}`) - Number(`${a}${b}`)
}

const solution = (numbers) => {
    const answer = numbers.sort(cmp).reduce((ret,val) => ret+val,"")
    return Number(answer) === 0 ? "0" : answer;
}