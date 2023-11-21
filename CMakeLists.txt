cmake_minimum_required(VERSION 3.26)
project(Projeto02PC1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projeto02PC1 src/main.c
        include/leitura.h
        src/leitura.c
        include/control.h
        src/control.c
        include/aritmeticas.h
        src/aritmeticas.c
        include/memoria.h
        src/memoria.c
        src/logica.c
        include/logica.h
        src/saida.c
        include/saida.h
)
