/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 5 "Grammar.y"
    #include <stdio.h>
    #include <stdlib.h>
    #include "../ErrVars.h"
    #include "../ParseTree/tree.h"
    #include "../ParseTree/tree_types.h"
    #include "../List/List.h"
    #include "y.tab.h"

    /*extern FILE *yyin;*/
    extern int yylex();
#line 17 "Grammar.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
    /* Numbers */
    int i_val;
    float f_val;
    char *char_val;
    /* Operators */
    int op_val;

    /* Simple id without a line number */
    char *id;

    /* Identifier with line number */
    struct ident
    {
        char *id;
        int line_num;
    } ident;

    /* Ident list with line numbers */
    struct ident_list
    {
        ListNode_t *list;
        int line_num;
    } ident_list;


    /* For Types */
    struct Type
    {
        int type;

        /* For arrays */
        int actual_type;
        int start;
        int end;
    } type_s;

    /* For Subprogram Headers */
    struct SubprogramHead
    {
        int sub_type;

        char *id;
        ListNode_t *args;
        int line_num;
        int return_type; /* -1 if procedure */
    } subprogram_head_s;

    /* For the for_assign rule */
    struct ForAssign
    {
        int assign_type;
        union for_assign_bison
        {
            struct Statement *stmt;
            struct Expression *expr;
        } for_assign_bison_union;
    } for_assign_bison;

    /* Tree pointers */
    Tree_t *tree;
    struct Statement *stmt;
    struct Expression *expr;

    /* List */
    ListNode_t *list;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 107 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PROGRAM 257
#define VARIABLE 258
#define PROCEDURE 259
#define FUNCTION 260
#define BBEGIN 261
#define END 262
#define INT_NUM 263
#define REAL_NUM 264
#define INT_TYPE 265
#define REAL_TYPE 266
#define CHAR_TYPE 267
#define CHAR_VAL 268
#define ID 269
#define ARRAY 270
#define SINGLE 271
#define OF 272
#define DOTDOT 273
#define IF 274
#define THEN 275
#define ELSE 276
#define WHILE 277
#define DO 278
#define NOT 279
#define FOR 280
#define TO 281
#define END_OF_FILE 282
#define ASSIGNOP 283
#define RELOP 284
#define EQ 285
#define NE 286
#define LT 287
#define LE 288
#define GT 289
#define GE 290
#define ADDOP 291
#define PLUS 292
#define MINUS 293
#define OR 294
#define MULOP 295
#define STAR 296
#define SLASH 297
#define AND 298
#define PAREN 299
#define VAR_ASSIGN 300
#define VAR 301
#define BUILTIN_ANY_TYPE 302
#define BOOL 303
#define UNKNOWN_TYPE 304
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   29,   30,   31,   32,   33,   34,   35,    1,    1,
    2,    2,    5,    5,    6,    6,    6,    3,    3,    7,
    8,    8,    9,    9,   10,   10,    4,   11,   11,   12,
   12,   13,   13,   13,   13,   13,   13,   16,   16,   14,
   17,   17,   18,   18,   15,   15,   19,   19,   20,   20,
   21,   21,   22,   22,   23,   24,   24,   25,   25,   26,
   26,   27,   27,   27,   27,   27,   27,   27,   27,   28,
};
static const YYINT yylen[] = {                            2,
   11,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    6,    0,    1,    8,    1,    1,    1,    3,    0,    4,
    6,    4,    3,    0,    3,    5,    3,    1,    0,    1,
    3,    1,    1,    1,    1,    4,    6,    4,    6,    3,
    1,    1,    1,    4,    1,    4,    3,    1,    3,    1,
    2,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    1,    4,    4,    1,    1,    1,    2,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    2,    0,    0,    0,    9,    0,    0,   12,
   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   12,    0,    0,    0,    0,    0,    0,   34,    0,    0,
   30,   32,   33,   35,    0,    0,    0,   18,    0,   15,
   16,   17,    0,    0,   13,    0,    0,    0,    3,    4,
    5,    0,   70,    0,    0,    0,   50,   52,   54,    0,
    0,   60,    0,    0,   65,   66,   67,    0,   41,    0,
    0,    0,   27,    0,    0,    0,    0,    1,    0,    0,
   11,    0,    0,   22,    0,   51,    0,    0,    0,    0,
    0,    6,    7,    0,    0,    8,    0,    0,   68,    0,
    0,    0,    0,   31,    0,    0,    0,    0,   20,    0,
    0,   23,    0,    0,   53,   69,    0,    0,   49,    0,
    0,   61,    0,    0,    0,   36,    0,   46,    0,   44,
    0,   25,    0,   21,    0,   64,   63,    0,    0,    0,
    0,   39,   37,    0,   26,    0,   14,
};
static const YYINT yydgoto[] = {                          2,
    6,   12,   14,   28,   44,   45,   20,   21,   47,   83,
   29,   30,   31,   32,   33,   34,   70,   35,   55,   56,
   57,   58,   59,  106,   60,   61,   62,   63,   64,   65,
   66,   67,   94,   95,   97,
};
static const YYINT yysindex[] = {                      -234,
 -238,    0,    0,    8, -238,  -16,    0,    4, -238,    0,
    0, -187, -238, -140,   10, -238, -238, -183,   53,   41,
    0, -154,   64,   64,   22,   22, -238,    0, -148,   49,
    0,    0,    0,    0, -155,  -30, -153,    0, -187,    0,
    0,    0,   40,   73,    0, -238,   75,   77,    0,    0,
    0,   22,    0,   22, -222, -165,    0,    0,    0, -218,
 -159,    0,   29,  -26,    0,    0,    0, -235,    0, -144,
 -155,   47,    0, -183,   29,   29,   29,    0, -140, -124,
    0,   43,  -20,    0, -143,    0,  -28,  -40, -183,   22,
   22,    0,    0,   29,   29,    0,   29,   29,    0,   29,
   29, -183,   29,    0, -151,   39, -151,  -85,    0, -131,
 -154,    0, -238,   84,    0,    0, -132, -165,    0, -151,
 -159,    0,  -35,   54,  -82,    0, -186,    0,   29,    0,
 -124,    0,   45,    0, -183,    0,    0, -183, -151,   52,
 -154,    0,    0, -126,    0, -143,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -134,    0,    0,    0,    0,    0, -115,    0,    0,
    0,    0,   89,   91,    0,    0,    0,    0,    0, -112,
    0,    0,    0,    0,    0,  -57,    0,    0, -134,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -7,    0,    0,    0,    0,
  -29,    0,    0,  -41,    0,    0,    0,    0,    0,    0,
 -130, -193,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -54,    0,   65,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -55,   -5,    0,  -15,
  -17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   74,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -6,  131,  114,    6,  -92,  -76,    0,    0,  130,    0,
    0,    0,  -42,  128,    0,    0,    0,  129,   -4,   67,
  -14,    0,    0,   58,  -19,   66,  -46,    0,   28,  -64,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 320
static const YYINT yytable[] = {                         62,
  116,   45,   62,   38,   40,  116,   15,  130,  114,   76,
  137,   58,  115,  100,   58,  110,   99,   62,  132,   19,
  112,   68,    1,   59,    8,   55,   59,    9,    4,   58,
    3,  104,    7,   48,   88,   47,   11,   86,  113,   82,
    7,   59,  102,   23,   24,   36,  117,    5,  145,   87,
  122,   62,   89,    9,   72,  105,  107,  108,   90,  126,
   77,   54,   10,   58,  101,   92,  140,   22,   98,  147,
   13,   90,   93,    7,  120,   59,  119,   18,  123,  128,
  107,  125,  129,  127,  109,    3,    9,   43,    9,   43,
   25,  138,  142,   26,  136,  143,   27,  129,   37,   38,
  111,   36,  141,   46,   93,   56,  133,   74,   56,  139,
   40,   41,   42,   73,   57,   43,   36,   57,   16,   17,
   18,   40,   41,   42,   19,   19,   19,   75,   78,   36,
   80,   81,   91,   84,   85,   96,  103,   77,   49,   93,
    7,  131,  134,  135,  144,  146,   29,   24,   24,   28,
   42,   39,   79,   48,   69,   71,  118,  124,    0,    0,
  121,    0,   36,    0,    0,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,   93,   38,   40,   93,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   45,    0,
   62,   40,    0,    0,    0,   43,   40,    0,    0,    0,
    0,    0,   58,   62,   62,    0,   62,    0,    0,   62,
    0,    0,   62,   92,   59,   58,   58,    0,   58,   62,
   93,   58,   62,   62,   58,   93,   62,   59,   59,   55,
   59,   58,   55,   59,   58,   90,   59,   48,   58,   47,
   48,    0,   47,   59,    0,    0,   59,    0,   55,    0,
   59,    0,   55,    0,   49,   50,   48,    0,   47,   51,
    3,   49,   50,    0,    0,    0,   51,    3,    0,    0,
   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   53,    0,    0,    0,    0,    0,    0,   53,
};
static const YYINT yycheck[] = {                         41,
   41,   59,   44,   59,   59,   41,   13,   93,   85,   40,
   93,   41,   41,   40,   44,   80,   63,   59,  111,   14,
   41,   26,  257,   41,   41,   41,   44,   44,    1,   59,
  269,   74,    5,   41,   54,   41,    9,   52,   59,   46,
   13,   59,  278,   16,   17,   18,   89,   40,  141,   54,
   97,   93,  275,   44,   27,   75,   76,   77,  294,  102,
   91,   40,   59,   93,   91,  284,  131,   58,   40,  146,
  258,  294,  291,   46,   94,   93,   91,  261,   98,   41,
  100,  101,   44,  103,   79,  269,   44,  281,   44,  283,
  274,  278,  135,  277,   41,  138,  280,   44,   46,   59,
   58,   74,   58,   40,  291,   41,  113,   59,   44,  129,
  265,  266,  267,  262,   41,  270,   89,   44,  259,  260,
  261,  265,  266,  267,  259,  260,  261,  283,  282,  102,
   91,   59,  298,   59,   58,  295,  281,   91,  263,  291,
  113,  273,   59,  276,   93,  272,  262,   59,   58,  262,
  281,   21,   39,   24,   27,   27,   90,  100,   -1,   -1,
   95,   -1,  135,   -1,   -1,  138,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,  291,  262,  262,  291,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,   -1,
  262,  276,   -1,   -1,   -1,  283,  281,   -1,   -1,   -1,
   -1,   -1,  262,  275,  276,   -1,  278,   -1,   -1,  281,
   -1,   -1,  284,  284,  262,  275,  276,   -1,  278,  291,
  291,  281,  294,  295,  284,  291,  298,  275,  276,  275,
  278,  291,  278,  281,  294,  294,  284,  275,  298,  275,
  278,   -1,  278,  291,   -1,   -1,  294,   -1,  294,   -1,
  298,   -1,  298,   -1,  263,  264,  294,   -1,  294,  268,
  269,  263,  264,   -1,   -1,   -1,  268,  269,   -1,   -1,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  291,   -1,   -1,   -1,   -1,   -1,   -1,  291,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 304
#define YYUNDFTOKEN 342
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"PROGRAM","VARIABLE","PROCEDURE","FUNCTION","BBEGIN","END","INT_NUM","REAL_NUM",
"INT_TYPE","REAL_TYPE","CHAR_TYPE","CHAR_VAL","ID","ARRAY","SINGLE","OF",
"DOTDOT","IF","THEN","ELSE","WHILE","DO","NOT","FOR","TO","END_OF_FILE",
"ASSIGNOP","RELOP","EQ","NE","LT","LE","GT","GE","ADDOP","PLUS","MINUS","OR",
"MULOP","STAR","SLASH","AND","PAREN","VAR_ASSIGN","VAR","BUILTIN_ANY_TYPE",
"BOOL","UNKNOWN_TYPE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : PROGRAM ident '(' identifier_list ')' ';' declarations subprogram_declarations compound_statement '.' END_OF_FILE",
"ident : ID",
"int_num : INT_NUM",
"real_num : REAL_NUM",
"char_val : CHAR_VAL",
"relop : RELOP",
"addop : ADDOP",
"mulop : MULOP",
"identifier_list : ident",
"identifier_list : identifier_list ',' ident",
"declarations : declarations VARIABLE identifier_list ':' type ';'",
"declarations :",
"type : standard_type",
"type : ARRAY '[' int_num DOTDOT int_num ']' OF standard_type",
"standard_type : INT_TYPE",
"standard_type : REAL_TYPE",
"standard_type : CHAR_TYPE",
"subprogram_declarations : subprogram_declarations subprogram_declaration ';'",
"subprogram_declarations :",
"subprogram_declaration : subprogram_head declarations subprogram_declarations compound_statement",
"subprogram_head : FUNCTION ident arguments ':' standard_type ';'",
"subprogram_head : PROCEDURE ident arguments ';'",
"arguments : '(' parameter_list ')'",
"arguments :",
"parameter_list : identifier_list ':' type",
"parameter_list : parameter_list ';' identifier_list ':' type",
"compound_statement : BBEGIN optional_statements END",
"optional_statements : statement_list",
"optional_statements :",
"statement_list : statement",
"statement_list : statement_list ';' statement",
"statement : variable_assignment",
"statement : procedure_statement",
"statement : compound_statement",
"statement : if_statement",
"statement : WHILE relop_expression DO statement",
"statement : FOR for_assign TO expression DO statement",
"if_statement : IF relop_expression THEN statement",
"if_statement : IF relop_expression THEN statement ELSE statement",
"variable_assignment : variable ASSIGNOP expression",
"for_assign : variable_assignment",
"for_assign : variable",
"variable : ident",
"variable : ident '[' expression ']'",
"procedure_statement : ident",
"procedure_statement : ident '(' expression_list ')'",
"relop_expression : relop_expression OR relop_and",
"relop_expression : relop_and",
"relop_and : relop_and AND relop_not",
"relop_and : relop_not",
"relop_not : NOT relop_not",
"relop_not : relop_paren",
"relop_paren : '(' relop_expression ')'",
"relop_paren : relop_expression_single",
"relop_expression_single : expression relop expression",
"expression_list : expression",
"expression_list : expression_list ',' expression",
"expression : term",
"expression : expression addop term",
"term : factor",
"term : term mulop factor",
"factor : ident",
"factor : ident '[' expression ']'",
"factor : ident '(' expression_list ')'",
"factor : int_num",
"factor : real_num",
"factor : char_val",
"factor : sign factor",
"factor : '(' expression ')'",
"sign : ADDOP",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 579 "Grammar.y"

void yyerror(char *s)
{
    /*fprintf(stderr, "Error on line %d:%d\n", line_num, col_num);*/
    if(file_to_parse != NULL)
    {
        fprintf(stderr, "Error parsing %s:\n", file_to_parse);
        fprintf(stderr, "On line %d:\n", line_num);
    }
    else
        fprintf(stderr, "Error on line %d:\n", line_num);

    fprintf(stderr, "%s\n", s);
}
#line 489 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 200 "Grammar.y"
	{
         parse_tree = mk_program(yystack.l_mark[-9].ident.line_num, yystack.l_mark[-9].ident.id, yystack.l_mark[-7].ident_list.list, yystack.l_mark[-4].list, yystack.l_mark[-3].list, yystack.l_mark[-2].stmt);
         return -1;
     }
break;
case 2:
#line 208 "Grammar.y"
	{
            yyval.ident.id = yylval.id;
            yyval.ident.line_num = line_num;
        }
break;
case 3:
#line 215 "Grammar.y"
	{yyval.i_val = yylval.i_val;}
break;
case 4:
#line 219 "Grammar.y"
	{yyval.f_val = yylval.f_val;}
break;
case 5:
#line 223 "Grammar.y"
	{yyval.char_val = yylval.char_val;}
break;
case 6:
#line 227 "Grammar.y"
	{ yyval.op_val = yylval.op_val;}
break;
case 7:
#line 231 "Grammar.y"
	{yyval.op_val = yylval.op_val;}
break;
case 8:
#line 235 "Grammar.y"
	{yyval.op_val = yylval.op_val;}
break;
case 9:
#line 239 "Grammar.y"
	{
            yyval.ident_list.list = CreateListNode(yystack.l_mark[0].ident.id, LIST_STRING);
            yyval.ident_list.line_num = yystack.l_mark[0].ident.line_num; /* TODO: List of line nums */
        }
break;
case 10:
#line 244 "Grammar.y"
	{
            yyval.ident_list.list = PushListNodeBack(yystack.l_mark[-2].ident_list.list, CreateListNode(yystack.l_mark[0].ident.id, LIST_STRING));
            yyval.ident_list.line_num = yystack.l_mark[-2].ident_list.line_num;
        }
break;
case 11:
#line 252 "Grammar.y"
	{
            Tree_t *tree;
            if(yystack.l_mark[-1].type_s.type == ARRAY)
                tree = mk_arraydecl(yystack.l_mark[-3].ident_list.line_num, yystack.l_mark[-3].ident_list.list, yystack.l_mark[-1].type_s.actual_type, yystack.l_mark[-1].type_s.start, yystack.l_mark[-1].type_s.end);
            else
                tree = mk_vardecl(yystack.l_mark[-3].ident_list.line_num, yystack.l_mark[-3].ident_list.list, yystack.l_mark[-1].type_s.actual_type);

            if(yystack.l_mark[-5].list == NULL)
                yyval.list = CreateListNode(tree, LIST_TREE);
            else
                yyval.list = PushListNodeBack(yystack.l_mark[-5].list, CreateListNode(tree, LIST_TREE));
        }
break;
case 12:
#line 264 "Grammar.y"
	{yyval.list = NULL;}
break;
case 13:
#line 269 "Grammar.y"
	{
            yyval.type_s.type = SINGLE;
            yyval.type_s.actual_type = yystack.l_mark[0].i_val;
        }
break;
case 14:
#line 274 "Grammar.y"
	{
            yyval.type_s.type = ARRAY;
            yyval.type_s.actual_type = yystack.l_mark[0].i_val;
            yyval.type_s.start = yystack.l_mark[-5].i_val;
            yyval.type_s.end = yystack.l_mark[-3].i_val;
        }
break;
case 15:
#line 284 "Grammar.y"
	{yyval.i_val = INT_TYPE;}
break;
case 16:
#line 285 "Grammar.y"
	{yyval.i_val = REAL_TYPE;}
break;
case 17:
#line 286 "Grammar.y"
	{yyval.i_val = CHAR_TYPE;}
break;
case 18:
#line 291 "Grammar.y"
	{
            if(yystack.l_mark[-2].list == NULL)
                yyval.list = CreateListNode(yystack.l_mark[-1].tree, LIST_TREE);
            else
                yyval.list = PushListNodeBack(yystack.l_mark[-2].list, CreateListNode(yystack.l_mark[-1].tree, LIST_TREE));
        }
break;
case 19:
#line 297 "Grammar.y"
	{yyval.list = NULL;}
break;
case 20:
#line 305 "Grammar.y"
	{
            if(yystack.l_mark[-3].subprogram_head_s.sub_type == PROCEDURE)
                yyval.tree = mk_procedure(yystack.l_mark[-3].subprogram_head_s.line_num, yystack.l_mark[-3].subprogram_head_s.id, yystack.l_mark[-3].subprogram_head_s.args, yystack.l_mark[-2].list, yystack.l_mark[-1].list, yystack.l_mark[0].stmt);
            else
                yyval.tree = mk_function(yystack.l_mark[-3].subprogram_head_s.line_num, yystack.l_mark[-3].subprogram_head_s.id, yystack.l_mark[-3].subprogram_head_s.args, yystack.l_mark[-2].list, yystack.l_mark[-1].list, yystack.l_mark[0].stmt, yystack.l_mark[-3].subprogram_head_s.return_type);
        }
break;
case 21:
#line 315 "Grammar.y"
	{
            yyval.subprogram_head_s.sub_type = FUNCTION;
            yyval.subprogram_head_s.args = yystack.l_mark[-3].list;
            yyval.subprogram_head_s.return_type = yystack.l_mark[-1].i_val;

            yyval.subprogram_head_s.id = yystack.l_mark[-4].ident.id;
            yyval.subprogram_head_s.line_num = yystack.l_mark[-4].ident.line_num;
        }
break;
case 22:
#line 324 "Grammar.y"
	{
            yyval.subprogram_head_s.sub_type = PROCEDURE;
            yyval.subprogram_head_s.args = yystack.l_mark[-1].list;
            yyval.subprogram_head_s.return_type = -1;

            yyval.subprogram_head_s.id = yystack.l_mark[-2].ident.id;
            yyval.subprogram_head_s.line_num = yystack.l_mark[-2].ident.line_num;
        }
break;
case 23:
#line 335 "Grammar.y"
	{yyval.list = yystack.l_mark[-1].list;}
break;
case 24:
#line 336 "Grammar.y"
	{yyval.list = NULL;}
break;
case 25:
#line 341 "Grammar.y"
	{
            Tree_t *tree;
            if(yystack.l_mark[0].type_s.type == ARRAY)
                tree = mk_arraydecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type, yystack.l_mark[0].type_s.start, yystack.l_mark[0].type_s.end);
            else
                tree = mk_vardecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type);

            yyval.list = CreateListNode(tree, LIST_TREE);
        }
break;
case 26:
#line 351 "Grammar.y"
	{
            Tree_t *tree;
            if(yystack.l_mark[0].type_s.type == ARRAY)
                tree = mk_arraydecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type, yystack.l_mark[0].type_s.start, yystack.l_mark[0].type_s.end);
            else
                tree = mk_vardecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type);

            yyval.list = PushListNodeBack(yystack.l_mark[-4].list, CreateListNode(tree, LIST_TREE));
        }
break;
case 27:
#line 364 "Grammar.y"
	{
            yyval.stmt = mk_compoundstatement(line_num, yystack.l_mark[-1].list);
        }
break;
case 28:
#line 370 "Grammar.y"
	{yyval.list = yystack.l_mark[0].list;}
break;
case 29:
#line 371 "Grammar.y"
	{yyval.list = NULL;}
break;
case 30:
#line 376 "Grammar.y"
	{
            yyval.list = CreateListNode(yystack.l_mark[0].stmt, LIST_STMT);
        }
break;
case 31:
#line 380 "Grammar.y"
	{
            yyval.list = PushListNodeBack(yystack.l_mark[-2].list, CreateListNode(yystack.l_mark[0].stmt, LIST_STMT));
        }
break;
case 32:
#line 387 "Grammar.y"
	{
            yyval.stmt = yystack.l_mark[0].stmt;
        }
break;
case 33:
#line 391 "Grammar.y"
	{
            yyval.stmt = yystack.l_mark[0].stmt;
        }
break;
case 34:
#line 395 "Grammar.y"
	{
            yyval.stmt = yystack.l_mark[0].stmt;
        }
break;
case 35:
#line 399 "Grammar.y"
	{
            yyval.stmt = yystack.l_mark[0].stmt;
        }
break;
case 36:
#line 403 "Grammar.y"
	{
            yyval.stmt = mk_while(line_num, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt);
        }
break;
case 37:
#line 407 "Grammar.y"
	{
            if(yystack.l_mark[-4].for_assign_bison.assign_type == VAR_ASSIGN)
                yyval.stmt = mk_forassign(line_num, yystack.l_mark[-4].for_assign_bison.for_assign_bison_union.stmt, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt);
            else
                yyval.stmt = mk_forvar(line_num, yystack.l_mark[-4].for_assign_bison.for_assign_bison_union.expr, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt);
        }
break;
case 38:
#line 418 "Grammar.y"
	{
            yyval.stmt = mk_ifthen(line_num, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt, NULL);
        }
break;
case 39:
#line 422 "Grammar.y"
	{
            yyval.stmt = mk_ifthen(line_num, yystack.l_mark[-4].expr, yystack.l_mark[-2].stmt, yystack.l_mark[0].stmt);
        }
break;
case 40:
#line 428 "Grammar.y"
	{
            yyval.stmt = mk_varassign(line_num, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 41:
#line 434 "Grammar.y"
	{
            yyval.for_assign_bison.assign_type = VAR_ASSIGN;
            yyval.for_assign_bison.for_assign_bison_union.stmt = yystack.l_mark[0].stmt;
        }
break;
case 42:
#line 439 "Grammar.y"
	{
            yyval.for_assign_bison.assign_type = VAR;
            yyval.for_assign_bison.for_assign_bison_union.expr = yystack.l_mark[0].expr;
        }
break;
case 43:
#line 446 "Grammar.y"
	{
            yyval.expr = mk_varid(yystack.l_mark[0].ident.line_num, yystack.l_mark[0].ident.id);
        }
break;
case 44:
#line 450 "Grammar.y"
	{
            yyval.expr = mk_arrayaccess(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].expr);
        }
break;
case 45:
#line 457 "Grammar.y"
	{
            yyval.stmt = mk_procedurecall(yystack.l_mark[0].ident.line_num, yystack.l_mark[0].ident.id, NULL);
        }
break;
case 46:
#line 461 "Grammar.y"
	{
            yyval.stmt = mk_procedurecall(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].list);
        }
break;
case 47:
#line 470 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, OR, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 48:
#line 473 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 49:
#line 478 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, AND, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 50:
#line 481 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 51:
#line 486 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, NOT, yystack.l_mark[0].expr, NULL);
        }
break;
case 52:
#line 489 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 53:
#line 493 "Grammar.y"
	{yyval.expr = yystack.l_mark[-1].expr;}
break;
case 54:
#line 494 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 55:
#line 499 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, yystack.l_mark[-1].op_val, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 56:
#line 508 "Grammar.y"
	{
            yyval.list = CreateListNode(yystack.l_mark[0].expr, LIST_EXPR);
        }
break;
case 57:
#line 512 "Grammar.y"
	{
            yyval.list = PushListNodeBack(yystack.l_mark[-2].list, CreateListNode(yystack.l_mark[0].expr, LIST_EXPR));
        }
break;
case 58:
#line 518 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 59:
#line 520 "Grammar.y"
	{
            yyval.expr = mk_addop(line_num, yystack.l_mark[-1].op_val, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 60:
#line 526 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 61:
#line 528 "Grammar.y"
	{
            yyval.expr = mk_mulop(line_num, yystack.l_mark[-1].op_val, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 62:
#line 535 "Grammar.y"
	{
            yyval.expr = mk_varid(yystack.l_mark[0].ident.line_num, yystack.l_mark[0].ident.id);
        }
break;
case 63:
#line 539 "Grammar.y"
	{
            yyval.expr = mk_arrayaccess(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].expr);
        }
break;
case 64:
#line 543 "Grammar.y"
	{
            yyval.expr = mk_functioncall(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].list);
        }
break;
case 65:
#line 547 "Grammar.y"
	{
            yyval.expr = mk_inum(line_num, yystack.l_mark[0].i_val);
        }
break;
case 66:
#line 551 "Grammar.y"
	{
            yyval.expr = mk_rnum(line_num, yystack.l_mark[0].f_val);
        }
break;
case 67:
#line 555 "Grammar.y"
	{
            yyval.expr = mk_charval(line_num, yystack.l_mark[0].char_val);
        }
break;
case 68:
#line 559 "Grammar.y"
	{
            if(yystack.l_mark[-1].op_val == MINUS)
                yyval.expr = mk_signterm(line_num, yystack.l_mark[0].expr);
            else
                yyval.expr = yystack.l_mark[0].expr;
        }
break;
case 69:
#line 566 "Grammar.y"
	{
            yyval.expr = yystack.l_mark[-1].expr;
        }
break;
case 70:
#line 573 "Grammar.y"
	{
            yyval.op_val = yylval.op_val;
        }
break;
#line 1120 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
