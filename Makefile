CPP = clang++
LINK = clang++
LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image -g
FLAGS = -Weverything -std=c++11 -g -c

SRCDIR = src/
BINDIR = bin/

all: $(BINDIR)game

$(BINDIR)game: $(BINDIR)game.o $(BINDIR)main.o $(BINDIR)text.o $(BINDIR)entity.o $(BINDIR)menustate.o $(BINDIR)utils.o
	$(LINK) $(LIBS) $^ -o $@

$(BINDIR)main.o: $(SRCDIR)main.cpp $(SRCDIR)Game.hpp
	$(CPP) $(FLAGS) $(SRCDIR)main.cpp -o $@

$(BINDIR)entity.o: $(SRCDIR)Entity.cpp $(SRCDIR)Entity.hpp
	$(CPP) $(FLAGS) $(SRCDIR)Entity.cpp -o $@

$(BINDIR)game.o: $(SRCDIR)Game.cpp $(SRCDIR)Game.hpp
	$(CPP) $(FLAGS) $(SRCDIR)Game.cpp -o $@

$(BINDIR)text.o: $(SRCDIR)Text.cpp $(SRCDIR)Text.hpp
	$(CPP) $(FLAGS) $(SRCDIR)Text.cpp -o $@

$(BINDIR)utils.o: $(SRCDIR)Utils.cpp $(SRCDIR)Utils.hpp
	$(CPP) $(FLAGS) $(SRCDIR)Utils.cpp -o $@

$(BINDIR)menustate.o: $(SRCDIR)MenuState.cpp $(SRCDIR)MenuState.hpp $(SRCDIR)State.hpp
	$(CPP) $(FLAGS) $(SRCDIR)MenuState.cpp -o $@


clean:
	rm $(BINDIR)*.o
