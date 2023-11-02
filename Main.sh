#!/bin/bash


case $1 in
    "-q" | "-Q")
        arg=$@
        export ARGUMENTO="$arg"
	g++ -Wall Qrcode.cpp qrcodegen.cpp qrcodegen.hpp -o salida.out
	./salida.out
    
    ;; 

    "-m" | "-M") 
        arg=$@
        export ARGUMENTO="$arg"
        g++ MorseTranslator.cpp -o salida.out
        ./salida.out
        
     ;;
    "-h" | "-H" | "--help" | "--Help"| "--HELP")
        echo "Buenas usuario el codigo funciona de la siguiente manera:
    Primero deberemos de colocar que tipo de transformacion queremos. Esto lo haremos poniendo los 
    siguientes parametros:
    -q o -Q: Este parametro es la transformacion del texto ingresado a codigo QR
    -m o -M: Este parametro es la transformacion del texto ingresado a codigo Morse
    Luego para el texto a traducir debemos colocar unas comillas a continuacion del primer parametro es 
    decir a continuacion del -m o -q. Es importante que este entre comillas porque sino no funcionara."

    ;;
    *)
        echo "Argumento equivocado"
    ;;
esac
