const solution = (sizes) => {
    const [w,h] = sizes.reduce((ret,value) => {
        const [minW,minH] = ret;
        const [w,h] = value;
        
        //정방향
        const oneW = minW > w ? minW : w;
        const oneH = minH > h ? minH : h;
        
        const oneR = oneW * oneH;
        
        //역방향
        const twoW = minW > h ? minW : h;
        const twoH = minH > w ? minH : w;
        
        const twoR = twoW * twoH;
        
        return oneR > twoR ? [twoW,twoH] : [oneW,oneH];
    })
    
    return w*h
}