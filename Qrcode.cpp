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
static void doBasicDemo();
static std::string toSvgString(const QrCode &qr, int border);
static void printQr(const QrCode &qr);

// The main application program.
int main()
{

	doBasicDemo();
	return 0;
}

/*---- Demo suite ----*/

// Creates a single QR Code, then prints it to the console.
static void doBasicDemo()
{
	string arg = getenv("ARGUMENTO");
	const char *text = arg.data();					 // User-supplied text
	const QrCode::Ecc errCorLvl = QrCode::Ecc::HIGH; // Error correction level

	// Make and print the QR Code symbol
	const QrCode qr = QrCode::encodeText(text, errCorLvl);
	printQr(qr);
	cout << toSvgString(qr, 4) << endl;
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

// Printea el codigo QR en la consola
static void printQr(const QrCode &qr)
{
	int border = 2;
	for (int y = -border; y < qr.getSize() + border; y++)
	{
		for (int x = -border; x < qr.getSize() + border; x++)
		{
			cout << (qr.getModule(x, y) ? "███" : "   ");
		}
		cout << endl;
	}
}
