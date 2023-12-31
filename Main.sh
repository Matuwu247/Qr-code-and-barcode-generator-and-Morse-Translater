#!/bin/bash
case ${1,,} in #iniciams el switch y la ,, hace la funcion de convertir todo a minuscula
    "-q") #Caso de codigo QR
    	shift 1 #Mueve el argumento
        arg=$@ #Esto tomara todo lo ingresado luego del primer argumento
        export ARGUMENTO="$arg" #Tomas lo ingresado en el primer parametro y lo envia al codigo
    	./salidaQ.out #Ejecuta el codigo de c++ compilado 
	
    ;; 
    "-m") #Caso de codigo Morse
        shift 1
        arg=$@
        export ARGUMENTO="$arg"
        ./salidaM.out
        
     ;;
     "-b") #Caso de codigo de barra
	shift 1
        arg=$@
        export ARGUMENTO="$arg"
	python3 Barcode.py #Ejecuta el interprete de python
     ;;
         "-qm") #Caso de codigo QR y Codigo Morse
	shift 1
        arg=$@
        export ARGUMENTO="$arg"
        ./salidaQ.out
        ./salidaM.out
     ;;
    "-h" | "--help") #En caso de necesitar ayuda explica el funcionamiento
        echo "Buenas usuario el codigo funciona de la siguiente manera:
    Primero deberemos de colocar que tipo de transformacion queremos. Esto lo haremos poniendo los 
    siguientes parametros:
    -q o -Q: Este parametro es la transformacion del texto ingresado a codigo QR
    -m o -M: Este parametro es la transformacion del texto ingresado a codigo Morse
    -b o -B: Este parametro es la transformacion del texto ingresado a codigo de barras
    Luego para el texto a traducir debemos colocar unas comillas a continuacion del primer parametro es 
    decir a continuacion del -m o -q. Es importante que este entre comillas porque sino no funcionara."
    ;;

    *) // toma todos los casos que no estan mencionados arriba
        echo "Argumento equivocado"
    ;;
esac
echo -e "\n\t\t\t\t\t\tPrograma Terminado, presione ENTER para finalizar\v"
read a
clear
