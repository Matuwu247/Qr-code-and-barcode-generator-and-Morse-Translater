# Qr-code-generator-and-Morse-Translater
Introduction
------------
This project has been created for project in the fifth year of the technical secondary school of the San Judas Tadeo school in Ituzaingo, Buenos Aires Argentina. The main objective was to find a way to place the arguments and manipulate them from the Linux command line using any Ubuntu distro.

Features
--------
It can generate the QR code of any text you place in high definition and easy to scan and the added bonus of translating the entered argument into Morse.
Developed in a bash scripting environment calling C++ codes within it.


Steps to follow to use the program:
-----------------------------------
1- have g++ installed if not intalled:
sudo apt update
sudo apt install build-essential
Then you have to compile the c++ files along with their libraries, which, if you have everything in the same folder, just copy and paste these simple commands
```C++
g++ MorseTranslator.cpp -o salidaM.out
g++ -Wall Qrcode.cpp qrcodegen.cpp qrcodegen.hpp -o salidaQ.out

```


Work elabored by: Maximo Aguirre, Franco Baldi, Tomas Fain and Moreira Mateo
we used the nayuki library for QR Code;
[https://www.nayuki.io/page/qr-code-generator-library](https://www.nayuki.io/page/qr-code-generator-library)

