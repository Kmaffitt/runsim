all: runsim testsim

runsim:
	gcc -Wall -o runsim runsim.c

testsim:
	gcc -Wall -o testsim testsim.c
clean:
	rm runsim testsim