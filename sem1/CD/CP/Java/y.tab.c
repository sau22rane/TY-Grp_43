/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./Java/converter_java.y" /* yacc.c:339  */

#include "converter_java.h"

#line 70 "./Java/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_JAVA_Y_TAB_H_INCLUDED
# define YY_YY_JAVA_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INC_OP = 258,
    DEC_OP = 259,
    SHL_OP = 260,
    SHR_OP = 261,
    LE_OP = 262,
    GE_OP = 263,
    EQ_OP = 264,
    NE_OP = 265,
    AND_OP = 266,
    OR_OP = 267,
    ADD_ASSIGN = 268,
    SUB_ASSIGN = 269,
    MUL_ASSIGN = 270,
    DIV_ASSIGN = 271,
    MOD_ASSIGN = 272,
    AND_ASSIGN = 273,
    XOR_ASSIGN = 274,
    OR_ASSIGN = 275,
    SHL_ASSIGN = 276,
    SHR_ASSIGN = 277,
    IDENTIFIER = 278,
    CONSTANT = 279,
    INT = 280,
    STRUCT = 281,
    FLOAT = 282,
    CHAR = 283,
    IF = 284,
    ELSE = 285,
    FOR = 286,
    CONTINUE = 287,
    BREAK = 288,
    RETURN = 289,
    READ = 290,
    WHILE = 291,
    EXTDEFS = 292,
    PARAS = 293,
    STMTS = 294,
    DEFS = 295,
    DECS = 296,
    ARGS = 297,
    INIT_ARGS = 298
  };
#endif
/* Tokens.  */
#define INC_OP 258
#define DEC_OP 259
#define SHL_OP 260
#define SHR_OP 261
#define LE_OP 262
#define GE_OP 263
#define EQ_OP 264
#define NE_OP 265
#define AND_OP 266
#define OR_OP 267
#define ADD_ASSIGN 268
#define SUB_ASSIGN 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define AND_ASSIGN 273
#define XOR_ASSIGN 274
#define OR_ASSIGN 275
#define SHL_ASSIGN 276
#define SHR_ASSIGN 277
#define IDENTIFIER 278
#define CONSTANT 279
#define INT 280
#define STRUCT 281
#define FLOAT 282
#define CHAR 283
#define IF 284
#define ELSE 285
#define FOR 286
#define CONTINUE 287
#define BREAK 288
#define RETURN 289
#define READ 290
#define WHILE 291
#define EXTDEFS 292
#define PARAS 293
#define STMTS 294
#define DEFS 295
#define DECS 296
#define ARGS 297
#define INIT_ARGS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 5 "./Java/converter_java.y" /* yacc.c:355  */

    int i;
    struct ast_node *n;

#line 201 "./Java/y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_JAVA_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "./Java/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,     2,     2,    62,    55,     2,
      44,    45,    60,    58,    46,    59,    65,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      57,    52,    56,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    53,    50,    64,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    36,    40,    41,    45,    46,    47,    48,
      53,    54,    58,    59,    63,    64,    65,    69,    70,    74,
      75,    79,    80,    81,    82,    83,    87,    88,    89,    90,
      91,    95,    99,   100,   104,   105,   109,   110,   111,   115,
     116,   120,   121,   122,   126,   127,   131,   132,   136,   137,
     141,   142,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   161,   162,   166,   167,   171,   172,
     176,   177,   181,   182,   186,   187,   188,   192,   193,   194,
     195,   196,   200,   201,   202,   206,   207,   208,   212,   213,
     214,   215,   219,   220,   221,   222,   223,   224,   228,   229,
     230,   231,   232,   233,   234,   238,   239,   240,   244,   245,
     249,   250,   254
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INC_OP", "DEC_OP", "SHL_OP", "SHR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN", "IDENTIFIER",
  "CONSTANT", "INT", "STRUCT", "FLOAT", "CHAR", "IF", "ELSE", "FOR",
  "CONTINUE", "BREAK", "RETURN", "READ", "WHILE", "EXTDEFS", "PARAS",
  "STMTS", "DEFS", "DECS", "ARGS", "INIT_ARGS", "'('", "')'", "','", "'['",
  "']'", "'{'", "'}'", "';'", "'='", "'|'", "'^'", "'&'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "'.'", "$accept",
  "program", "extdefs", "extdef", "func", "paras", "para", "var", "stmts",
  "stmt", "compound_stmt", "expr_stmt", "selection_stmt", "iteration_stmt",
  "jump_stmt", "defs", "def", "decs", "dec", "init", "expr", "assignment",
  "logical_or", "logical_and", "bit_or", "bit_xor", "bit_and", "equality",
  "relational", "shift", "additive", "multi", "unary", "postfix",
  "primary", "args", "init_args", "init_arg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    40,    41,    44,    91,    93,   123,
     125,    59,    61,   124,    94,    38,    62,    60,    43,    45,
      42,    47,    37,    33,   126,    46
};
# endif

#define YYPACT_NINF -56

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      70,   -21,   -21,   -21,    15,    70,   -56,   -56,   -39,   -23,
     -29,   -14,   -56,   -23,     8,   -23,     9,   -56,   -56,   -11,
      96,   -56,   -56,     1,   239,    30,   -56,   -56,   -56,   -56,
     -56,    30,    30,    30,   -56,    27,   -56,   266,   266,   -56,
     -56,    30,    30,    30,    50,    78,    13,    83,   272,    93,
      95,   272,   -56,   266,   266,   266,   185,   -56,   -56,   -56,
     -56,   -56,   -56,   148,   -56,   107,   -56,   154,   159,   132,
     139,   145,    92,     5,   138,   106,   -16,    90,     3,   -56,
     146,   272,   -56,   -56,   -56,   -56,   155,   155,   155,   -56,
     108,   -56,   -56,   272,   129,   -56,   -56,   150,   272,   272,
     158,   -56,   -56,   -56,   -56,   -56,   -56,   222,   -56,   -56,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   -56,
     -56,   256,   272,   181,   -56,   -56,    17,   -56,   -56,   160,
     272,   -56,   161,   165,   -56,   -56,   159,   -56,   132,   139,
     145,    92,     5,     5,   138,   138,   138,   138,   106,   106,
     -16,   -16,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   103,   167,
     -56,   272,   -56,     7,   162,   -56,     7,   -56,   272,   -56,
     -56,   192,   272,   -56,   -56,     7,   178,   -56,     7,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     3,     4,     6,    17,     0,
      46,     0,    44,     0,     0,     0,     0,     1,     5,     0,
       0,    30,     7,     0,     0,     0,    41,     8,    42,     9,
      43,     0,     0,     0,    11,     0,    12,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    19,    21,    22,
      23,    24,    25,     0,    39,     0,    50,    52,    64,    66,
      68,    70,    72,    74,    77,    82,    85,    88,    92,    98,
       0,     0,    47,    48,    17,    45,    14,    15,    16,    10,
       0,    93,    94,     0,     0,    37,    38,     0,     0,     0,
       0,    95,    96,    97,    28,    20,    27,     0,    40,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,    18,   112,     0,   110,    13,     0,
       0,    36,     0,     0,   107,    26,    65,    88,    67,    69,
      71,    73,    75,    76,    81,    79,    78,    80,    83,    84,
      86,    87,    89,    90,    91,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    53,   103,   108,     0,     0,
     104,     0,    49,     0,     0,    51,     0,   102,     0,   101,
     111,    32,     0,    35,   109,     0,     0,    33,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -56,   219,   166,   -56,   137,   130,   168,   -55,
      20,   -56,   -56,   -56,   -56,   -56,     2,     6,   203,   -56,
     -24,   209,   -56,   120,   121,   125,   126,   119,    71,    -4,
      69,    72,   -34,   -56,   -56,   -56,   -56,    47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     9,    35,    36,    10,    56,    57,
      58,    59,    60,    61,    62,    63,     7,    11,    12,    82,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   188,   146,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,   105,     8,    91,    92,    19,   139,   140,    14,    16,
      37,    38,   117,   118,    31,    17,    32,    33,    23,   101,
     102,   103,    64,    24,    97,    80,    20,   100,    21,    22,
      39,    40,    25,    27,    34,    29,    44,    26,    45,    46,
      47,    48,    49,    50,   125,   126,   127,   141,    14,    16,
     142,    51,   105,    84,    25,    25,    20,   145,    21,    28,
      30,   119,   120,   191,    95,   108,    53,   192,   143,   149,
      54,    55,    89,    90,   152,   153,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   172,   173,   174,    93,     1,   150,     2,     3,    37,
      38,   115,   116,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   164,   165,   166,   167,   187,   189,    39,
      40,    41,    94,    42,    43,    44,   194,    45,    46,    47,
      48,    49,    50,    31,    96,    32,    33,    98,   201,    99,
      51,   203,   138,   121,   122,    20,    52,    21,   197,   198,
     207,    37,    38,   209,    41,    53,    42,    43,   109,    54,
      55,    86,    87,    88,   123,   124,   110,   145,    13,    15,
     111,    39,    40,    41,   204,    42,    43,    44,   206,    45,
      46,    47,    48,    49,    50,   112,   162,   163,    37,    38,
     168,   169,    51,   113,   144,   170,   171,    20,   106,    21,
     114,   151,    23,   154,   190,   193,   195,    53,    39,    40,
     196,    54,    55,   202,    44,   199,    45,    46,    47,    48,
      49,    50,   205,   208,    18,    37,    38,   148,    85,    51,
     156,   107,   158,   161,    20,   104,    21,   159,   200,   160,
       0,     0,    37,    38,    53,    39,    40,     0,    54,    55,
       0,    44,     0,    45,    46,    47,    48,    49,    50,    37,
      38,     0,    39,    40,     0,     0,    51,     0,     0,    37,
      38,    20,   155,    21,    49,    37,    38,     0,     0,    39,
      40,    53,     0,    51,     0,    54,    55,     0,    81,    39,
      40,    49,     0,     0,     0,    39,    40,     0,    53,     0,
      51,   186,    54,    55,     0,     0,     0,    49,     0,     0,
      51,     0,     0,     0,     0,    53,    51,     0,     0,    54,
      55,     0,     0,     0,     0,    53,     0,     0,     0,    54,
      55,    53,     0,     0,     0,    54,    55,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185
};

static const yytype_int16 yycheck[] =
{
      24,    56,    23,    37,    38,    44,     3,     4,     2,     3,
       3,     4,     7,     8,    25,     0,    27,    28,    47,    53,
      54,    55,    20,    52,    48,    24,    49,    51,    51,     9,
      23,    24,    46,    13,    45,    15,    29,    51,    31,    32,
      33,    34,    35,    36,    60,    61,    62,    44,    42,    43,
      47,    44,   107,    23,    46,    46,    49,    81,    51,    51,
      51,    56,    57,    46,    51,    63,    59,    50,    65,    93,
      63,    64,    45,    46,    98,    99,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    44,    25,    94,    27,    28,     3,
       4,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   117,   118,   119,   120,   141,   142,    23,
      24,    25,    44,    27,    28,    29,   150,    31,    32,    33,
      34,    35,    36,    25,    51,    27,    28,    44,   193,    44,
      44,   196,    52,     5,     6,    49,    50,    51,    45,    46,
     205,     3,     4,   208,    25,    59,    27,    28,    51,    63,
      64,    31,    32,    33,    58,    59,    12,   191,     2,     3,
      11,    23,    24,    25,   198,    27,    28,    29,   202,    31,
      32,    33,    34,    35,    36,    53,   115,   116,     3,     4,
     121,   122,    44,    54,    48,   123,   124,    49,    50,    51,
      55,    51,    47,    45,    23,    45,    45,    59,    23,    24,
      45,    63,    64,    51,    29,    48,    31,    32,    33,    34,
      35,    36,    30,    45,     5,     3,     4,    90,    25,    44,
     110,    63,   111,   114,    49,    50,    51,   112,   191,   113,
      -1,    -1,     3,     4,    59,    23,    24,    -1,    63,    64,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,    -1,    23,    24,    -1,    -1,    44,    -1,    -1,     3,
       4,    49,    50,    51,    35,     3,     4,    -1,    -1,    23,
      24,    59,    -1,    44,    -1,    63,    64,    -1,    49,    23,
      24,    35,    -1,    -1,    -1,    23,    24,    -1,    59,    -1,
      44,    45,    63,    64,    -1,    -1,    -1,    35,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    59,    44,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    63,
      64,    59,    -1,    -1,    -1,    63,    64,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    27,    28,    67,    68,    69,    82,    23,    70,
      73,    83,    84,    70,    83,    70,    83,     0,    69,    44,
      49,    51,    76,    47,    52,    46,    51,    76,    51,    76,
      51,    25,    27,    28,    45,    71,    72,     3,     4,    23,
      24,    25,    27,    28,    29,    31,    32,    33,    34,    35,
      36,    44,    50,    59,    63,    64,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      24,    49,    85,    86,    23,    84,    73,    73,    73,    45,
      46,    98,    98,    44,    44,    51,    51,    86,    44,    44,
      86,    98,    98,    98,    50,    75,    50,    74,    82,    51,
      12,    11,    53,    54,    55,     9,    10,     7,     8,    56,
      57,     5,     6,    58,    59,    60,    61,    62,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    52,     3,
       4,    44,    47,    65,    48,    86,   102,   103,    72,    86,
      82,    51,    86,    86,    45,    50,    89,    98,    90,    91,
      92,    93,    94,    94,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    45,    86,   101,    86,
      23,    46,    50,    45,    86,    45,    45,    45,    46,    48,
     103,    75,    51,    75,    86,    30,    86,    75,    45,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    96,    96,    97,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     102,   102,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     3,     3,     3,
       4,     3,     1,     3,     2,     2,     2,     1,     4,     1,
       2,     1,     1,     1,     1,     1,     4,     3,     3,     2,
       1,     2,     5,     7,     8,     5,     3,     2,     2,     1,
       2,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     4,     4,     3,     3,     1,     1,     3,     1,     3,
       1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 35 "./Java/converter_java.y" /* yacc.c:1646  */
    { set_parse_tree((yyval.n) = NULL); }
#line 1473 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 36 "./Java/converter_java.y" /* yacc.c:1646  */
    { set_parse_tree((yyval.n) = (yyvsp[0].n)); }
#line 1479 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(EXTDEFS, (yyvsp[0].n), NULL); }
#line 1485 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(EXTDEFS, (yyvsp[0].n), NULL)); }
#line 1491 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1497 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 46 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(int_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1503 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(float_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1509 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(char_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1515 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 53 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = funchead_new((yyvsp[-3].i), (yyvsp[-1].n)); }
#line 1521 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 54 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = funchead_new((yyvsp[-2].i), NULL); }
#line 1527 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(PARAS, (yyvsp[0].n), NULL); }
#line 1533 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(PARAS, (yyvsp[0].n), NULL)); }
#line 1539 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 63 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(int_type(), (yyvsp[0].n)); }
#line 1545 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 64 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(float_type(), (yyvsp[0].n)); }
#line 1551 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 65 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(char_type(), (yyvsp[0].n)); }
#line 1557 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 69 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = var_new((yyvsp[0].i)); }
#line 1563 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 70 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = subvar_new((yyvsp[-3].n), (yyvsp[-1].i)); }
#line 1569 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 74 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(STMTS, (yyvsp[0].n), NULL); }
#line 1575 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 75 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(STMTS, (yyvsp[0].n), NULL)); }
#line 1581 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 79 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1587 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 80 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1593 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1599 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 82 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1605 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 83 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1611 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-2].n), (yyvsp[-1].n)); }
#line 1617 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-1].n), NULL); }
#line 1623 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, (yyvsp[-1].n)); }
#line 1629 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 90 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL); }
#line 1635 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 91 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL); }
#line 1641 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 95 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = expr_stmt_new((yyvsp[-1].n)); }
#line 1647 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = if_stmt_new((yyvsp[-2].n), (yyvsp[0].n), NULL); }
#line 1653 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = if_stmt_new((yyvsp[-4].n), (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1659 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 104 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-5].n),   (yyvsp[-4].n),   (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1665 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 105 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = while_stmt_new((yyvsp[-2].n), (yyvsp[0].n)); }
#line 1671 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 109 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = return_stmt_new((yyvsp[-1].n)); }
#line 1677 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 110 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = continue_stmt_new(); }
#line 1683 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 111 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = break_stmt_new(); }
#line 1689 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 115 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(DEFS, (yyvsp[0].n), NULL); }
#line 1695 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 116 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(DEFS, (yyvsp[0].n), NULL)); }
#line 1701 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 120 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = def_new(int_type(), (yyvsp[-1].n)); }
#line 1707 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = def_new(float_type(), (yyvsp[-1].n)); }
#line 1713 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 122 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = def_new(char_type(), (yyvsp[-1].n)); }
#line 1719 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(DECS, (yyvsp[0].n), NULL); }
#line 1725 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(DECS, (yyvsp[0].n), NULL)); }
#line 1731 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = dec_new((yyvsp[0].n), NULL); }
#line 1737 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = dec_new((yyvsp[-2].n), (yyvsp[0].n)); }
#line 1743 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 136 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1749 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 137 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 1755 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 141 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1761 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 142 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('=', (yyvsp[-1].n), func_call_new(id_new(sym("read")), NULL)); }
#line 1767 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 146 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1773 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 147 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('=', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1779 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 148 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(ADD_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1785 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 149 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SUB_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1791 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 150 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(MUL_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1797 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 151 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(DIV_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1803 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 152 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(MOD_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1809 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 153 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(AND_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1815 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 154 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(XOR_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1821 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(OR_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1827 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 156 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHL_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1833 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 157 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHR_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1839 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 161 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1845 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 162 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(OR_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1851 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 166 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1857 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 167 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(AND_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1863 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 171 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1869 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 172 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('|', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1875 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 176 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1881 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 177 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('^', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1887 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 181 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1893 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 182 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('&', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1899 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 186 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1905 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 187 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(EQ_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1911 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 188 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(NE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1917 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 192 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1923 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 193 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('>', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1929 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 194 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(GE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1935 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 195 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('<', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1941 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 196 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(LE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1947 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 200 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1953 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 201 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHL_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1959 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 202 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHR_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1965 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 206 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1971 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 207 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('+', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1977 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 208 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('-', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1983 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 212 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1989 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 213 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('*', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1995 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 214 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('/', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2001 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 215 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('%', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2007 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 219 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2013 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 220 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new(INC_OP, (yyvsp[0].n)); }
#line 2019 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 221 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new(DEC_OP, (yyvsp[0].n)); }
#line 2025 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 222 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('-', (yyvsp[0].n)); }
#line 2031 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 223 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('!', (yyvsp[0].n)); }
#line 2037 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 224 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('~', (yyvsp[0].n)); }
#line 2043 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 228 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2049 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 229 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = postfix_new(INC_OP, (yyvsp[-1].n)); }
#line 2055 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 230 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = postfix_new(DEC_OP, (yyvsp[-1].n)); }
#line 2061 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 231 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = indexing_new((yyvsp[-3].n), (yyvsp[-1].n)); }
#line 2067 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 232 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = func_call_new((yyvsp[-3].n), (yyvsp[-1].n)); }
#line 2073 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 233 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = func_call_new((yyvsp[-2].n), NULL); }
#line 2079 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 234 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = member_new((yyvsp[-2].n), (yyvsp[0].i)); }
#line 2085 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 238 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = id_new((yyvsp[0].i)); }
#line 2091 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 239 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = const_new((yyvsp[0].i)); }
#line 2097 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 240 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 2103 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 244 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(ARGS, (yyvsp[0].n), NULL); }
#line 2109 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 245 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(ARGS, (yyvsp[0].n), NULL)); }
#line 2115 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 249 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(INIT_ARGS, (yyvsp[0].n), NULL); }
#line 2121 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 250 "./Java/converter_java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(INIT_ARGS, (yyvsp[0].n), NULL)); }
#line 2127 "./Java/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 254 "./Java/converter_java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2133 "./Java/y.tab.c" /* yacc.c:1646  */
    break;


#line 2137 "./Java/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
