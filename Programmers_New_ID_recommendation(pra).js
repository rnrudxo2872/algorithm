const solution = (new_id) => {
    let answer = new_id
    .toLowerCase()
    .replace(/[^\w.-]/g,'')
    .replace(/\.{2,}/g,'.')
    .replace(/^\.|\.$/g,'')
    .replace(/^$/,'a')
    .slice(0,15)
    .replace(/\.$/,'');
    
    return answer.length < 3 ? `${answer}${answer[answer.length-1].repeat(3-answer.length)}` : answer;
}