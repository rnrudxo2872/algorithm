var answer = 0;

function dfs(depth, object, arr) {
    if(Object.keys(object).length === depth){
        return;
    }
    
    answer += (answer * object[arr[0]]) + object[arr[0]];
    arr.splice(0,1)
    dfs(depth+1,object,arr)
}

function solution(clothes) {
    const dic = {};
    clothes.map(([_,clo]) => dic[clo] = (dic[clo] | 0) + 1)
    
    dfs(0,dic,Object.keys(dic));
    
    return answer;
}