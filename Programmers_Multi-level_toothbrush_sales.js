class node {
    parent;
    child;
    income = 0;
    
    constructor(parent,child) {
        this.parent = parent;
        this.child = child;
    }
}

const dfs = (element, income, tree) => {
    if(!tree[element].parent) {
        tree[element].income += income;
        return;
    }
    
    let passIncome = Math.floor(income*0.1);
    if(passIncome < 1) {
        tree[element].income += income;
        return;
    }
    
    tree[element].income += income - passIncome;
    dfs(tree[element].parent, passIncome, tree);
}

const solution = (enroll, referral, seller, amount) => {
    let tree = {'minho':new node(null,[])};
    
    for(let i = 0; i < referral.length; i++) {
        let parent = referral[i] === '-' ? 'minho' : referral[i];
        
        tree[enroll[i]] = tree[enroll[i]] || new node(null,[]);
        tree[parent] = tree[parent] || new node(null,[]);
        
        tree[enroll[i]].parent = parent;
        tree[parent].child.push(enroll[i]);
    }
    
    for(let i = 0; i < seller.length; i++) {
        let income = 100 * amount[i];
        dfs(seller[i], income, tree);
    }
    
    let answer = [];
    let nameArr = Object.keys(tree);
    nameArr.shift();
    for(let i = 0; i < nameArr.length; i++) {
        answer.push(tree[nameArr[i]].income)
    }
    
    return answer;
}