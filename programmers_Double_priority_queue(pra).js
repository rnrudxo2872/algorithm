let ans = [];

function maxPop() {
    let value = Math.max(...ans);
    return ans.splice(ans.indexOf(value), 1);
}

function minPop () {
    let value = Math.min(...ans)
    return ans.splice(ans.indexOf(value), 1);
}

function commandSolve(cmd) {
    const [oper, num] = cmd.split(' ');
    oper === 'I' ? 
        ans.push(Number(num)) : (ans.length !== 0 
                                 ? (num[0] === '-' ? minPop() : maxPop()) : false);
}

function solution(operations) {
    operations.forEach(commandSolve)
    return ans.length === 0 ? [0,0] : [Math.max(...ans), Math.min(...ans)];
}