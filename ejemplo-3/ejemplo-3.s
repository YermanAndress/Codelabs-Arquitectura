
.data

mensaje: .asciz "%d $d \r\n"

.text
.global main
.extern printf # Similar Al Include stdio.h

main:
_start:

	subq $8, %rsp   # Alineamos Los Datos

	mov $4, %rax
	mov $5, %rbx

	#		%rdi		rsi	rdx
	# printf("Numero1 %d numero2 %d", rax, rbx)

	movq $mensaje, %rdi
	movq %rax, %rsi
	movq %rbx, %rdx

	call imprimir

	call salir

salir:

	# Salir Al Sistema
	mov $60, %rax
	mov $0, %rdi
	syscall
	ret


# Funcion Que Imprime Enteros En Consola
imprimir:

	subq $8, %rsp	# Alineamos Los Datos

	# RAX se pone 0 para indicar que necesitamos 0 registros de punto flotante
	movq $0, %rax	#rax=0	toca memoria
	xorq %rax, %rax	#rax=0	no toca memoria

	call printf

	addq $8, %rsp

	ret

.section .note.GNU-stack,"",@progbits
