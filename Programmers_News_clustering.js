function getArr(Arr) {
    const regex = /[a-z]/
    let ret = [];
    
    for(let i = 0; i < Arr.length - 1; ++i) {
        if(regex.test(Arr[i]) && regex.test(Arr[i+1])) ret.push([Arr[i], Arr[i+1]].join(''));  
    }
    return ret;
}

function solution(str1, str2) {
    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();
    
    const charArr1 = str1.split('');
    const charArr2 = str2.split('');
    
    let Arr1 = getArr(charArr1);
    let Arr2 = getArr(charArr2);
    
    if(Arr1.length === 0 && Arr2.length === 0) return 65536;
    
    let unionArr = [...Arr1,...Arr2];
    
    let crossArr = [];
    
    for(let i = 0; i < Arr1.length; ++i) {
        let idx = Arr2.indexOf(Arr1[i]);
        
        if(idx !== -1) {
            Arr2.splice(idx,1);
            crossArr.push(Arr1[i]);
        }
    }
    
    for(let i = 0; i < crossArr.length; ++i) {
        let idx = unionArr.indexOf(crossArr[i]);
        if(idx !== -1) {
            unionArr.splice(idx, 1);
        }
    }
    
    let answer = crossArr.length / unionArr.length;
    return Math.floor(answer * 65536);
}