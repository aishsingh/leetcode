# Read from the file file.txt and output the tenth line to stdout.

#!/usr/bin/bash
filename="file.txt"

sed '10!d' $filename
