function solution(bridge_length, weight, trucks) {
    let time = 1;
    let Q = Array.from({length:bridge_length}, () => 0);
    
    Q[0] = trucks.shift();
    
    let limitWeight = Q[0];
    
    while(limitWeight) {
        
        limitWeight -= Q.pop();
        let curTruck = trucks.length > 0 ? trucks[0] : 0;
        
        if(limitWeight + curTruck <= weight){
            limitWeight += curTruck;
           let outputTruck = trucks.shift();
           Q.unshift(outputTruck);
        }else{
            Q.unshift(0);
        }
        time++;
    }
    
    return time;
}