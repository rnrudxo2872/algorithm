# https://school.programmers.co.kr/learn/courses/30/lessons/42860?language=python3#

def solution(name):
    answer = 0
    minMove = len(name) - 1
    
    for index, ch in enumerate(name):
        answer += min(ord(ch) - ord('A'), ord('Z') - ord(ch) + 1)
        
        nextIndex = index + 1
        while nextIndex < len(name) and name[nextIndex] == 'A':
            nextIndex += 1
        
        minMove = min(minMove, (2 * index) + (len(name) - nextIndex), (2 * (len(name) - nextIndex)) + index)
        
    return answer + minMove

# "BBBBAAAABA" 12