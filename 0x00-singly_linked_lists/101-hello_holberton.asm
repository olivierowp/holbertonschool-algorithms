        SECTION .data
msg:    db "Hello, Holberton", 0
fmt:    db "%s", 10, 0

        SECTION .text
        extern printf
        global main
main:
        mov esi, msg    ; 64-bit ABI passing order starts w/ edi, esi, ...
        mov edi, fmt    ;
        mov eax, 0      ; printf is varargs, so EAX counts # of non-integer arguments being passed
        call printf
	mov eax, 0

	ret

