from PIL import Image, ImageFilter

before = Image.open("bridge.bmp") #  functions inside of structures in python
after = before.filter(ImageFilter.BoxBlur(1))

