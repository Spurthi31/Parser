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
extern YYSTYPE yylval;
