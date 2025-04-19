.text
.global suma_float

# Para Los Floats Se Utilizan Los Registros xmm0
# Segun System V:
# xmm0 funcion (xmm0,	xmm1,	xmm2,	...) En Ensamblador
# Float funcion (float1, float2, float3, ...) En Lenguaje C

suma_float:
	addss %xmm1, %xmm0 # xmm0 = xmm0 + xmm1
	ret


# addss: Add Scalar Single Precision (Sumar Un Escalara De Precision Simple, Es Decir Float)
