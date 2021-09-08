function solution(table, languages, preference) {
    
    return table.map(str => str.split(' '))
    .map(element => [...element.splice(0,1), element])
    .map(([sub,arr]) => 
         [sub,languages.reduce((pre,cur,idx) => pre += (5 - (arr.indexOf(cur) !== -1 ? arr.indexOf(cur) : 5)) * preference[idx],0)])
    .sort((a,b) => b[1] - a[1] === 0 ? (a[0] < b[0] ? -1 : 0) : b[1] - a[1])[0][0]
}