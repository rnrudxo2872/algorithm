# https://school.programmers.co.kr/learn/courses/30/lessons/87946

def dfs(visited, dungeons, n, k):
    deep = 0
    for (index, dungeon) in enumerate(dungeons):
        if not index in visited and k >= dungeon[0]:
            visited.add(index)
            deep = max(dfs(visited, dungeons, n+1, k - dungeon[1]), deep)
            visited.remove(index)
            
    return max(deep, n)

def solution(k, dungeons):
    visited = set()
    return dfs(visited, dungeons, 0, k)
    