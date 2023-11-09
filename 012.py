# https://school.programmers.co.kr/learn/courses/30/lessons/154539
def solution(numbers):
    answer = [-1] * len(numbers)
    stack = []
    
    for index in range(len(numbers) - 1, -1, -1):
        while stack and numbers[index] >= stack[-1]:
            stack.pop()
        
        if stack:
            answer[index] = stack[-1]
            
        stack.append(numbers[index])
        
    return answer