.data
        # Mensaje
        msg_seno:       .asciz "El seno de %.2f grados es: %.6f\n"

        # Constantes
        grados_a_rad:   .double 0.017453292519943295   # π / 180
        angulo:         .double 45.0

.text
.global main
.extern printf
.extern sin

main:
        sub $8, %rsp

        # Cargar El Angulo
        movsd angulo, %xmm0             # xmm0 = Angulo En Grados

        # Convertir Grados A Radianes
        mulsd grados_a_rad, %xmm0       # xmm0 = Angulo En Radianes

        # Llamar A La Funcion Sin
        call sin                        # xmm0 = sin

        movsd %xmm0, %xmm1              # xmm1 = sin
        movsd angulo, %xmm0             # xmm0 = Angulo En Grados

        mov $msg_seno, %rdi
        #mov $2, %rax

        call printf

        # Restaurar la pila
        add $8, %rsp

        # Salir del programa

        mov $60, %rax
        xor %rdi, %rdi
        syscall
