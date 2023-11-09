import barcode
from barcode import Code39
from barcode.writer import ImageWriter
import os # Importa la variable de entorno desde el bash
texto = os.environ["ARGUMENTO"] 
code = Code39(texto, writer=ImageWriter(),add_checksum=False) # Usa la funcion y declara que codificacion de barras utilizara
barcode_image = code.render() # renderiza la informacion de la variable enviada
barcode_image.show() # Convierte, hace y muestra el archivo temporal con el codigo de barras
