const solution = (numbers) => [...numbers.reduce((ret,val,idx) => {
    numbers.forEach((item,itemIdx) => {
        if(idx !== itemIdx)
            ret.add(val + item)
    });
    return ret;
},new Set())]
.sort((a,b) => a-b)