all: parabolico.o output

parabolico.o: parabolico.cpp ; g++ -c parabolico.cpp

output: parabolico.cpp ; g++ parabolico.o -o output ; ./output ; python3 animation.py

clean: ; rm *.o output *.csv *.gif
