headerpath = include/
objpath = obj/
sourcepath = src/
OBJ = Character.o Inventory.o Item.o Team.o Equipment.o Classes.o
FILE = Prat3
LFLAGS = -lm

all: $(OBJ)
	g++ -std=c++11 -o $(FILE) $(sourcepath)$(FILE).cpp $(objpath)*.o -I $(headerpath) $(LFLAGS)

Character.o: Inventory.o Item.o
	g++ -std=c++11 -c $(sourcepath)Character.cpp -I $(headerpath) -o $(objpath)Character.o $(LFLAGS)
Inventory.o: Item.o
	g++ -std=c++11 -c $(sourcepath)Inventory.cpp -I $(headerpath) -o $(objpath)Inventory.o $(LFLAGS)
Item.o: 
	g++ -std=c++11 -c $(sourcepath)Item.cpp -I $(headerpath) -o $(objpath)Item.o $(LFLAGS)
Team.o: Character.o Loja.o
	g++ -std=c++11 -c $(sourcepath)Team.cpp -I $(headerpath) -o $(objpath)Team.o $(LFLAGS)
Equipment.o: Item.o
	g++ -std=c++11 -c $(sourcepath)Equipment.cpp -I $(headerpath) -o $(objpath)Equipment.o $(LFLAGS)
Classes.o: Character.o
	g++ -std=c++11 -c $(sourcepath)Classes.cpp -I $(headerpath) -o $(objpath)Classes.o $(LFLAGS)
Loja.o:
	g++ -std=c++11 -c $(sourcepath)Loja.cpp -I $(headerpath) -o $(objpath)Loja.o $(LFLAGS)

clean:
	rm -rf *o $(FILE)
	rm -rf $(objpath)*.o
run:
	./$(FILE)
