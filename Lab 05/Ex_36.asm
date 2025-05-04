;Solution:
;The display address of the first character (H) = (0 x 160) + (40 x 2) = [80]

ORG 100h

MOV AX, 0B800h
MOV ES, AX

MOV ES:[80], 'H'
MOV ES:[82], 'E'
MOV ES:[84], 'L'
MOV ES:[86], 'L'
MOV ES:[88], 'O'

RET