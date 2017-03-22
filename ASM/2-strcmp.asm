; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
jmp start

st1 db "wow" , 0x0
st2 db "waw" , 0x0
st3 db "wawa", 0x0
st4 db "alsss",0x0

start:
lea bx, st1
push bx
lea bx, st2
push bx
call Strcmp  
pop bx
        
lea bx, st1
push bx
call Strcmp
pop bx
pop bx

ret    
     
     
Strcmp:

;creates frame
Push bp
Mov bp, sp

;saving registers
Push bx
Push di
Push si

;saving strings into registers
mov di, [bp + 4]
mov si, [bp + 6]
      
;init ax
mov ax, 0

;comparing one byte (ecx) from str1 (edx) to one byte (eax) from str2 (ebx)
;until end of one of the str's (\0) or not equale
comp:
;take the bytes
mov al, [di]
mov bl, [si]

Cmp al, bl
Jne notequal

;if is equal, we check if end of strings
Cmp al, 0
Je isequal

;if not end of strings, we move to the next bytes and move to comp
Add di, 1
Add si, 1
Jmp comp

;if not equal, return 1
notequal:
Mov ax, 1

;if equal, return 0 (no need to actually do it should be 0(\0))
isequal: 

;restoring registers
Pop si
Pop di
Pop bx

;restoring ebp
Pop bp

Ret




