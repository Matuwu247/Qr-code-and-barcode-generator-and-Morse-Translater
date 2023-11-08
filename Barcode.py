import barcode
from barcode import Code39
from barcode.writer import ImageWriter
import os
texto = os.environ["ARGUMENTO"]

code = Code39(texto, writer=ImageWriter())

barcode_image = code.render()
barcode_image.show()
