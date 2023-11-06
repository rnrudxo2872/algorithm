# https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=python3

def solution(n, lost, reserve):
    answer = n - len(lost)
    
    lost.sort()
    reserve.sort()
    
    visit = set()
    for a in lost:
        minNum = a - 1 if a - 1 >= 0 else n
        
        if a in reserve:
            index = reserve.index(a)
            if not index in visit:
                visit.add(index)
                answer += 1
        elif a - 1 in reserve:
            index = reserve.index(a-1)
            if not index in visit:
                visit.add(index)
                answer += 1
            elif (a + 1) % (n + 1) in reserve:
                nextIndex = reserve.index((a + 1) % (n + 1))
                if not nextIndex in visit:
                    visit.add(nextIndex)
                    answer += 1
        elif (a + 1) % (n + 1) in reserve:
            index = reserve.index((a + 1) % (n + 1))
            if not index in visit:
                visit.add(index)
                answer += 1
 
    return answer