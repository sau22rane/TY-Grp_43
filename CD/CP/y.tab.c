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
#line 1 "c2java.y" /* yacc.c:339  */

#include "c2java.h"

#line 70 "y.tab.c" /* yacc.c:339  */

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    EXTDEFS = 291,
    PARAS = 292,
    STMTS = 293,
    DEFS = 294,
    DECS = 295,
    ARGS = 296,
    INIT_ARGS = 297
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
#define EXTDEFS 291
#define PARAS 292
#define STMTS 293
#define DEFS 294
#define DECS 295
#define ARGS 296
#define INIT_ARGS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 5 "c2java.y" /* yacc.c:355  */

    int i;
    struct ast_node *n;

#line 199 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,     2,     2,    61,    54,     2,
      43,    44,    59,    57,    45,    58,    64,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      56,    51,    55,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,    52,    49,    63,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    36,    40,    41,    45,    46,    47,    48,
      53,    54,    58,    59,    63,    67,    68,    72,    73,    77,
      78,    79,    80,    81,    85,    86,    87,    88,    89,    93,
      97,    98,   102,   103,   104,   105,   106,   107,   108,   109,
     113,   114,   115,   119,   120,   124,   128,   129,   133,   134,
     138,   139,   143,   144,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   163,   164,   168,   169,
     173,   174,   178,   179,   183,   184,   188,   189,   190,   194,
     195,   196,   197,   198,   202,   203,   204,   208,   209,   210,
     214,   215,   216,   217,   221,   222,   223,   224,   225,   226,
     230,   231,   232,   233,   234,   235,   236,   240,   241,   242,
     246,   247,   251,   252,   256
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
  "CONTINUE", "BREAK", "RETURN", "READ", "EXTDEFS", "PARAS", "STMTS",
  "DEFS", "DECS", "ARGS", "INIT_ARGS", "'('", "')'", "','", "'['", "']'",
  "'{'", "'}'", "';'", "'='", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "'.'", "$accept", "program",
  "extdefs", "extdef", "func", "paras", "para", "var", "stmts", "stmt",
  "compound_stmt", "expr_stmt", "selection_stmt", "iteration_stmt",
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
     295,   296,   297,    40,    41,    44,    91,    93,   123,   125,
      59,    61,   124,    94,    38,    62,    60,    43,    45,    42,
      47,    37,    33,   126,    46
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    -6,    -4,    -4,    10,    17,   -43,   -43,   -30,    -1,
     -12,   -10,   -43,   -30,    -1,    -1,   -43,   -43,   -13,    63,
     -43,   -43,     9,   284,    13,   -43,   -43,   -43,    13,   -43,
      18,   -43,    86,    86,   -43,   -43,    13,     5,    12,    41,
      43,   409,    62,   409,   -43,    86,    86,    86,   196,   -43,
     -43,   -43,   -43,   -43,   -43,   160,   -43,    74,   -43,    46,
     123,    83,    84,    82,    94,     1,   109,    60,    -8,     8,
       0,   -43,    91,   409,   -43,   -43,   -43,   -43,    93,   -43,
     116,   -43,   -43,   409,   301,   -43,   -43,    92,   409,    99,
     -43,   -43,   -43,   -43,   -43,   -43,   232,   -43,   -43,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,   -43,   -43,
     310,   409,   122,   -43,   -43,   -38,   -43,   -43,   102,   317,
      97,   -43,   107,   -43,   -43,   123,   -43,    83,    84,    82,
      94,     1,     1,   109,   109,   109,   109,    60,    60,    -8,
      -8,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,    75,   105,   -43,
     409,   -43,   268,   334,   103,   358,   -43,   -43,   409,   -43,
     -43,   124,   268,   111,   367,   380,   118,   -43,   268,   -43,
     268,   268,   129,   268,   130,   383,   -43,   -43,   -43,   268,
     -43,   268,   268,   132,   -43,   -43,   -43,   268,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     3,     4,     6,    15,     0,
      48,     0,    46,     0,     0,     0,     1,     5,     0,     0,
      28,     7,     0,     0,     0,    45,     8,     9,     0,    11,
       0,    12,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    17,
      19,    20,    21,    22,    23,     0,    43,     0,    52,    54,
      66,    68,    70,    72,    74,    76,    79,    84,    87,    90,
      94,   100,     0,     0,    49,    50,    15,    47,    14,    10,
       0,    95,    96,     0,     0,    41,    42,     0,     0,     0,
      97,    98,    99,    26,    18,    25,     0,    44,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
       0,     0,     0,    16,   114,     0,   112,    13,     0,     0,
       0,    40,     0,   109,    24,    67,    90,    69,    71,    73,
      75,    77,    78,    83,    81,    80,    82,    85,    86,    88,
      89,    91,    92,    93,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    55,   105,   110,     0,     0,   106,
       0,    51,     0,     0,     0,     0,    53,   104,     0,   103,
     113,    30,     0,     0,     0,     0,     0,   111,     0,    39,
       0,     0,     0,     0,     0,     0,    31,    38,    37,     0,
      35,     0,     0,     0,    36,    34,    33,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,   161,   120,   -43,    98,   149,   125,   -42,
      23,   -43,   -43,   -43,   -43,   -43,   -14,   -43,   155,   -43,
     -23,   336,   -43,    87,    81,    89,    85,    95,    26,    -7,
      22,    15,   -31,   -43,   -43,   -43,   -43,    16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     9,    30,    31,    10,    48,    49,
      50,    51,    52,    53,    54,    55,     7,    11,    12,    74,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   177,   135,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,    81,    82,   128,   129,    56,    94,   180,   106,   107,
      16,   181,    28,    18,    90,    91,    92,     8,    87,    13,
      89,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    29,    21,    72,    22,    24,    76,    26,    27,    23,
      25,    97,     1,   130,     2,     3,   131,    19,    83,    20,
     134,   114,   115,   116,    94,    84,   108,   109,    99,   127,
     138,   140,    79,    80,   132,   142,    32,    33,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   161,   162,   163,    34,    35,    36,    32,
      33,    85,    37,    86,    38,    39,    40,    41,    42,   153,
     154,   155,   156,   104,   105,    88,    43,   176,   178,    34,
      35,    19,    44,    20,   110,   111,   184,   112,   113,   187,
     188,    45,    14,    15,    98,    46,    47,   159,   160,    43,
     151,   152,   157,   158,   100,   101,   103,   102,   133,    22,
     191,    28,   141,   143,    45,   179,   182,   185,    46,    47,
     199,   186,   189,   194,   198,   200,   206,   134,   207,   208,
     193,   210,   196,    32,    33,   197,    17,   214,   205,   215,
     216,   202,   204,   209,   211,   218,   217,    78,   137,    77,
      96,   147,   213,    34,    35,    36,   145,   149,     0,    37,
     148,    38,    39,    40,    41,    42,   190,     0,   150,    32,
      33,     0,     0,    43,     0,     0,     0,     0,    19,    95,
      20,     0,     0,     0,     0,     0,     0,     0,    45,    34,
      35,     0,    46,    47,     0,    37,     0,    38,    39,    40,
      41,    42,     0,     0,     0,    32,    33,     0,     0,    43,
       0,     0,     0,     0,    19,    93,    20,     0,     0,     0,
       0,     0,     0,     0,    45,    34,    35,     0,    46,    47,
       0,    37,     0,    38,    39,    40,    41,    42,     0,     0,
       0,    32,    33,     0,     0,    43,     0,     0,     0,     0,
      19,   144,    20,     0,     0,     0,     0,    32,    33,     0,
      45,    34,    35,     0,    46,    47,     0,    37,     0,    38,
      39,    40,    41,    42,    32,    33,     0,    34,    35,     0,
       0,    43,     0,    32,    33,     0,    19,     0,    20,    42,
      32,    33,     0,     0,    34,    35,    45,    43,     0,     0,
      46,    47,    73,    34,    35,     0,    42,    32,    33,     0,
      34,    35,    45,     0,    43,    42,    46,    47,     0,     0,
       0,   139,    42,    43,   175,     0,     0,    34,    35,    45,
      43,    32,    33,    46,    47,     0,     0,   183,    45,    42,
      32,    33,    46,    47,     0,    45,     0,    43,   192,    46,
      47,    34,    35,    32,    33,     0,    32,    33,     0,     0,
      34,    35,    45,    42,     0,     0,    46,    47,     0,     0,
       0,    43,    42,    34,    35,     0,    34,    35,   195,     0,
      43,   201,    32,    33,     0,    42,    45,     0,    42,     0,
      46,    47,     0,    43,   203,    45,    43,   212,     0,    46,
      47,     0,    34,    35,     0,     0,     0,     0,    45,     0,
       0,    45,    46,    47,    42,    46,    47,     0,     0,     0,
       0,     0,    43,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,     0,    45,     0,     0,
       0,    46,    47
};

static const yytype_int16 yycheck[] =
{
      23,    32,    33,     3,     4,    19,    48,    45,     7,     8,
       0,    49,    25,    43,    45,    46,    47,    23,    41,    23,
      43,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    44,     9,    24,    46,    45,    23,    14,    15,    51,
      50,    55,    25,    43,    27,    28,    46,    48,    43,    50,
      73,    59,    60,    61,    96,    43,    55,    56,    12,    51,
      83,    84,    44,    45,    64,    88,     3,     4,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    23,    24,    25,     3,
       4,    50,    29,    50,    31,    32,    33,    34,    35,   106,
     107,   108,   109,     9,    10,    43,    43,   130,   131,    23,
      24,    48,    49,    50,     5,     6,   139,    57,    58,    44,
      45,    58,     2,     3,    50,    62,    63,   112,   113,    43,
     104,   105,   110,   111,    11,    52,    54,    53,    47,    46,
     182,    25,    50,    44,    58,    23,    44,    50,    62,    63,
     192,    44,    47,    50,    30,    44,   198,   180,   200,   201,
     183,   203,   185,     3,     4,   188,     5,   209,    50,   211,
     212,   194,   195,    44,    44,   217,    44,    28,    80,    24,
      55,   100,   205,    23,    24,    25,    99,   102,    -1,    29,
     101,    31,    32,    33,    34,    35,   180,    -1,   103,     3,
       4,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    23,
      24,    -1,    62,    63,    -1,    29,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,     3,     4,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    23,    24,    -1,    62,    63,
      -1,    29,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,     3,     4,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,     3,     4,    -1,
      58,    23,    24,    -1,    62,    63,    -1,    29,    -1,    31,
      32,    33,    34,    35,     3,     4,    -1,    23,    24,    -1,
      -1,    43,    -1,     3,     4,    -1,    48,    -1,    50,    35,
       3,     4,    -1,    -1,    23,    24,    58,    43,    -1,    -1,
      62,    63,    48,    23,    24,    -1,    35,     3,     4,    -1,
      23,    24,    58,    -1,    43,    35,    62,    63,    -1,    -1,
      -1,    50,    35,    43,    44,    -1,    -1,    23,    24,    58,
      43,     3,     4,    62,    63,    -1,    -1,    50,    58,    35,
       3,     4,    62,    63,    -1,    58,    -1,    43,    44,    62,
      63,    23,    24,     3,     4,    -1,     3,     4,    -1,    -1,
      23,    24,    58,    35,    -1,    -1,    62,    63,    -1,    -1,
      -1,    43,    35,    23,    24,    -1,    23,    24,    50,    -1,
      43,    44,     3,     4,    -1,    35,    58,    -1,    35,    -1,
      62,    63,    -1,    43,    44,    58,    43,    44,    -1,    62,
      63,    -1,    23,    24,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    58,    62,    63,    35,    62,    63,    -1,    -1,    -1,
      -1,    -1,    43,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    27,    28,    66,    67,    68,    81,    23,    69,
      72,    82,    83,    23,    69,    69,     0,    68,    43,    48,
      50,    75,    46,    51,    45,    50,    75,    75,    25,    44,
      70,    71,     3,     4,    23,    24,    25,    29,    31,    32,
      33,    34,    35,    43,    49,    58,    62,    63,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    24,    48,    84,    85,    23,    83,    72,    44,
      45,    97,    97,    43,    43,    50,    50,    85,    43,    85,
      97,    97,    97,    49,    74,    49,    73,    81,    50,    12,
      11,    52,    53,    54,     9,    10,     7,     8,    55,    56,
       5,     6,    57,    58,    59,    60,    61,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    51,     3,     4,
      43,    46,    64,    47,    85,   101,   102,    71,    85,    50,
      85,    50,    85,    44,    49,    88,    97,    89,    90,    91,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    44,    85,   100,    85,    23,
      45,    49,    44,    50,    85,    50,    44,    44,    45,    47,
     102,    74,    44,    85,    50,    50,    85,    85,    30,    74,
      44,    44,    85,    44,    85,    50,    74,    74,    74,    44,
      74,    44,    44,    85,    74,    74,    74,    44,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      89,    89,    90,    90,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     3,     3,     3,
       4,     3,     1,     3,     2,     1,     4,     1,     2,     1,
       1,     1,     1,     1,     4,     3,     3,     2,     1,     2,
       5,     7,     9,     8,     8,     7,     8,     7,     7,     6,
       3,     2,     2,     1,     2,     3,     1,     3,     1,     3,
       1,     3,     1,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     2,     2,
       1,     2,     2,     4,     4,     3,     3,     1,     1,     3,
       1,     3,     1,     3,     1
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
#line 35 "c2java.y" /* yacc.c:1646  */
    { set_parse_tree((yyval.n) = NULL); }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 36 "c2java.y" /* yacc.c:1646  */
    { set_parse_tree((yyval.n) = (yyvsp[0].n)); }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(EXTDEFS, (yyvsp[0].n), NULL); }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(EXTDEFS, (yyvsp[0].n), NULL)); }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 46 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(int_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(float_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = funcdef_new(char_type(), (yyvsp[-1].n), (yyvsp[0].n)); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 53 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = funchead_new((yyvsp[-3].i), (yyvsp[-1].n)); }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 54 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = funchead_new((yyvsp[-2].i), NULL); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(PARAS, (yyvsp[0].n), NULL); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(PARAS, (yyvsp[0].n), NULL)); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 63 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = para_new(int_type(), (yyvsp[0].n)); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 67 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = var_new((yyvsp[0].i)); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 68 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = subvar_new((yyvsp[-3].n), (yyvsp[-1].i)); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(STMTS, (yyvsp[0].n), NULL); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(STMTS, (yyvsp[0].n), NULL)); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 78 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 79 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 80 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-2].n), (yyvsp[-1].n)); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new((yyvsp[-1].n), NULL); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, (yyvsp[-1].n)); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = compound_stmt_new(NULL, NULL); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 93 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = expr_stmt_new((yyvsp[-1].n)); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = if_stmt_new((yyvsp[-2].n), (yyvsp[0].n), NULL); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = if_stmt_new((yyvsp[-4].n), (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 102 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-6].n),   (yyvsp[-4].n),   (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 103 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-5].n),   (yyvsp[-3].n),   NULL, (yyvsp[0].n)); }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 104 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-5].n),   NULL, (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 105 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new((yyvsp[-4].n),   NULL, NULL, (yyvsp[0].n)); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 106 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, (yyvsp[-4].n),   (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, (yyvsp[-3].n),   NULL, (yyvsp[0].n)); }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 108 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, NULL, (yyvsp[-2].n),   (yyvsp[0].n)); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 109 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = for_stmt_new(NULL, NULL, NULL, (yyvsp[0].n)); }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 113 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = return_stmt_new((yyvsp[-1].n)); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = continue_stmt_new(); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 115 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = break_stmt_new(); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 119 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(DEFS, (yyvsp[0].n), NULL); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 120 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-1].n), list_new(DEFS, (yyvsp[0].n), NULL)); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 124 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = def_new(int_type(), (yyvsp[-1].n)); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 128 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(DECS, (yyvsp[0].n), NULL); }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 129 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(DECS, (yyvsp[0].n), NULL)); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = dec_new((yyvsp[0].n), NULL); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 134 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = dec_new((yyvsp[-2].n), (yyvsp[0].n)); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 139 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 143 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 144 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('=', (yyvsp[-1].n), func_call_new(id_new(sym("read")), NULL)); }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 148 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 149 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('=', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 150 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(ADD_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 151 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SUB_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 152 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(MUL_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 153 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(DIV_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 154 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(MOD_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(AND_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 156 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(XOR_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 157 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(OR_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 158 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHL_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 159 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHR_ASSIGN, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 163 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 164 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(OR_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 168 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 169 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(AND_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 173 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('|', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 178 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 179 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('^', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 183 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 184 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('&', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 188 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 189 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(EQ_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 190 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(NE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 194 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 195 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('>', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 196 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(GE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 197 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('<', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 198 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(LE_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 202 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 203 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHL_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 204 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new(SHR_OP, (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 208 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 209 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('+', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 210 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('-', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 214 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 215 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('*', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 216 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('/', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 217 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = binop_new('%', (yyvsp[-2].n), (yyvsp[0].n)); }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 221 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 222 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new(INC_OP, (yyvsp[0].n)); }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 223 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new(DEC_OP, (yyvsp[0].n)); }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 224 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('-', (yyvsp[0].n)); }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 225 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('!', (yyvsp[0].n)); }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 226 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = prefix_new('~', (yyvsp[0].n)); }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 230 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 231 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = postfix_new(INC_OP, (yyvsp[-1].n)); }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 232 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = postfix_new(DEC_OP, (yyvsp[-1].n)); }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 233 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = indexing_new((yyvsp[-3].n), (yyvsp[-1].n)); }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 234 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = func_call_new((yyvsp[-3].n), (yyvsp[-1].n)); }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 235 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = func_call_new((yyvsp[-2].n), NULL); }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 236 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = member_new((yyvsp[-2].n), (yyvsp[0].i)); }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 240 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = id_new((yyvsp[0].i)); }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 241 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = const_new((yyvsp[0].i)); }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 242 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[-1].n); }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 246 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(ARGS, (yyvsp[0].n), NULL); }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 247 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(ARGS, (yyvsp[0].n), NULL)); }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 251 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = list_new(INIT_ARGS, (yyvsp[0].n), NULL); }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 252 "c2java.y" /* yacc.c:1646  */
    { list_append((yyval.n) = (yyvsp[-2].n), list_new(INIT_ARGS, (yyvsp[0].n), NULL)); }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 256 "c2java.y" /* yacc.c:1646  */
    { (yyval.n) = (yyvsp[0].n); }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2176 "y.tab.c" /* yacc.c:1646  */
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
