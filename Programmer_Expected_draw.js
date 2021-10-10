const solution = (n,a,b) => {
    let start = 1;
    
    while(true) {
        a = Math.ceil(a/2);
        b = Math.ceil(b/2);
        if(a === b) return start;
        
        start++;
    }
}