
.text
.global main

main:
	mov $4, %rax	#rax=4
	mov $5, %rbx	#rbx=5
	add %rbx, %rax 	#rax=rax+rbx

	mov $68, %rax 	#indico que vamos a usar la funcion sys_exit
	mov $0, %rdi 	#indico que el argumento tiene un valor de 0
	syscall 	#No es parte del ensamblador
