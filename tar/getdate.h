/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tAGO = 258,
     tDAY = 259,
     tDAYZONE = 260,
     tAMPM = 261,
     tMONTH = 262,
     tMONTH_UNIT = 263,
     tSEC_UNIT = 264,
     tUNUMBER = 265,
     tZONE = 266,
     tDST = 267
   };
#endif
#define tAGO 258
#define tDAY 259
#define tDAYZONE 260
#define tAMPM 261
#define tMONTH 262
#define tMONTH_UNIT 263
#define tSEC_UNIT 264
#define tUNUMBER 265
#define tZONE 266
#define tDST 267




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 91 "tar/getdate.y"
typedef union YYSTYPE {
    time_t		Number;
} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 64 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



