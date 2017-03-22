
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;push 4
;call fibonachi
;pop bx

push 12
call fibonachi
pop bx

ret


fibonachi:

;create new frame
Push bp
Mov bp, sp

;saving required registers
Push bx
Push cx

;taking N from stack
Mov cx, [bp + 4]

Mov ax, 0
Mov bx, 0

;if end of recursion (0 or 1)
Cmp cx, 1
Ja notend
Mov ax, 1
Jmp end

notend:
;calling for N - 1
Dec cx
Push cx
Call fibonachi
Pop cx
;saving result
Mov bx, ax

;calling for N - 2
Dec cx
Push cx
Call fibonachi
Pop cx

end:
;calc the N
Add ax, bx

;restore the registers
Pop cx
Pop bx

;restore ebp
Pop bp

Ret



