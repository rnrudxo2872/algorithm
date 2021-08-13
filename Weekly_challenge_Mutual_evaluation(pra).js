const solution = (scores) => 
(scores[0].map((_,idx) => scores.map(row => row[idx])))
.map((item, idx) => [item.splice(idx,1)[0], item])
.map(([self, arr]) => Math.min(...arr) <= self && self <= Math.max(...arr) ? [self,...arr] : arr)
.map((item, idx) => "FDDCBAA"[Math.max(Math.floor((item.reduce((acc,cur) => acc+cur))/item.length/10)-4, 0)])
.join('')