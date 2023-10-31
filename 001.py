# 뒤에서 5등 위로
def solution(num_list):
    answer = num_list
    answer.sort()
    answer.reverse()
    
    for i in range(0, 5):
        answer.pop()
        
    answer.reverse()
    
    return answer