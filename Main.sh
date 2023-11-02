#!/bin/bash
echo -e "\n\t\t\t\t\t\tCargando su Codigo QR personalizado"
barra()
{
echo -e "\v"
seconds=0,08
clear
for i in {1..50..1}
do
   echo -n "███"   
   sleep $seconds
done
echo -e "\n\t\t\t\t\t\tQR generado, presione ENTER para continuar"
}
case ${1,,} in
    "-q")
    	shift 1
        arg=$@
        export ARGUMENTO="$arg"
	barra & pid1=$!
	g++ -Wall Qrcode.cpp qrcodegen.cpp qrcodegen.hpp -o salida.out & pid2=$!
	wait $pid1
	wait $pid2
	read a
	./salida.out
	
    ;; 

    "-m") 
        shift 1
        arg=$@
        export ARGUMENTO="$arg"
        g++ MorseTranslator.cpp -o salida.out
        ./salida.out
        
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
    "-qm") 
        shift 1
        arg=$@
        export ARGUMENTO="$arg"
	g++ -Wall Qrcode.cpp qrcodegen.cpp qrcodegen.hpp -o salida.out
	./salida.out
        g++ MorseTranslator.cpp -o salida.out
        ./salida.out
     ;;
    *)
        echo "Argumento equivocado"
    ;;
esac

echo -e "\n\t\t\t\t\t\tPrograma Terminado, presione ENTER para finalizar\v"
read a
