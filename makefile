Sort.exe: Driver.o Insert.o Bubble.o
	g++ Driver.o Insert.o Bubble.o -o Sort.exe

Driver.o: Driver.cpp	
	g++ -c Driver.cpp -o Driver.o

Insert.o: Insert.cpp	
	g++ -c Insert.cpp -o Insert.o
	
Bubble.o: Bubble.cpp
	g++ -c Bubble.cpp -o Bubble.o	
	
clean:
	rm -rf  *o *.exe
