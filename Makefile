# cGraph

PROJECT_NAME =? cGraph

.PHONY = compile clear

compile:
	gcc -o CGraph.out -O3 main.c
	
clean:
	rm -f CGraph.out
