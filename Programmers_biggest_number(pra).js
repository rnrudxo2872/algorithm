const solution = (numbers) => {
    const answer = numbers.map(val => val+'').sort((a,b) => (b+a) * 1 - (a+b) * 1).join('');
    return Number(answer) === 0 ? "0" : answer;
}