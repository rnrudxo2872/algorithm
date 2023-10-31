# 포켓몬
# https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=python3
def solution(nums):
    dic = {}
    for num in nums:
        dic[num] = dic[num] + 1 if num in dic else 0
    
    return min(len(dic), len(nums) / 2)