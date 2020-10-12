CC = gcc
FLAGS = -g
OPTIMIZE =
LIBS = -ly -ll -lm

# Directory for Lex and Yacc
GRAMMAR_DIR = LexAndYacc
TREE_DIR = ParseTree

CCFLAGS = $(FLAGS) $(OPTIMIZE)

# Object files to build
GPC_OBJS = mainp.o ParsePascal.o
TREE_OBJS = List/List.o $(TREE_DIR)/tree.o
TREE_OBJS_1 = List.o tree.o

PARSER_OBJS = $(GRAMMAR_DIR)/lex.yy.o $(GRAMMAR_DIR)/y.tab.o
ALL_OBJS = $(GPC_OBJS) $(TREE_OBJS) $(PARSER_OBJS)

BIN = fuckyou

######## THE MAIN BUILD RULES ###########
release: lexAndYacc parser bin

debug_flexbison: debugFlexBison bin 
debug_bison: bisonDebug parser bin
debug_flex: flexDebug parser bin


############ MAKING OBJS #############
# Making all the objects and bins across directories
# Please no touch :)

bin: $(GPC_OBJS) $(TREE_OBJS_1) $(PARSER_OBJS)
	$(CC) $(CCFLAGS) -o $(BIN) $(GPC_OBJS) $(TREE_OBJS_1) $(PARSER_OBJS) -ll

mainp.o: ParsePascal.o mainp.c
	gcc -g -c mainp.c

parser: $(ALL_OBJS) ParsePascal.o

ParsePascal.o: $(PARSER_OBJS) $(TREE_OBJS) ParsePascal.h ParsePascal.c
	$(CC) $(CCFLAGS) -c ParsePascal.c

#ParsePascal.o: $(PARSER_OBJS) $(TREE_OBJS) ParsePascal.h ParsePascal.c
#	$(CC) $(CCFLAGS) -DDEBUG_BISON -c ParsePascal.c

List/List.o:
	$(CC) $(CCFLAGS) -c List/List.c


$(TREE_DIR)/tree.o:
	$(CC) $(CCFLAGS) -c $(TREE_DIR)/tree.c

lexAndYacc:
	cd $(GRAMMAR_DIR) && $(MAKE)

debugFlexBison:
	cd $(GRAMMAR_DIR) && $(MAKE) flexDebug
	CCFLAGS += -DDEBUG_BISON

bisonDebug:
	cd $(GRAMMAR_DIR) && $(MAKE)
	CCFLAGS += -DDEBUG_BISON

flexDebug:
	cd $(GRAMMAR_DIR) && $(MAKE) flexDebug



############ CLEANING ##########3
clean: clean_fuckyou clean_parser clean_LexYacc
clean_fuckyou:
	rm -f fuckyou
clean_parser:
	rm -f $(ALL_OBJS) *.o
clean_LexYacc:
	cd $(GRAMMAR_DIR) && $(MAKE) clean
