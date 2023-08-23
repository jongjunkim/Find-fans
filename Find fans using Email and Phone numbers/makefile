COURSE = cs240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 4

# Change the following to your own information
LASTNAME = Kim
GITUSERID = jongjunkim

# The name of the executable
EXE = fans

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(BIN)/$(EXE)

# Reflects how the files may have been named in CP0
$(BIN)/$(EXE): $(OBJ)/fans.o $(OBJ)/Email.o $(OBJ)/Fan.o $(OBJ)/LinkedList.o $(OBJ)/Phone.o 
	$(CC) $(FLAGS) $(OBJ)/Email.o $(OBJ)/Fan.o $(OBJ)/LinkedList.o $(OBJ)/Phone.o $(OBJ)/fans.o -o $@

$(OBJ)/fans.o: fans.cpp Fan.h LinkedList.h Parser.h BST.h
	$(CC) $(FLAGS) -c fans.cpp -o $@

$(OBJ)/Email.o: Email.cpp Email.h
	$(CC) $(FLAGS) -c Email.cpp -o $@

$(OBJ)/Fan.o: Fan.cpp Fan.h Phone.h Email.h
	$(CC) $(FLAGS) -c Fan.cpp -o $@

$(OBJ)/Phone.o: Phone.cpp Phone.h
	$(CC) $(FLAGS) -c Phone.cpp -o $@

$(OBJ)/LinkedList.o: LinkedList.cpp LinkedList.h Fan.h
	$(CC) $(FLAGS) -c LinkedList.cpp -o $@

# Update to add targets for your other .o files, following the Play.o sample

# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz