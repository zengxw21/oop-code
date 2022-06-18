all:main product sum
	g++  main.o product.o sum.o -o main
main:main.cpp
	g++ -c  main.cpp -o main.o
product:product.cpp
	g++ -c  product.cpp -o product.o
sum:sum.cpp
	g++ -c  sum.cpp -o sum.o
clean:
	del *.o main.exe
debug:main1 product1 sum1
	g++  main1.o product1.o sum1.o -o main
main1:main.cpp
	g++ -c -D DEBUG main.cpp -o main1.o
product1:product.cpp
	g++ -c -D DEBUG product.cpp -o product1.o
sum1:sum.cpp
	g++ -c -D DEBUG sum.cpp -o sum1.o