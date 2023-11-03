# https://school.programmers.co.kr/learn/courses/30/lessons/169199

def bfs(board, ri, ci):
    visit = set()
    delPos = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    queue = [[ri, ci, 0]];
    
    while queue:
        [row, col, count] = queue.pop(0)
        visit.add((row, col))
        
        if board[row][col] == "G":
            return count
        
        for [delRow, delCol] in delPos:
            rowPos = row 
            colPos = col 
            while True:
                rowPos += delRow
                colPos += delCol
                if rowPos < 0 or rowPos >= len(board) or colPos < 0 or colPos >= len(board[0]) or board[rowPos][colPos] == "D":
                    rowPos -= delRow
                    colPos -= delCol
                    break
            if (rowPos, colPos) in visit:
                continue
                
            queue.append([rowPos,colPos,count+1])
            
    return -1
        

def solution(board):
    answer = 0
    
    isStart = False
    for ri, row in enumerate(board):
        for ci, col in enumerate(row):
            if board[ri][ci] == "R":
                isStart = True
                answer = bfs(board, ri, ci)
                break
        if isStart:
            break
    
    return answer