LIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system
CXXFLAG = -I "./include"
LD_LIBRARY_PATH = "-L../SFML-2.5.1/lib"
CPPFLAGS ="-I../SFML-2.5.1/include"
LDFLAGS ="-L../SFML-2.5.1/lib"

all: thegame

Line.o:
	g++ $(CXXFLAG) -c ./src/Line.cpp -o Line.o $(LDFLAGS) $(CPPFLAGS)

Player.o: 
	g++ $(CXXFLAG) -c ./src/Player.cpp -o Player.o

Game.o: Game.cpp
	g++ $(CXXFLAG) -c ./src/Game.cpp -o Game.o
		
main.o: main.cpp
	g++ $(CXXFLAG) -c ./src/main.cpp -o main.o


thegame: Line.o Player.o Game.o main.o
	g++ -o thegame Line.o Player.o Game.o main.o $(LIBS)

clean:
	rm -f thegame *.o

install:
	@echo '** Installing...'
	cp thegame ./bin

uninstall:
	@echo '** Uninstalling...'
	rm -f ./bin/thegame