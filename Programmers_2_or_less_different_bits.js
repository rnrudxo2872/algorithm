// const solution = (numbers) => numbers.map(num => {
//     let toBinary = num.toString(2);
//     let plus = 1;

//     while(true) {
//         let matchNum = num + plus++;
//         let matchToBinary = matchNum.toString(2);
        
//         let cnt = 0;
//         let gap = matchToBinary.length - toBinary.length;
        
//         for(let i = 0; i < gap; ++i) {
//             matchToBinary[i] !== '0' ? cnt++ : false;
//         }
        
//         let idx = 0;
//         for(let i = gap; i < matchToBinary.length; ++i) {
//             matchToBinary[i] !== toBinary[idx] ? cnt ++ : false;
//             idx++;
//         }
//         if(cnt < 3) return matchNum;
//     }
// })

// fail(time over)

const solution = (numbers) => numbers.map(num => {
    let toBinary = num.toString(2).split('');
    
    if(toBinary[toBinary.length-1] === '0') {
        toBinary[toBinary.length-1] = '1';
    }else {
        toBinary.unshift('0');
        for(let i = toBinary.length-1; i > -1; --i) {
            if(toBinary[i] === '0' && toBinary[i+1] === '1') {
                toBinary[i] = '1';
                toBinary[i+1] = '0';
                break;
            }
        }
    }
    
    let ans = parseInt(toBinary.join(''),2);
    return ans;
    
})