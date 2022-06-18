all:main Server Task
	g++ main.o Server.o Task.o -o main
main:main.cpp
	g++ -c main.cpp -o main.o
Server:Server.cpp
	g++ -c Server.cpp -o Server.o
Task:Task.cpp
	g++ -c Task.cpp -o Task.o
clean:
	del *.o 