from PIL import Image
import sys
import numpy as np

#im = Image.open("fsociety40.jpg")
#pix = im.load()
#for r in range(0,40):
#	for c in range(0,40):
#		if(pix[r,c][0] > 127):
#			sys.stdout.write(str(hex(255))+',')
#		else:
#			sys.stdout.write(str(hex(0))+',')

#im = Image.open("sonic_small_888_trans.png")
im = Image.open("intro.png")
pix = im.load()

red = np.uint8(0)
green = np.uint8(0)
blue = np.uint8(0)

color = np.uint16((red << (5 + 6)) | (green << 5) | blue)

for r in range(0,300):
	for c in range(0,400):
		red = np.uint8(pix[c,r][0]) >> 3
		green = np.uint8(pix[c,r][1]) >> 2
		blue = np.uint8(pix[c,r][2]) >> 3
		color = np.uint16((red << (5 + 6)) | (green << 5) | blue)
		sys.stdout.write(str(hex(color))+',')
		#print "%d" % pix[r,c][1]