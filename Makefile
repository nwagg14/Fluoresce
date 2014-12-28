CPP = clang++
LINK = clang++
LIBS = -lSDL2 -lSDL2_image
FLAGS = -Weverything -std=c++11 -c

all: game

game: game.o main.o entity.o
	$(LINK) $(LIBS) $^ -o $@

main.o: main.cpp Game.hpp
	$(CPP) $(FLAGS) main.cpp -o $@

entity.o: Entity.cpp Entity.hpp
	$(CPP) $(FLAGS) Entity.cpp -o $@

game.o: Game.cpp Game.hpp
	$(CPP) $(FLAGS) Game.cpp -o $@

clean:
	rm *.o
