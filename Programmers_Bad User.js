let curIdxList = [];
let bannList = new Set();
let banLen;
let User_id;
let regex = [];
let visit;

const cmp = (a,b) => a-b

function dfs(start){
    
    if(curIdxList.length === banLen){
        let Str = "";
        let temp = [...curIdxList];
        temp.sort(cmp);
        temp.forEach((value) => {
            Str += value;
        })
        
        bannList.add(Str);
        return;
    }
    
        for(var i = 0 ; i < User_id.length; i++){
            const reg = regex[start].exec(User_id[i]);
            
            if(!visit[i] && reg){
                
                visit[i] = true;
                curIdxList.push(i);
                
                dfs(start+1)
                
                curIdxList.pop();
                visit[i] = false;
                
            }
            
        }
}

function solution(user_id, banned_id) {
    
    banLen = banned_id.length;
    User_id = user_id;
    visit = Array.from({length:banned_id.length},() => false)
    
    banned_id.forEach((value) => {
        let curData = "";
        
        for(var i = 0; i < value.length; i++){
            if(value[i] === '*')
                curData += '.';
            else
                curData += value[i];
            }
        curData = `^(?=.{1,${curData.length}}$)${curData}`
        
        regex.push(new RegExp(curData));
    })
    
    dfs(0)
    bannList.forEach((value) => console.log(value))
    return bannList.size;
}