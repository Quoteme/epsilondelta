all: epsilondelta

# recompile everything (main.cpp, main.o, ... = *)
.PHONY: *

# $@ matches the target; $< matches the first dependent
epsilondelta: main.o
	g++ $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	g++ -c main.cpp

clean:
	rm main.o main
