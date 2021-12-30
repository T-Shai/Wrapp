CC = g++

# REALEASE
FLAG 	= -O3 -fopenmp
FLAG   += -DNDEBUG

# DEBUG
FLAG 	= -g
FLAG   += -Wall -Werror -Wfatal-errors -pedantic


LINK 	= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image


INCLUDES 	= 	Makefile Window.h Clock.h Mouse.h Shape.h
OBJS 		= 	main.o Window.o Clock.o Mouse.o Shape.o
BIN 		= 	main

##################################################

run : $(BIN) $(INCLUDES)
	./$(BIN)

$(BIN) : $(OBJS) $(INCLUDES)
	$(CC) $(FLAG) $(OBJS) $(LINK) -o $(BIN)

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAG) -c $< $(LINK) -o $@

clean : 
	rm $(OBJS) $(BIN) $(IMGS)