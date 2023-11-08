# Qr-code-and-barcode-generator-and-Morse-Translater
Introduction
------------
This project has been created for project in the fifth year of the technical secondary school of San Judas Tadeo in Ituzaingo, Buenos Aires Argentina. The main objective was to find a way to place the arguments and manipulate them from the Linux command line using any Linux distro.


Features
--------
It can generate the QR code or Barcode of any text you place in high definition and easy to scan and the added bonus of translating the entered argument into Morse.
Developed in a bash scripting environment calling C++ and python programs within it.


Steps to follow to use the program:
-----------------------------------
execute setup.sh or follow the instructions:

1- have g++ and python installed if not intalled:
sudo su
apt update
apt install build-essential
sudo apt install python3

install python libraries for barcode
pip install python-barcode
apt install dbus-x11

Then you have to compile the c++ files along with their libraries, which, if you have everything in the same folder, just copy and paste these simple commands
```C++
g++ MorseTranslator.cpp -o salidaM.out
g++ -Wall Qrcode.cpp qrcodegen.cpp qrcodegen.hpp -o salidaQ.out

```


Work elabored by: Maximo Aguirre, Franco Baldi, Tomas Fain and Moreira Mateo
we used the nayuki library for QR Code;
https://github.com/nayuki/QR-Code-generator.git
and the WhyNotHugo library for BarCode;
https://github.com/WhyNotHugo/python-barcode.git
](https://github.com/WhyNotHugo/python-barcode.git)https://github.com/WhyNotHugo/python-barcode.git
