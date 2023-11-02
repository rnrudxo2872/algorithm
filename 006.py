# https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=python3
def solution(s):
    brackets = []
    for bra in s:
        if bra == "(":
            brackets.append(1)
        else:
            if not brackets: 
                return False
            else:
                brackets.pop()
    
    if brackets:
        return False
    return True