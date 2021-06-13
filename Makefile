#target all

all: ls mkdir rm cat date shell output

ls:
	gcc -o ls ls.c
	
mkdir: 
	gcc -o mkdir mkdir.c
	
rm:
	gcc -o rm rm.c 

cat:
	gcc -o cat cat.c
	
date:
	gcc -o date date.c

shell:
	gcc q2.c

output:
	./a.out
