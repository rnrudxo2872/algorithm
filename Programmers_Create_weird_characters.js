const solution = (s) => s
    .split(' ')
    .map(str => str.split('').map((char,idx) => (idx+1)%2 === 1 ? char.toUpperCase() : char.toLowerCase()).join('')).join(' ');