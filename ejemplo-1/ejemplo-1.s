
.globl _start

.text 


_start:

	mov $0x3F, %al
	mov $0xF3, %ah


	# Salir Al Sistema
	mov $60, %rax	# 60 Es La Funcion Exit
	xor %rdi, %rdi	# rdi = 0
	syscall
