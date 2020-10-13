VPATH = ./src
LIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system
CXXFLAGS = -I "./include" 
CXXFLAGS += -Wall -static-libstdc++ -static-libgcc
CXX := g++


CPPFLAGS ="-I../../SFML-2.5.1/include"
LDFLAGS ="-L../../SFML-2.5.1/lib"

program: Line.o Player.o Game.o main.o
	$(CXX) Line.o Player.o Game.o main.o -o ./bin/program $(LIBS) $(LDFLAGS) $(CPPFLAGS)

Line.o: Line.cpp
	$(CXX) -c $(CXXFLAGS) $< $(LIBS) $(LDFLAGS) $(CPPFLAGS)

Player.o: Player.cpp
	$(CXX) -c $(CXXFLAGS) $< $(LIBS) $(LDFLAGS) $(CPPFLAGS)

Game.o: Game.cpp
	$(CXX) -c $(CXXFLAGS) $< $(LIBS) $(LDFLAGS) $(CPPFLAGS)
		
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $< $(LIBS) $(LDFLAGS) $(CPPFLAGS)


clean:
	del *.o	
	del bin\*.exe 