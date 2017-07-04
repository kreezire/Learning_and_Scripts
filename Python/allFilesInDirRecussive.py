import os
from glob import glob

files = []
start_dir = "Z:\\users\\vipaggar\\124917_Callgrind"#os.getcwd()
pattern   = "*.out"#"*.log"

for dir,_,_ in os.walk(start_dir):
    files.extend(glob(os.path.join(dir,pattern))) 
#sprint files