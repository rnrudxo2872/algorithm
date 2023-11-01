# https://school.programmers.co.kr/learn/courses/30/lessons/49189?language=python3
def solution(n, edge):
    dic = {}
    for [start, end] in edge:
        if not start in dic:
            dic[start] = {end: 1}
        else:
            dic[start][end] = 1
        if not end in dic:
            dic[end] = {start: 1}
        else:
            dic[end][start] = 1
    
    visit = {}
    for visit_key in dic.keys():
        visit[visit_key] = False
    
    queue = [(1,0)]
    max_value = 0
    count = 0
    answer_list = []
    
    while len(queue) != 0:
        (number, dist) = queue.pop(0)
        if visit[number]: continue
        visit[number] = True
        
        if dist == max_value:
            answer_list.append(number)
        
        if dist > max_value:
            answer_list = [number]
            max_value = dist
            
        for v in dic[number]:
            queue.append((v, dist + 1))
    
    return len(answer_list)