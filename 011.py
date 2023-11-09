# https://school.programmers.co.kr/learn/courses/30/lessons/154540

def bfs(maps, visited, queue):
    delPos = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    result = 0
    
    while queue:
        (row, col) = queue.pop(0)
        if (row, col) in visited:
            continue
        visited.add((row, col))
        
        result += int(maps[row][col])
        
        for [delRow, delCol] in delPos:
            mRow = row + delRow
            mCol = col + delCol
            
            if mRow < 0 or mRow >= len(maps) or mCol < 0 or mCol >= len(maps[mRow]) or maps[mRow][mCol] == 'X':
                continue
                
            queue.append((mRow, mCol))
    
    return result

def solution(maps):
    answer = []
    visited = set()
    
    for row, rowMap in enumerate(maps):
        for col, _ in enumerate(rowMap):
            if not (row, col) in visited and maps[row][col] != 'X':
                queue = [(row, col)];
                maxLive = bfs(maps, visited, queue)
                answer.append(maxLive)
           
    answer.sort()
    if not answer:
        return [-1]
    
    return answer