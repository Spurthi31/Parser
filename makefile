LEX = flex
YACC = byacc -v
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
TREE_OBJS = List.o tree.o
TREE_OBJS_1 = List.o tree.o

PARSER_OBJS = lex.yy.o y.tab.o
ALL_OBJS = $(GPC_OBJS) $(TREE_OBJS) $(PARSER_OBJS)

BIN = parserexec

######## THE MAIN BUILD RULES ###########
release: lex.yy.o y.tab.o parser bin

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

List.o:
	$(CC) $(CCFLAGS) -c List.c


tree.o:
	$(CC) $(CCFLAGS) -c tree.c


debugFlexBison:
	debug_lex.yy.o y.tab.o
	CCFLAGS += -DDEBUG_BISON

bisonDebug:
	lex.yy.o y.tab.o
	CCFLAGS += -DDEBUG_BISON

flexDebug:
	debug_lex.yy.o y.tab.o



lex.yy.o: lex.yy.c y.tab.h
	$(CC) $(CCFLAGS) -c lex.yy.c

y.tab.o: y.tab.c y.tab.h
	$(CC) $(CCFLAGS) -c y.tab.c

debug_lex.yy.o: lex.yy.c y.tab.h
	$(CC) $(CCFLAGS)  -c lex.yy.c

y.tab.c y.tab.h: Grammar.y
	$(YACC) -d Grammar.y

lex.yy.c: Tokenizer.l
	$(LEX) Tokenizer.l



############ CLEANING ##########3
clean: clean_parserexec clean_parser clean_LexYacc
clean_parserexec:
	rm -f parserexec
clean_parser:
	rm -f $(ALL_OBJS) *.o
clean_LexYacc:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output
