CPP = clang++
LINK = clang++
LIBS = -lSDL2 -lSDL2_image -g
FLAGS = -Weverything -std=c++11 -g -c

all: game

game: game.o main.o utils.o entity.o menustate.o
	$(LINK) $(LIBS) $^ -o $@

main.o: main.cpp Game.hpp
	$(CPP) $(FLAGS) main.cpp -o $@

entity.o: Entity.cpp Entity.hpp
	$(CPP) $(FLAGS) Entity.cpp -o $@

game.o: Game.cpp Game.hpp
	$(CPP) $(FLAGS) Game.cpp -o $@

utils.o: Utils.cpp Utils.hpp
	$(CPP) $(FLAGS) Utils.cpp -o $@

menustate.o: MenuState.cpp MenuState.hpp State.hpp
	$(CPP) $(FLAGS) MenuState.cpp -o $@


clean:
	rm *.o
