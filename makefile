# Object files to either reference or create                          
# OBJECTS = Proj2.o Blackjack.o Deck.o Card.o Hand.o Player.o           
OBJECTS = *.cpp
# The executable file that will be created at the end                 
EXEC = Sudoku.out                                                      
# The flags to use for compilation                                    
FLAGS = -Wall --std=c++0x                                                        
# The code compiler to use for compilation                            
CC = g++                                                              

# Perform action on all object files (May or may not exist)           
all: $(OBJECTS)                                                       
# $(CC) $(FLAGS)  
		$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)