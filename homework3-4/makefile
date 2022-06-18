all:main tarnished normal_smithing_stone somber_smithing_stone normal_weapon somber_weapon weapon smithing_stone
	g++ main.o tarnished.o normal_smithing_stone.o somber_smithing_stone.o normal_weapon.o somber_weapon.o weapon.o smithing_stone.o -o main
main:main.cpp
	g++ -c main.cpp -o main.o
tarnished:tarnished.cpp
	g++ -c tarnished.cpp -o tarnished.o
normal_smithing_stone:normal_smithing_stone.cpp
	g++ -c normal_smithing_stone.cpp -o normal_smithing_stone.o
somber_smithing_stone:somber_smithing_stone.cpp
	g++ -c somber_smithing_stone.cpp -o somber_smithing_stone.o
normal_weapon:normal_weapon.cpp
	g++ -c normal_weapon.cpp -o normal_weapon.o
somber_weapon:somber_weapon.cpp
	g++ -c somber_weapon.cpp -o somber_weapon.o
weapon:weapon.cpp
	g++ -c weapon.cpp -o weapon.o
smithing_stone:smithing_stone.cpp
	g++ -c smithing_stone.cpp -o smithing_stone.o
clean:
	del *.o