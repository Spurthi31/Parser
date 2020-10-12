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
extern YYSTYPE yylval;
