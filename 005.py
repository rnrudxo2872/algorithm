# https://school.programmers.co.kr/learn/courses/30/lessons/43238?language=python3
def solution(n, times):
    times.sort()
    left = 0
    right = times[-1] * n
    
    while left < right:
        mid = int((left+right) / 2)
        
        sumNum = 0
        for time in times:
            sumNum += int(mid / time)
        
        if sumNum >= n:
            right = mid
        else:
            left = mid + 1
    return left