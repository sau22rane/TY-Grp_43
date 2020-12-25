/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 5 "./Java/converter_java.y" /* yacc.c:1909  */

    int i;
    struct ast_node *n;

#line 145 "./Java/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_JAVA_Y_TAB_H_INCLUDED  */
