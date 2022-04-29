# Compiler
CC = gcc

# Delete function
RM = del /f /q

# Additional includes directories
IDIR = /SDL2/include

# Set paths to src files
SDIR = src

# Set path to bin folder
BDIR = bin

# Set paths to obj files
ODIR = obj
_OBJS = game.o
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

# Set paths to debug obj files
DODIR = dobj
_DOBJS = game_d.o
DOBJS = $(patsubst %, $(DODIR)/%, $(_DOBJS))

# Set paths to lib files
LDIR = /SDL2/lib/x86/
_LIBS = SDL2.lib SDL2main.lib SDL2_image.lib SDL2.dll
LIBS = $(patsubst %, $(LDIR)/%, $(_LIBS))

# default flags (don't want many)
CFLAGS = -c -I$(IDIR)

# build game.exe (release)
game: $(OBJS) $(LIBS) 
	$(CC) $^ -o $(BDIR)/game.exe  

# build game_d.exe (debug)
game_d: $(DOBJS) $(LIBS) 
	$(CC) $^ -o %(BDIR)/game_d.exe 

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@ 

$(DODIR)/%.o: $(SDIR)/%.c
	$(CC) -ggdb $(CFLAGS) -o $@ $<

.phony: clean
clean:
	$(RM) $(ODIR)\\*
	$(RM) $(DODIR)\\*
	$(RM) $(BIN)\\*.exe






	



















