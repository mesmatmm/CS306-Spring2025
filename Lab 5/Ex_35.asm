;The display address of the first character (H) = (41 - 1) x 2 = [80]

ORG 100h

MOV AX, 0B800h
MOV DS, AX

MOV [80], 'H'
MOV [82], 'E'
MOV [84], 'L'
MOV [86], 'L'
MOV [88], 'O'

RET