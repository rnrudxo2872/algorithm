const solution = (s) => s.length % 2 === 1 ? s[Math.floor(s.length/2)] : [s[Math.floor(s.length/2)-1],s[Math.floor(s.length/2)]].join('')

/// /// ///

const solution = (s) => s.substring(Math.floor(s.length/2) - (s.length%2 === 1 ? 0 : 1), Math.floor(s.length/2)+1);
