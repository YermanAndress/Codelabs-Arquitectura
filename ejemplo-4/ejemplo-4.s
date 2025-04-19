# Ejemplo De Una Funcion Hecha En Assembly


.text
.global sumar
.global restar


sumar:	# En Lenguaje C: Resultado = Sumar (int a, int b)

	add %rsi, %rdi
	mov %rdi, %rax

	ret


restar: # En Lenguaje C: Resultado = Restar (int a, int b)

	sub %rsi, %rdi
	mov %rdi, %rax

	ret
