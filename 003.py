#https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=python3

def solution(arr):
    answer = []
    for a in arr:
        if answer:
            if answer[-1] != a:
                answer.append(a)
        else:
             answer.append(a)   
    return answer

def solution(arr):
    answer = []
    for a in arr:
        if answer[-1:] == [a]:
            continue
        answer.append(a)
    return answer