const solution = (part, comp) => {
    const dic = {};
    
    part.forEach(value => {
        if(dic.hasOwnProperty(value)){
            dic[value] += 1;
            return;
        }
        dic[value] = 1;
    })
    
    comp.forEach(value => {
        dic[value] -= 1;
        if(dic[value] === 0){
            delete dic[value];
        }
    })
    
    for(const value in dic){
        return value
    }
}