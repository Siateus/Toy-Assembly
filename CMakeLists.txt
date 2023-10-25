cmake_minimum_required(VERSION 3.26)
project(Projeto02PC1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projeto02PC1 main.c
        leitura.h
        leitura.c
        control.h
        control.c
        aritmeticas.h
        aritmeticas.c
        memoria.h
        memoria.c
        logica.c
        logica.h
        saida.c
        saida.h
)
