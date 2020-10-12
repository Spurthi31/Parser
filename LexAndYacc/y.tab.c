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
#define ID 267
#define ARRAY 268
#define SINGLE 269
#define OF 270
#define DOTDOT 271
#define IF 272
#define THEN 273
#define ELSE 274
#define WHILE 275
#define DO 276
#define NOT 277
#define FOR 278
#define TO 279
#define END_OF_FILE 280
#define ASSIGNOP 281
#define RELOP 282
#define EQ 283
#define NE 284
#define LT 285
#define LE 286
#define GT 287
#define GE 288
#define ADDOP 289
#define PLUS 290
#define MINUS 291
#define OR 292
#define MULOP 293
#define STAR 294
#define SLASH 295
#define AND 296
#define PAREN 297
#define VAR_ASSIGN 298
#define VAR 299
#define BUILTIN_ANY_TYPE 300
#define BOOL 301
#define UNKNOWN_TYPE 302
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   29,   30,   31,   32,   33,   34,    1,    1,    2,
    2,    5,    5,    6,    6,    3,    3,    7,    8,    8,
    9,    9,   10,   10,    4,   11,   11,   12,   12,   13,
   13,   13,   13,   13,   13,   16,   16,   14,   17,   17,
   18,   18,   15,   15,   19,   19,   20,   20,   21,   21,
   22,   22,   23,   24,   24,   25,   25,   26,   26,   27,
   27,   27,   27,   27,   27,   27,   28,
};
static const YYINT yylen[] = {                            2,
   11,    1,    1,    1,    1,    1,    1,    1,    3,    6,
    0,    1,    8,    1,    1,    3,    0,    4,    6,    4,
    3,    0,    3,    5,    3,    1,    0,    1,    3,    1,
    1,    1,    1,    4,    6,    4,    6,    3,    1,    1,
    1,    4,    1,    4,    3,    1,    3,    1,    2,    1,
    3,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    4,    4,    1,    1,    2,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    2,    0,    0,    0,    8,    0,    0,   11,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   11,    0,    0,    0,    0,    0,    0,   32,    0,    0,
   28,   30,   31,   33,    0,    0,    0,   16,    0,   14,
   15,    0,    0,   12,    0,    0,    0,    3,    4,    0,
   67,    0,    0,    0,   48,   50,   52,    0,    0,   58,
    0,    0,   63,   64,    0,   39,    0,    0,    0,   25,
    0,    0,    0,    0,    1,    0,    0,   10,    0,    0,
   20,    0,   49,    0,    0,    0,    0,    0,    5,    6,
    0,    0,    7,    0,    0,   65,    0,    0,    0,    0,
   29,    0,    0,    0,    0,   18,    0,    0,   21,    0,
    0,   51,   66,    0,    0,   47,    0,    0,   59,    0,
    0,    0,   34,    0,   44,    0,   42,    0,   23,    0,
   19,    0,   62,   61,    0,    0,    0,    0,   37,   35,
    0,   24,    0,   13,
};
static const YYINT yydgoto[] = {                          2,
    6,   12,   14,   28,   43,   44,   20,   21,   46,   80,
   29,   30,   31,   32,   33,   34,   67,   35,   53,   54,
   55,   56,   57,  103,   58,   59,   60,   61,   62,   63,
   64,   91,   92,   94,
};
static const YYINT yysindex[] = {                      -231,
 -208,    0,    0,   53, -208,   -9,    0,   39, -208,    0,
    0, -155, -208, -150,    7, -208, -208, -186,   61,   59,
    0, -181,   81,   81,   15,   15, -208,    0, -140,   65,
    0,    0,    0,    0, -158,  -24, -154,    0, -155,    0,
    0,   34,   68,    0, -208,   69,   71,    0,    0,   15,
    0,   15, -248, -163,    0,    0,    0, -260, -161,    0,
   -3,  -23,    0,    0, -249,    0, -145, -158,   44,    0,
 -186,   -3,   -3,   -3,    0, -150, -127,    0,   13,  -11,
    0, -146,    0,  -35,   -1, -186,   15,   15,    0,    0,
   -3,   -3,    0,   -3,   -3,    0,   -3,   -3, -186,   -3,
    0, -152,   25, -152,  -88,    0, -133, -181,    0, -208,
   80,    0,    0, -134, -163,    0, -152, -161,    0,  -31,
   47,  -86,    0, -256,    0,   -3,    0, -127,    0,   38,
    0, -186,    0,    0, -186, -152,   48, -181,    0,    0,
 -128,    0, -146,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -147,    0,    0,    0,    0,    0, -119,    0,    0,
    0,    0,   86,   88,    0,    0,    0,    0,    0, -115,
    0,    0,    0,    0,    0,  -58,    0,    0, -147,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -27,    0,    0,    0,    0,  -20,    0,
    0,  -41,    0,    0,    0,    0,    0, -131, -164,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -57,    0,   56,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -55,   -5,    0,  -26,    1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   64,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -4,  128,  111,   -6,  -85,  -69,    0,    0,  127,    0,
    0,    0,  -52,  125,    0,    0,    0,  126,  -14,   67,
  -39,    0,    0,   60,    4,   66,  -30,    0,   45,  -49,
    0,    0,    0,    0,
};
#define YYTABLESIZE 304
static const YYINT yytable[] = {                         60,
   43,   38,   60,   36,  127,  112,  134,   19,   15,  113,
   83,   65,  111,   46,   53,   73,   97,   60,  101,  135,
   56,   89,  129,   56,   86,    1,   99,  107,   90,  109,
   96,    8,   90,  114,    9,   45,   95,   84,   56,  113,
   79,   57,   87,   87,   57,    4,  123,  110,  116,    7,
    9,   60,  142,   11,   52,   85,    9,    7,    3,   57,
   23,   24,   36,  119,   22,  125,   74,   98,  126,  106,
  108,   69,   56,  144,   18,  102,  104,  105,  137,  139,
    3,    9,  140,   40,   41,   25,   42,  133,   26,    7,
  126,   27,    5,   57,  117,  138,   54,   10,  120,   54,
  104,  122,   13,  124,   55,  130,   37,   55,   16,   17,
   18,   17,   17,   17,   41,   36,   41,   38,   40,   41,
   45,   70,   72,   71,   77,   75,   78,   81,   82,  136,
   36,   93,   88,  100,   74,   48,   90,  128,  131,  132,
  141,  143,   27,   36,   22,   22,   26,   40,   39,   76,
   47,   66,   68,  115,    7,    0,  121,  118,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,    0,    0,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   90,    0,   90,   43,   38,    0,   36,    0,    0,    0,
    0,    0,    0,    0,    0,   43,   38,    0,    0,    0,
   60,   38,   41,    0,    0,    0,    0,    0,    0,    0,
    0,   60,   60,    0,   60,    0,    0,   60,    0,    0,
   60,   56,    0,    0,    0,   46,   53,   60,   46,   53,
   60,   60,   56,   56,   60,   56,   87,   90,   56,   48,
   49,   56,   57,    3,   46,   53,    0,   45,   56,   53,
   45,   56,    0,   57,   57,   56,   57,   48,   49,   57,
   89,    3,   57,    0,    0,   51,   45,   90,    0,   57,
    0,   50,   57,    0,    0,    0,   57,    0,    0,    0,
    0,    0,    0,   51,
};
static const YYINT yycheck[] = {                         41,
   59,   59,   44,   59,   93,   41,   93,   14,   13,   41,
   50,   26,   82,   41,   41,   40,   40,   59,   71,  276,
   41,  282,  108,   44,  273,  257,  276,   77,  289,   41,
   61,   41,  289,   86,   44,   41,   40,   52,   59,   41,
   45,   41,  292,  292,   44,    1,   99,   59,   88,    5,
   44,   93,  138,    9,   40,   52,   44,   13,  267,   59,
   16,   17,   18,   94,   58,   41,   91,   91,   44,   76,
   58,   27,   93,  143,  261,   72,   73,   74,  128,  132,
  267,   44,  135,  265,  266,  272,  268,   41,  275,   45,
   44,  278,   40,   93,   91,   58,   41,   59,   95,   44,
   97,   98,  258,  100,   41,  110,   46,   44,  259,  260,
  261,  259,  260,  261,  279,   71,  281,   59,  265,  266,
   40,  262,  281,   59,   91,  280,   59,   59,   58,  126,
   86,  293,  296,  279,   91,  263,  289,  271,   59,  274,
   93,  270,  262,   99,   59,   58,  262,  279,   21,   39,
   24,   27,   27,   87,  110,   -1,   97,   92,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  132,   -1,   -1,  135,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  289,   -1,  289,  262,  262,   -1,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  274,   -1,   -1,   -1,
  262,  279,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  273,  274,   -1,  276,   -1,   -1,  279,   -1,   -1,
  282,  262,   -1,   -1,   -1,  273,  273,  289,  276,  276,
  292,  293,  273,  274,  296,  276,  292,  289,  279,  263,
  264,  282,  262,  267,  292,  292,   -1,  273,  289,  296,
  276,  292,   -1,  273,  274,  296,  276,  263,  264,  279,
  282,  267,  282,   -1,   -1,  289,  292,  289,   -1,  289,
   -1,  277,  292,   -1,   -1,   -1,  296,   -1,   -1,   -1,
   -1,   -1,   -1,  289,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 302
#define YYUNDFTOKEN 339
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
"INT_TYPE","REAL_TYPE","ID","ARRAY","SINGLE","OF","DOTDOT","IF","THEN","ELSE",
"WHILE","DO","NOT","FOR","TO","END_OF_FILE","ASSIGNOP","RELOP","EQ","NE","LT",
"LE","GT","GE","ADDOP","PLUS","MINUS","OR","MULOP","STAR","SLASH","AND","PAREN",
"VAR_ASSIGN","VAR","BUILTIN_ANY_TYPE","BOOL","UNKNOWN_TYPE",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : PROGRAM ident '(' identifier_list ')' ';' declarations subprogram_declarations compound_statement '.' END_OF_FILE",
"ident : ID",
"int_num : INT_NUM",
"real_num : REAL_NUM",
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
#line 567 "Grammar.y"

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
#line 481 "y.tab.c"

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
#line 197 "Grammar.y"
	{
         parse_tree = mk_program(yystack.l_mark[-9].ident.line_num, yystack.l_mark[-9].ident.id, yystack.l_mark[-7].ident_list.list, yystack.l_mark[-4].list, yystack.l_mark[-3].list, yystack.l_mark[-2].stmt);
         return -1;
     }
break;
case 2:
#line 205 "Grammar.y"
	{
            yyval.ident.id = yylval.id;
            yyval.ident.line_num = line_num;
        }
break;
case 3:
#line 212 "Grammar.y"
	{yyval.i_val = yylval.i_val;}
break;
case 4:
#line 216 "Grammar.y"
	{yyval.f_val = yylval.f_val;}
break;
case 5:
#line 220 "Grammar.y"
	{ yyval.op_val = yylval.op_val;}
break;
case 6:
#line 224 "Grammar.y"
	{yyval.op_val = yylval.op_val;}
break;
case 7:
#line 228 "Grammar.y"
	{yyval.op_val = yylval.op_val;}
break;
case 8:
#line 232 "Grammar.y"
	{
            yyval.ident_list.list = CreateListNode(yystack.l_mark[0].ident.id, LIST_STRING);
            yyval.ident_list.line_num = yystack.l_mark[0].ident.line_num; /* TODO: List of line nums */
        }
break;
case 9:
#line 237 "Grammar.y"
	{
            yyval.ident_list.list = PushListNodeBack(yystack.l_mark[-2].ident_list.list, CreateListNode(yystack.l_mark[0].ident.id, LIST_STRING));
            yyval.ident_list.line_num = yystack.l_mark[-2].ident_list.line_num;
        }
break;
case 10:
#line 245 "Grammar.y"
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
case 11:
#line 257 "Grammar.y"
	{yyval.list = NULL;}
break;
case 12:
#line 262 "Grammar.y"
	{
            yyval.type_s.type = SINGLE;
            yyval.type_s.actual_type = yystack.l_mark[0].i_val;
        }
break;
case 13:
#line 267 "Grammar.y"
	{
            yyval.type_s.type = ARRAY;
            yyval.type_s.actual_type = yystack.l_mark[0].i_val;
            yyval.type_s.start = yystack.l_mark[-5].i_val;
            yyval.type_s.end = yystack.l_mark[-3].i_val;
        }
break;
case 14:
#line 277 "Grammar.y"
	{yyval.i_val = INT_TYPE;}
break;
case 15:
#line 278 "Grammar.y"
	{yyval.i_val = REAL_TYPE;}
break;
case 16:
#line 283 "Grammar.y"
	{
            if(yystack.l_mark[-2].list == NULL)
                yyval.list = CreateListNode(yystack.l_mark[-1].tree, LIST_TREE);
            else
                yyval.list = PushListNodeBack(yystack.l_mark[-2].list, CreateListNode(yystack.l_mark[-1].tree, LIST_TREE));
        }
break;
case 17:
#line 289 "Grammar.y"
	{yyval.list = NULL;}
break;
case 18:
#line 297 "Grammar.y"
	{
            if(yystack.l_mark[-3].subprogram_head_s.sub_type == PROCEDURE)
                yyval.tree = mk_procedure(yystack.l_mark[-3].subprogram_head_s.line_num, yystack.l_mark[-3].subprogram_head_s.id, yystack.l_mark[-3].subprogram_head_s.args, yystack.l_mark[-2].list, yystack.l_mark[-1].list, yystack.l_mark[0].stmt);
            else
                yyval.tree = mk_function(yystack.l_mark[-3].subprogram_head_s.line_num, yystack.l_mark[-3].subprogram_head_s.id, yystack.l_mark[-3].subprogram_head_s.args, yystack.l_mark[-2].list, yystack.l_mark[-1].list, yystack.l_mark[0].stmt, yystack.l_mark[-3].subprogram_head_s.return_type);
        }
break;
case 19:
#line 307 "Grammar.y"
	{
            yyval.subprogram_head_s.sub_type = FUNCTION;
            yyval.subprogram_head_s.args = yystack.l_mark[-3].list;
            yyval.subprogram_head_s.return_type = yystack.l_mark[-1].i_val;

            yyval.subprogram_head_s.id = yystack.l_mark[-4].ident.id;
            yyval.subprogram_head_s.line_num = yystack.l_mark[-4].ident.line_num;
        }
break;
case 20:
#line 316 "Grammar.y"
	{
            yyval.subprogram_head_s.sub_type = PROCEDURE;
            yyval.subprogram_head_s.args = yystack.l_mark[-1].list;
            yyval.subprogram_head_s.return_type = -1;

            yyval.subprogram_head_s.id = yystack.l_mark[-2].ident.id;
            yyval.subprogram_head_s.line_num = yystack.l_mark[-2].ident.line_num;
        }
break;
case 21:
#line 327 "Grammar.y"
	{yyval.list = yystack.l_mark[-1].list;}
break;
case 22:
#line 328 "Grammar.y"
	{yyval.list = NULL;}
break;
case 23:
#line 333 "Grammar.y"
	{
            Tree_t *tree;
            if(yystack.l_mark[0].type_s.type == ARRAY)
                tree = mk_arraydecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type, yystack.l_mark[0].type_s.start, yystack.l_mark[0].type_s.end);
            else
                tree = mk_vardecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type);

            yyval.list = CreateListNode(tree, LIST_TREE);
        }
break;
case 24:
#line 343 "Grammar.y"
	{
            Tree_t *tree;
            if(yystack.l_mark[0].type_s.type == ARRAY)
                tree = mk_arraydecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type, yystack.l_mark[0].type_s.start, yystack.l_mark[0].type_s.end);
            else
                tree = mk_vardecl(yystack.l_mark[-2].ident_list.line_num, yystack.l_mark[-2].ident_list.list, yystack.l_mark[0].type_s.actual_type);

            yyval.list = PushListNodeBack(yystack.l_mark[-4].list, CreateListNode(tree, LIST_TREE));
        }
break;
case 25:
#line 356 "Grammar.y"
	{
            yyval.stmt = mk_compoundstatement(line_num, yystack.l_mark[-1].list);
        }
break;
case 26:
#line 362 "Grammar.y"
	{yyval.list = yystack.l_mark[0].list;}
break;
case 27:
#line 363 "Grammar.y"
	{yyval.list = NULL;}
break;
case 28:
#line 368 "Grammar.y"
	{
            yyval.list = CreateListNode(yystack.l_mark[0].stmt, LIST_STMT);
        }
break;
case 29:
#line 372 "Grammar.y"
	{
            yyval.list = PushListNodeBack(yystack.l_mark[-2].list, CreateListNode(yystack.l_mark[0].stmt, LIST_STMT));
        }
break;
case 30:
#line 379 "Grammar.y"
	{
            yyval.stmt = yystack.l_mark[0].stmt;
        }
break;
case 31:
#line 383 "Grammar.y"
	{
            yyval.stmt = yystack.l_mark[0].stmt;
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
            yyval.stmt = mk_while(line_num, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt);
        }
break;
case 35:
#line 399 "Grammar.y"
	{
            if(yystack.l_mark[-4].for_assign_bison.assign_type == VAR_ASSIGN)
                yyval.stmt = mk_forassign(line_num, yystack.l_mark[-4].for_assign_bison.for_assign_bison_union.stmt, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt);
            else
                yyval.stmt = mk_forvar(line_num, yystack.l_mark[-4].for_assign_bison.for_assign_bison_union.expr, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt);
        }
break;
case 36:
#line 410 "Grammar.y"
	{
            yyval.stmt = mk_ifthen(line_num, yystack.l_mark[-2].expr, yystack.l_mark[0].stmt, NULL);
        }
break;
case 37:
#line 414 "Grammar.y"
	{
            yyval.stmt = mk_ifthen(line_num, yystack.l_mark[-4].expr, yystack.l_mark[-2].stmt, yystack.l_mark[0].stmt);
        }
break;
case 38:
#line 420 "Grammar.y"
	{
            yyval.stmt = mk_varassign(line_num, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 39:
#line 426 "Grammar.y"
	{
            yyval.for_assign_bison.assign_type = VAR_ASSIGN;
            yyval.for_assign_bison.for_assign_bison_union.stmt = yystack.l_mark[0].stmt;
        }
break;
case 40:
#line 431 "Grammar.y"
	{
            yyval.for_assign_bison.assign_type = VAR;
            yyval.for_assign_bison.for_assign_bison_union.expr = yystack.l_mark[0].expr;
        }
break;
case 41:
#line 438 "Grammar.y"
	{
            yyval.expr = mk_varid(yystack.l_mark[0].ident.line_num, yystack.l_mark[0].ident.id);
        }
break;
case 42:
#line 442 "Grammar.y"
	{
            yyval.expr = mk_arrayaccess(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].expr);
        }
break;
case 43:
#line 449 "Grammar.y"
	{
            yyval.stmt = mk_procedurecall(yystack.l_mark[0].ident.line_num, yystack.l_mark[0].ident.id, NULL);
        }
break;
case 44:
#line 453 "Grammar.y"
	{
            yyval.stmt = mk_procedurecall(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].list);
        }
break;
case 45:
#line 462 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, OR, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 46:
#line 465 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 47:
#line 470 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, AND, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 48:
#line 473 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 49:
#line 478 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, NOT, yystack.l_mark[0].expr, NULL);
        }
break;
case 50:
#line 481 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 51:
#line 485 "Grammar.y"
	{yyval.expr = yystack.l_mark[-1].expr;}
break;
case 52:
#line 486 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 53:
#line 491 "Grammar.y"
	{
            yyval.expr = mk_relop(line_num, yystack.l_mark[-1].op_val, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 54:
#line 500 "Grammar.y"
	{
            yyval.list = CreateListNode(yystack.l_mark[0].expr, LIST_EXPR);
        }
break;
case 55:
#line 504 "Grammar.y"
	{
            yyval.list = PushListNodeBack(yystack.l_mark[-2].list, CreateListNode(yystack.l_mark[0].expr, LIST_EXPR));
        }
break;
case 56:
#line 510 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 57:
#line 512 "Grammar.y"
	{
            yyval.expr = mk_addop(line_num, yystack.l_mark[-1].op_val, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 58:
#line 518 "Grammar.y"
	{yyval.expr = yystack.l_mark[0].expr;}
break;
case 59:
#line 520 "Grammar.y"
	{
            yyval.expr = mk_mulop(line_num, yystack.l_mark[-1].op_val, yystack.l_mark[-2].expr, yystack.l_mark[0].expr);
        }
break;
case 60:
#line 527 "Grammar.y"
	{
            yyval.expr = mk_varid(yystack.l_mark[0].ident.line_num, yystack.l_mark[0].ident.id);
        }
break;
case 61:
#line 531 "Grammar.y"
	{
            yyval.expr = mk_arrayaccess(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].expr);
        }
break;
case 62:
#line 535 "Grammar.y"
	{
            yyval.expr = mk_functioncall(yystack.l_mark[-3].ident.line_num, yystack.l_mark[-3].ident.id, yystack.l_mark[-1].list);
        }
break;
case 63:
#line 539 "Grammar.y"
	{
            yyval.expr = mk_inum(line_num, yystack.l_mark[0].i_val);
        }
break;
case 64:
#line 543 "Grammar.y"
	{
            yyval.expr = mk_rnum(line_num, yystack.l_mark[0].f_val);
        }
break;
case 65:
#line 547 "Grammar.y"
	{
            if(yystack.l_mark[-1].op_val == MINUS)
                yyval.expr = mk_signterm(line_num, yystack.l_mark[0].expr);
            else
                yyval.expr = yystack.l_mark[0].expr;
        }
break;
case 66:
#line 554 "Grammar.y"
	{
            yyval.expr = yystack.l_mark[-1].expr;
        }
break;
case 67:
#line 561 "Grammar.y"
	{
            yyval.op_val = yylval.op_val;
        }
break;
#line 1098 "y.tab.c"
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
