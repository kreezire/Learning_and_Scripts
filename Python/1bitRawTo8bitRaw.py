import os
filename = "Z:\\users\\adikumar\\Xcases\\maah_frame_1bit_box_rectfill_black_up.raw"
outfile=open("out.raw",'w')
with open(filename) as f:
	data = f.read().strip()
	for c in data:
	#while True:
		#c = f.read(1)
		if not c:
			print "End of file"
			break
		#print c
		digit = ord(c) & (int('0b000001', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b000010', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b000100', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b001000', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b010000', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b100000', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b1000000', 2))
		outfile.write(chr(digit))
		digit = ord(c) & (int('0b10000000', 2))
		outfile.write(chr(digit))
		#print digit
	outfile.close()
	print "Read a character:", c

