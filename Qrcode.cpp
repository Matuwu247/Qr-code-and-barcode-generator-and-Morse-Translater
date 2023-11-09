#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "qrcodegen.hpp"
using namespace std;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
using std::uint8_t; 

// Function prototypes
static void doBasicDemo(); //declara la funcion dobasicdemo
static std::string toSvgString(const QrCode &qr, int border); // declara la funcion para transformar de string a Svg
static void printQr(const QrCode &qr); // declara la funcion para dibujar en consola el QR

int main()
{
	doBasicDemo(); // hace el qr ;D
	return 0;
}

// Crea el QR, y llamando otra funcion lo muestra 
static void doBasicDemo()
{
	string arg = getenv("ARGUMENTO"); // consigue la variable de entorno y la pasa a arg
	const char *text = arg.data(); 	// convierte la informacion recibida del bash a datos
	const QrCode::Ecc errCorLvl = QrCode::Ecc::HIGH; // pone el qr en calidad alta

	// Make and print the QR Code symbol
	const QrCode qr = QrCode::encodeText(text, errCorLvl); // genera el qr
	printQr(qr); // dibuja el QR
}

/*---- Utilities ----*/

// convierte el texto en SVG (Tipo de archivo utilizado por HTML)
static std::string toSvgString(const QrCode &qr, int border)
{
	if (border < 0)
		throw std::domain_error("Border must be non-negative");
	if (border > INT_MAX / 2 || border * 2 > INT_MAX - qr.getSize())
		throw std::overflow_error("Border too large");
	ostringstream sb;
	return sb.str();
}

// dibuja el codigo QR en la consola
static void printQr(const QrCode &qr)
{
	int border = 2;		
	cout << "\t\t\t";
	for (int y = -border; y < qr.getSize() + border; y++)
	{
		for (int x = -border; x < qr.getSize() + border; x++)
		{
			cout << (qr.getModule(x, y) ? "███" : "   ");
		}
		cout << endl;
		cout << "\t\t\t";
	}
}
