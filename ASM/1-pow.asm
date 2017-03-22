
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h	
   
push 2
push 4
call POW
pop bx
pop bx

push 3
push 6
call POW
pop bx
pop bx

ret





POW:
	;making new frame
	Push bp
	Mov bp, sp

	;saving eax ebx ecx edx
	;Push eax
	Push bx
	Push cx
	;Push edx

	;setting eax to 1 and ecx to 0 - those registers are the result
	Mov ax, 1
	Mov cx, 0

	;setting ebx to the base number - we will multiple ecx:eax with ebx.
	Mov bx, [bp + 6]

	;setting counter (ecx) as the exponent
	Mov cx, [bp + 4]

	;calculating
	l:
		Imul bx
		loop l

	;restore ecx and ebx
	pop cx
	pop bx

	;restore ebp
	pop bp

	ret


