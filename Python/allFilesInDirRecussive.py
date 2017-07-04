import os
from glob import glob

files = []
start_dir = "/devdisk/users/vipaggar/output/callgrindData/"#os.getcwd()
pattern   = "*.out"#"*.log"

for dir,_,_ in os.walk(start_dir):
    files.extend(glob(os.path.join(dir,pattern))) 
#sprint files

for file in files:
	print "callgrind_annotate --tree=caller " + file + " &> /devdisk/users/vipaggar/output/callgrindData/annotated/"+os.path.basename(file)
	os.system("callgrind_annotate --tree=caller " + file + " &> /devdisk/users/vipaggar/output/callgrindData/annotated/"+os.path.basename(file))