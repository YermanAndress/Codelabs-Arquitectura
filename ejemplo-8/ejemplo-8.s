
# .data

uno: .float 1.0
cero: .float 0.0


.text
.global comparar_float

# Float Comparar_Float(float, float)
# xmm0 Comparar_Float(xmm0, xmm1) : xmm0 > xmm1?

comparar_float:

	ucomiss %xmm1, %xmm0		# Compare Como Escalar Float xmm0 con xmm1
	ja mayor			# xmm0 > xmm1

menor:

	movss cero(%rip), %xmm0		# xmm0 = cero
	jmp fin

mayor:

	movss uno(%rip), %xmm0		#xmm = uno

fin:
	ret
