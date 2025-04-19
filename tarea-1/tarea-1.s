.data
	msg_multiplicacion:	.asciz "Multiplicación: %d\n"
	msg_division:		.asciz "División: %d\n"

.text
.global main
.extern printf

main:

_start:
	# Llamar A La Funcion Multiplicacion

	mov $10, %rdi  # a = 10
	mov $3,  %rsi  # b = 3

	call multiplicar

	# Imprimir El Resultado De La Multiplicacion

	mov $msg_multiplicacion, %rdi
	mov %rax, %rsi

        xorq %rax, %rax
	call printf

	# Llamar A La Función De Division

	mov $12, %rdi  # a = 12
	mov $3,  %rsi  # b = 3

	call dividir

	# Imprimir El Resultado De La Division

	mov $msg_division, %rdi
	mov %rax, %rsi
        xorq %rax, %rax

	call printf

	call salir


multiplicar:

	imul %rsi, %rdi  # Multiplica %rsi (b) por %rdi (a)
	mov %rdi, %rax   # Mueve el resultado a %rax
	ret

dividir:

	mov %rdi, %rax   # Mueve el primer argumento (a) a %rax
	idiv %rsi        # Divide %rax (a) por %rsi (b)
	ret

salir:
	#salir al sistema
        mov $60, %rax
        mov $0, %rdi
        syscall
	ret
