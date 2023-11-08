#!/bin/bash
exportvar()
{
    	shift 1
        arg=$@
        export ARGUMENTO="$arg"
}
case ${1,,} in
    "-q")
    	shift 1
        arg=$@
        export ARGUMENTO="$arg"
    	./salidaQ.out
	
    ;; 
    "-m") 
        shift 1
        arg=$@
        export ARGUMENTO="$arg"
        ./salidaM.out
        
     ;;
     "-b")
	shift 1
        arg=$@
        export ARGUMENTO="$arg"
	python3 Barcode.py
     ;;
         "-qm") 
	shift 1
        arg=$@
        export ARGUMENTO="$arg"
        ./salidaQ.out
        ./salidaM.out
     ;;
    "-h" | "--help")
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
echo -e "\n\t\t\t\t\t\tPrograma Terminado, presione ENTER para finalizar\v"
read a
clear
