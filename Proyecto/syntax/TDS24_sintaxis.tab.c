/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "TDS24_sintaxis.y"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/AST.h"

void interprete(struct AST *arbol);
struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r);
extern int yylineno;
int blockNum = 1;

#line 85 "TDS24_sintaxis.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INT = 259,                     /* INT  */
    TTRUE = 260,                   /* TTRUE  */
    TFALSE = 261,                  /* TFALSE  */
    TYPE_INT = 262,                /* TYPE_INT  */
    TYPE_BOOL = 263,               /* TYPE_BOOL  */
    TYPE_VOID = 264,               /* TYPE_VOID  */
    TMAS = 265,                    /* TMAS  */
    TPOR = 266,                    /* TPOR  */
    TMENOS = 267,                  /* TMENOS  */
    TDIVISION = 268,               /* TDIVISION  */
    TRESTO = 269,                  /* TRESTO  */
    ASIGNACION = 270,              /* ASIGNACION  */
    TPAR_OP = 271,                 /* TPAR_OP  */
    TPAR_CL = 272,                 /* TPAR_CL  */
    TLLAVE_OP = 273,               /* TLLAVE_OP  */
    TLLAVE_CL = 274,               /* TLLAVE_CL  */
    OR = 275,                      /* OR  */
    AND = 276,                     /* AND  */
    NOT = 277,                     /* NOT  */
    MAYORQUE = 278,                /* MAYORQUE  */
    MENORQUE = 279,                /* MENORQUE  */
    EQ = 280,                      /* EQ  */
    PROGRAM = 281,                 /* PROGRAM  */
    EXTERN = 282,                  /* EXTERN  */
    THEN = 283,                    /* THEN  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    WHILE = 286,                   /* WHILE  */
    RETURN = 287,                  /* RETURN  */
    MAIN = 288                     /* MAIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "TDS24_sintaxis.y"

    struct Tsymbol* symbol;
    struct AST *arbol;

#line 170 "TDS24_sintaxis.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_TTRUE = 5,                      /* TTRUE  */
  YYSYMBOL_TFALSE = 6,                     /* TFALSE  */
  YYSYMBOL_TYPE_INT = 7,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_BOOL = 8,                  /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 9,                  /* TYPE_VOID  */
  YYSYMBOL_TMAS = 10,                      /* TMAS  */
  YYSYMBOL_TPOR = 11,                      /* TPOR  */
  YYSYMBOL_TMENOS = 12,                    /* TMENOS  */
  YYSYMBOL_TDIVISION = 13,                 /* TDIVISION  */
  YYSYMBOL_TRESTO = 14,                    /* TRESTO  */
  YYSYMBOL_ASIGNACION = 15,                /* ASIGNACION  */
  YYSYMBOL_TPAR_OP = 16,                   /* TPAR_OP  */
  YYSYMBOL_TPAR_CL = 17,                   /* TPAR_CL  */
  YYSYMBOL_TLLAVE_OP = 18,                 /* TLLAVE_OP  */
  YYSYMBOL_TLLAVE_CL = 19,                 /* TLLAVE_CL  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_MAYORQUE = 23,                  /* MAYORQUE  */
  YYSYMBOL_MENORQUE = 24,                  /* MENORQUE  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_PROGRAM = 26,                   /* PROGRAM  */
  YYSYMBOL_EXTERN = 27,                    /* EXTERN  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_main = 38,                      /* main  */
  YYSYMBOL_list_decls = 39,                /* list_decls  */
  YYSYMBOL_list_sents = 40,                /* list_sents  */
  YYSYMBOL_sentencia = 41,                 /* sentencia  */
  YYSYMBOL_asignacion = 42,                /* asignacion  */
  YYSYMBOL_call_func = 43,                 /* call_func  */
  YYSYMBOL_declaracion = 44,               /* declaracion  */
  YYSYMBOL_argumento = 45,                 /* argumento  */
  YYSYMBOL_parametros = 46,                /* parametros  */
  YYSYMBOL_dec_parametro = 47,             /* dec_parametro  */
  YYSYMBOL_list_func = 48,                 /* list_func  */
  YYSYMBOL_declare_funcion = 49,           /* declare_funcion  */
  YYSYMBOL_expr = 50,                      /* expr  */
  YYSYMBOL_valor = 51,                     /* valor  */
  YYSYMBOL_retorno = 52,                   /* retorno  */
  YYSYMBOL_if_else = 53,                   /* if_else  */
  YYSYMBOL_while = 54                      /* while  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    81,    82,    83,    86,    87,    88,    91,
      92,    95,    96,    99,   100,   101,   102,   103,   106,   110,
     114,   115,   119,   120,   121,   125,   126,   127,   130,   131,
     136,   137,   140,   142,   144,   146,   147,   148,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   170,   171,   172,   173,   174,   177,   181,   182,
     188
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "TTRUE",
  "TFALSE", "TYPE_INT", "TYPE_BOOL", "TYPE_VOID", "TMAS", "TPOR", "TMENOS",
  "TDIVISION", "TRESTO", "ASIGNACION", "TPAR_OP", "TPAR_CL", "TLLAVE_OP",
  "TLLAVE_CL", "OR", "AND", "NOT", "MAYORQUE", "MENORQUE", "EQ", "PROGRAM",
  "EXTERN", "THEN", "IF", "ELSE", "WHILE", "RETURN", "MAIN", "';'", "','",
  "$accept", "prog", "main", "list_decls", "list_sents", "sentencia",
  "asignacion", "call_func", "declaracion", "argumento", "parametros",
  "dec_parametro", "list_func", "declare_funcion", "expr", "valor",
  "retorno", "if_else", "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    27,    50,    98,   -68,    -1,     2,     3,    45,    98,
     -68,   127,   -68,    39,    79,    78,    83,   106,   112,   -68,
      90,   -68,   127,     4,     5,    91,   -68,    12,   -68,    97,
      12,   -68,    99,    12,   107,   -68,   111,   122,   128,   -68,
     156,   165,   152,   135,   154,   158,   166,   168,   171,   -68,
     -68,   -68,    31,    12,    19,    47,    19,    48,    19,    19,
     149,   -68,   187,   188,    19,    19,   167,    19,    19,   180,
      19,    19,   -68,   181,   184,    11,    19,   -68,    15,    19,
     -68,    38,    69,   126,   -68,   170,   186,   176,   -68,   -68,
     196,   -68,   -68,   -68,    89,   -68,    94,   -68,   -68,   176,
     176,   176,   176,   189,   -68,   -68,   -68,   195,   176,   176,
     -68,   137,   -68,   -68,   -68,   -68,   153,    -2,   231,   183,
     199,   -68,   215,   -68,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   -68,   -68,   -68,   176,   193,   216,
     -68,    10,   -68,    10,   -68,   -68,   236,   236,   142,   142,
     252,   231,   219,   -68,   -68,   100,   108,   -68,   201,   235,
     -68,   114,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       9,     0,    30,     0,     0,     0,     0,     0,     0,     3,
       0,    10,     0,     0,     0,     0,    31,    25,    20,     0,
      25,    21,     0,    25,     0,     5,     0,     0,     0,     4,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     2,
      28,    29,     0,    25,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    11,     0,     0,    11,     0,     0,
      11,    11,    35,     0,     0,     0,    11,    36,     0,    11,
      37,     0,     0,     0,     7,     0,     0,     0,    12,    13,
       0,    14,    15,    16,     0,     6,     0,     8,    32,     0,
      22,     0,     0,    53,    52,    55,    56,     0,     0,     0,
      39,     0,    38,    17,    33,    34,     0,     0,    23,     0,
       0,    54,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    18,    19,     0,     0,     0,
      51,    40,    42,    41,    43,    44,    49,    48,    45,    46,
      47,    24,     0,    11,    11,     0,     0,    60,    58,     0,
      11,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,    93,   213,   -67,   -68,   -68,   -65,    -8,   -68,
      -5,   -68,   208,     0,   -48,   -68,   -68,   -68,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    75,    88,    89,   110,    10,   117,
      42,    43,    11,    12,   111,   112,    91,    92,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,    21,    13,    81,    82,    15,    17,    37,    38,    94,
      90,    26,    96,    90,    83,   136,    90,    90,    83,    40,
      41,   125,    26,   127,   128,    45,    62,    63,    47,    90,
      84,    90,    14,   137,    95,    16,    18,    14,    16,     1,
      85,    83,    86,    87,    85,     3,    86,    87,    61,    59,
       4,   116,   118,   119,   120,    27,    21,    97,    60,    21,
     122,   123,    21,    21,    19,    65,    68,    85,    21,    86,
      87,    21,    83,    28,    66,    69,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   155,   156,    98,   151,
      90,    90,    83,   161,    30,    29,    90,    83,    85,    32,
      86,    87,    20,    83,    25,     5,     6,     7,   114,    35,
      39,    83,    31,   115,    44,    36,    46,    83,    85,   157,
      86,    87,    33,    85,    48,    86,    87,   158,    34,    85,
      49,    86,    87,   162,    23,    24,     7,    85,    27,    86,
      87,    99,   100,    85,    30,    86,    87,   124,   125,   126,
     127,   128,   124,   125,   126,   127,   128,   129,   130,    50,
     131,   132,   133,   124,   125,   126,   127,   128,    51,    52,
      53,   134,    54,   129,   130,    55,   131,   132,   133,   103,
     104,   105,   106,    72,    56,    57,   101,   135,   107,    58,
      73,    74,   108,   124,   125,   126,   127,   128,   109,   121,
     138,    77,   102,   129,   130,   100,   131,   132,   133,   124,
     125,   126,   127,   128,    80,    28,   139,    22,    31,   129,
     130,   152,   131,   132,   133,   124,   125,   126,   127,   128,
     113,   159,   140,     0,   153,   129,   130,   154,   131,   132,
     133,   124,   125,   126,   127,   128,   124,   125,   126,   127,
     128,   129,   130,   160,   131,   132,   133,     0,     0,   131,
     132,   133,   124,   125,   126,   127,   128,    64,     0,    67,
       0,    70,    71,     0,     0,   131,   132,     0,    76,     0,
       0,    79
};

static const yytype_int16 yycheck[] =
{
      67,     9,     3,    70,    71,     3,     3,     3,     3,    76,
      75,    11,    79,    78,     3,    17,    81,    82,     3,     7,
       8,    11,    22,    13,    14,    30,     7,     8,    33,    94,
      19,    96,    33,    35,    19,    33,    33,    33,    33,    26,
      29,     3,    31,    32,    29,    18,    31,    32,    53,    18,
       0,    99,   100,   101,   102,    16,    64,    19,    27,    67,
     108,   109,    70,    71,    19,    18,    18,    29,    76,    31,
      32,    79,     3,    34,    27,    27,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   153,   154,    19,   137,
     155,   156,     3,   160,    16,    16,   161,     3,    29,    16,
      31,    32,     9,     3,    11,     7,     8,     9,    19,    19,
      19,     3,    34,    19,    17,    22,    17,     3,    29,    19,
      31,    32,    16,    29,    17,    31,    32,    19,    16,    29,
      19,    31,    32,    19,     7,     8,     9,    29,    16,    31,
      32,    15,    16,    29,    16,    31,    32,    10,    11,    12,
      13,    14,    10,    11,    12,    13,    14,    20,    21,     3,
      23,    24,    25,    10,    11,    12,    13,    14,     3,    17,
      35,    34,    18,    20,    21,    17,    23,    24,    25,     3,
       4,     5,     6,    34,    18,    17,    16,    34,    12,    18,
       3,     3,    16,    10,    11,    12,    13,    14,    22,     4,
      17,    34,    16,    20,    21,    16,    23,    24,    25,    10,
      11,    12,    13,    14,    34,    34,    17,     9,    34,    20,
      21,    28,    23,    24,    25,    10,    11,    12,    13,    14,
      34,    30,    17,    -1,    18,    20,    21,    18,    23,    24,
      25,    10,    11,    12,    13,    14,    10,    11,    12,    13,
      14,    20,    21,    18,    23,    24,    25,    -1,    -1,    23,
      24,    25,    10,    11,    12,    13,    14,    54,    -1,    56,
      -1,    58,    59,    -1,    -1,    23,    24,    -1,    65,    -1,
      -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    37,    18,     0,     7,     8,     9,    38,    39,
      44,    48,    49,     3,    33,     3,    33,     3,    33,    19,
      38,    44,    48,     7,     8,    38,    49,    16,    34,    16,
      16,    34,    16,    16,    16,    19,    38,     3,     3,    19,
       7,     8,    46,    47,    17,    46,    17,    46,    17,    19,
       3,     3,    17,    35,    18,    17,    18,    17,    18,    18,
      27,    46,     7,     8,    39,    18,    27,    39,    18,    27,
      39,    39,    34,     3,     3,    40,    39,    34,    40,    39,
      34,    40,    40,     3,    19,    29,    31,    32,    41,    42,
      43,    52,    53,    54,    40,    19,    40,    19,    19,    15,
      16,    16,    16,     3,     4,     5,     6,    12,    16,    22,
      43,    50,    51,    34,    19,    19,    50,    45,    50,    50,
      50,     4,    50,    50,    10,    11,    12,    13,    14,    20,
      21,    23,    24,    25,    34,    34,    17,    35,    17,    17,
      17,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    28,    18,    18,    40,    40,    19,    19,    30,
      18,    40,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    38,    38,    38,    39,
      39,    40,    40,    41,    41,    41,    41,    41,    42,    43,
      44,    44,    45,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    51,    51,    51,    51,    52,    53,    53,
      54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     5,     5,     8,     8,     8,     1,
       2,     0,     2,     1,     1,     1,     1,     2,     4,     4,
       3,     3,     0,     1,     3,     0,     1,     3,     2,     2,
       1,     2,     9,     9,     9,     7,     7,     7,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     2,     1,     1,     3,     8,    12,
       7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* prog: PROGRAM TLLAVE_OP list_decls list_func main TLLAVE_CL  */
#line 79 "TDS24_sintaxis.y"
                                                             {char * name = "PROGRAM_BLOCK"; struct AST* aux= createTreeWhitSymbol(name,EPROGRAM,1,yylineno,(yyvsp[-3].arbol), (yyvsp[-2].arbol));
                                                              char * name1 = "PROGRAM"; interprete(createTreeWhitSymbol(name,OTHERS,1,yylineno,(yyvsp[-3].arbol), (yyvsp[-2].arbol)));}
#line 1324 "TDS24_sintaxis.tab.c"
    break;

  case 3: /* prog: PROGRAM TLLAVE_OP main TLLAVE_CL  */
#line 81 "TDS24_sintaxis.y"
                                         {  char * name = "PROGRAM"; interprete(createTreeWhitSymbol(name,OTHERS,1,yylineno,NULL, (yyvsp[-1].arbol)));}
#line 1330 "TDS24_sintaxis.tab.c"
    break;

  case 4: /* prog: PROGRAM TLLAVE_OP list_func main TLLAVE_CL  */
#line 82 "TDS24_sintaxis.y"
                                                   { char * name = "PROGRAM"; interprete(createTreeWhitSymbol(name,EPROGRAM,1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol)));}
#line 1336 "TDS24_sintaxis.tab.c"
    break;

  case 5: /* prog: PROGRAM TLLAVE_OP list_decls main TLLAVE_CL  */
#line 83 "TDS24_sintaxis.y"
                                                    { char * name = "PROGRAM"; interprete(createTreeWhitSymbol(name,EPROGRAM,1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol)));}
#line 1342 "TDS24_sintaxis.tab.c"
    break;

  case 6: /* main: TYPE_BOOL MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  */
#line 86 "TDS24_sintaxis.y"
                                                                                {blockNum += 1 ;char * name = "MAIN";(yyval.arbol) = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol));}
#line 1348 "TDS24_sintaxis.tab.c"
    break;

  case 7: /* main: TYPE_INT MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  */
#line 87 "TDS24_sintaxis.y"
                                                                               {blockNum += 1 ;char * name = "MAIN";(yyval.arbol) = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol));}
#line 1354 "TDS24_sintaxis.tab.c"
    break;

  case 8: /* main: TYPE_VOID MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  */
#line 88 "TDS24_sintaxis.y"
                                                                               {blockNum += 1 ;char * name = "MAIN";(yyval.arbol) = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol));}
#line 1360 "TDS24_sintaxis.tab.c"
    break;

  case 9: /* list_decls: declaracion  */
#line 91 "TDS24_sintaxis.y"
                                     {char * name = "DECLARACION"; (yyval.arbol) = createTreeWhitSymbol(name,DECLA,blockNum,yylineno,(yyvsp[0].arbol), NULL);}
#line 1366 "TDS24_sintaxis.tab.c"
    break;

  case 10: /* list_decls: list_decls declaracion  */
#line 92 "TDS24_sintaxis.y"
                                    {char * name = "DECLARACION"; (yyval.arbol) = createTreeWhitSymbol(name,DECLA,blockNum,yylineno,(yyvsp[-1].arbol), (yyvsp[0].arbol));}
#line 1372 "TDS24_sintaxis.tab.c"
    break;

  case 11: /* list_sents: %empty  */
#line 95 "TDS24_sintaxis.y"
                                            {(yyval.arbol) = NULL;}
#line 1378 "TDS24_sintaxis.tab.c"
    break;

  case 12: /* list_sents: list_sents sentencia  */
#line 96 "TDS24_sintaxis.y"
                                            {char * name = "SENTENCIA"; (yyval.arbol) = createTreeWhitSymbol(name,SENTEN,blockNum,yylineno,(yyvsp[-1].arbol), (yyvsp[0].arbol));}
#line 1384 "TDS24_sintaxis.tab.c"
    break;

  case 13: /* sentencia: asignacion  */
#line 99 "TDS24_sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1390 "TDS24_sintaxis.tab.c"
    break;

  case 14: /* sentencia: retorno  */
#line 100 "TDS24_sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1396 "TDS24_sintaxis.tab.c"
    break;

  case 15: /* sentencia: if_else  */
#line 101 "TDS24_sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1402 "TDS24_sintaxis.tab.c"
    break;

  case 16: /* sentencia: while  */
#line 102 "TDS24_sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1408 "TDS24_sintaxis.tab.c"
    break;

  case 17: /* sentencia: call_func ';'  */
#line 103 "TDS24_sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1414 "TDS24_sintaxis.tab.c"
    break;

  case 18: /* asignacion: ID ASIGNACION expr ';'  */
#line 106 "TDS24_sintaxis.y"
                                   {char * name = (yyvsp[-3].symbol)->varname;struct AST* aux3 = createTreeWhitSymbol(name,EID,blockNum,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";(yyval.arbol) = createTreeWhitSymbol(nameAsig,ASIG,1,yylineno,aux3, (yyvsp[-1].arbol));}
#line 1421 "TDS24_sintaxis.tab.c"
    break;

  case 19: /* call_func: ID TPAR_OP argumento TPAR_CL  */
#line 110 "TDS24_sintaxis.y"
                                         {char * name = (yyvsp[-3].symbol)->varname;struct AST* aux3 = createTreeWhitSymbol(name,EFUNC,blockNum,yylineno,NULL, NULL);
                                    char * nameCall = "LLAMADA_FUNC";(yyval.arbol) = createTreeWhitSymbol(nameCall,CALL_F,blockNum,yylineno,aux3, (yyvsp[-1].arbol));}
#line 1428 "TDS24_sintaxis.tab.c"
    break;

  case 20: /* declaracion: TYPE_INT ID ';'  */
#line 114 "TDS24_sintaxis.y"
                              {char * name = (yyvsp[-1].symbol)->varname; (yyval.arbol) = createTreeWhitSymbol(name,VARINT,blockNum,yylineno,NULL, NULL);}
#line 1434 "TDS24_sintaxis.tab.c"
    break;

  case 21: /* declaracion: TYPE_BOOL ID ';'  */
#line 115 "TDS24_sintaxis.y"
                              {char * name = (yyvsp[-1].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,VARBOOL,blockNum,yylineno,NULL, NULL);}
#line 1440 "TDS24_sintaxis.tab.c"
    break;

  case 22: /* argumento: %empty  */
#line 119 "TDS24_sintaxis.y"
                                   {(yyval.arbol) = NULL;}
#line 1446 "TDS24_sintaxis.tab.c"
    break;

  case 23: /* argumento: expr  */
#line 120 "TDS24_sintaxis.y"
                                   {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1452 "TDS24_sintaxis.tab.c"
    break;

  case 24: /* argumento: argumento ',' expr  */
#line 121 "TDS24_sintaxis.y"
                                   {char * name = "arguments"; (yyval.arbol) = createTreeWhitSymbol(name,ARGS, blockNum, yylineno, (yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1458 "TDS24_sintaxis.tab.c"
    break;

  case 25: /* parametros: %empty  */
#line 125 "TDS24_sintaxis.y"
                                            {(yyval.arbol) = NULL;}
#line 1464 "TDS24_sintaxis.tab.c"
    break;

  case 26: /* parametros: dec_parametro  */
#line 126 "TDS24_sintaxis.y"
                                            {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1470 "TDS24_sintaxis.tab.c"
    break;

  case 27: /* parametros: dec_parametro ',' parametros  */
#line 127 "TDS24_sintaxis.y"
                                            {char * name = "DECLARACION"; (yyval.arbol) = createTreeWhitSymbol(name,DECLA,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1476 "TDS24_sintaxis.tab.c"
    break;

  case 28: /* dec_parametro: TYPE_INT ID  */
#line 130 "TDS24_sintaxis.y"
                             {char * name = (yyvsp[0].symbol)->varname; (yyval.arbol) = createTreeWhitSymbol(name,PARAMINT,blockNum,yylineno,NULL, NULL);}
#line 1482 "TDS24_sintaxis.tab.c"
    break;

  case 29: /* dec_parametro: TYPE_BOOL ID  */
#line 131 "TDS24_sintaxis.y"
                              {char * name = (yyvsp[0].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,PARAMBOOL,blockNum,yylineno,NULL, NULL);}
#line 1488 "TDS24_sintaxis.tab.c"
    break;

  case 30: /* list_func: declare_funcion  */
#line 136 "TDS24_sintaxis.y"
                                            {char * name = "LIS_FUNCION";(yyval.arbol) = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,(yyvsp[0].arbol), NULL);}
#line 1494 "TDS24_sintaxis.tab.c"
    break;

  case 31: /* list_func: list_func declare_funcion  */
#line 137 "TDS24_sintaxis.y"
                                            {char * name = "LIS_FUNCION";(yyval.arbol) = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,(yyvsp[-1].arbol), (yyvsp[0].arbol));}
#line 1500 "TDS24_sintaxis.tab.c"
    break;

  case 32: /* declare_funcion: TYPE_INT ID TPAR_OP parametros TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  */
#line 140 "TDS24_sintaxis.y"
                                                                                                    {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, (yyvsp[-2].arbol), (yyvsp[-1].arbol));
                                                                                                     blockNum ++;char * name = (yyvsp[-7].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,(yyvsp[-5].arbol), aux);}
#line 1507 "TDS24_sintaxis.tab.c"
    break;

  case 33: /* declare_funcion: TYPE_BOOL ID TPAR_OP parametros TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  */
#line 142 "TDS24_sintaxis.y"
                                                                                                    {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, (yyvsp[-2].arbol), (yyvsp[-1].arbol));
                                                                                                     blockNum ++;char * name = (yyvsp[-7].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,(yyvsp[-5].arbol), aux);}
#line 1514 "TDS24_sintaxis.tab.c"
    break;

  case 34: /* declare_funcion: TYPE_VOID ID TPAR_OP parametros TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  */
#line 144 "TDS24_sintaxis.y"
                                                                                                    {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, (yyvsp[-2].arbol), (yyvsp[-1].arbol));
                                                                                                     blockNum ++;char * name = (yyvsp[-7].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,(yyvsp[-5].arbol), aux);}
#line 1521 "TDS24_sintaxis.tab.c"
    break;

  case 35: /* declare_funcion: TYPE_INT ID TPAR_OP parametros TPAR_CL EXTERN ';'  */
#line 146 "TDS24_sintaxis.y"
                                                                                                    {blockNum ++;char * name = (yyvsp[-5].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,(yyvsp[-3].arbol), NULL);}
#line 1527 "TDS24_sintaxis.tab.c"
    break;

  case 36: /* declare_funcion: TYPE_BOOL ID TPAR_OP parametros TPAR_CL EXTERN ';'  */
#line 147 "TDS24_sintaxis.y"
                                                                                                    {blockNum ++;char * name = (yyvsp[-5].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,(yyvsp[-3].arbol), NULL);}
#line 1533 "TDS24_sintaxis.tab.c"
    break;

  case 37: /* declare_funcion: TYPE_VOID ID TPAR_OP parametros TPAR_CL EXTERN ';'  */
#line 148 "TDS24_sintaxis.y"
                                                                                                    {blockNum ++;char * name = (yyvsp[-5].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,(yyvsp[-3].arbol), NULL);}
#line 1539 "TDS24_sintaxis.tab.c"
    break;

  case 38: /* expr: valor  */
#line 152 "TDS24_sintaxis.y"
                                {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1545 "TDS24_sintaxis.tab.c"
    break;

  case 39: /* expr: call_func  */
#line 153 "TDS24_sintaxis.y"
                                {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1551 "TDS24_sintaxis.tab.c"
    break;

  case 40: /* expr: expr TMAS expr  */
#line 154 "TDS24_sintaxis.y"
                                {char * name = "+"; (yyval.arbol) = createTreeWhitSymbol(name,SUMA,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1557 "TDS24_sintaxis.tab.c"
    break;

  case 41: /* expr: expr TMENOS expr  */
#line 155 "TDS24_sintaxis.y"
                                {char * name = "-"; (yyval.arbol) = createTreeWhitSymbol(name,RESTA,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1563 "TDS24_sintaxis.tab.c"
    break;

  case 42: /* expr: expr TPOR expr  */
#line 156 "TDS24_sintaxis.y"
                                {char * name = "*"; (yyval.arbol) = createTreeWhitSymbol(name,PROD,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1569 "TDS24_sintaxis.tab.c"
    break;

  case 43: /* expr: expr TDIVISION expr  */
#line 157 "TDS24_sintaxis.y"
                                {char * name = "/"; (yyval.arbol) = createTreeWhitSymbol(name,EDIV,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1575 "TDS24_sintaxis.tab.c"
    break;

  case 44: /* expr: expr TRESTO expr  */
#line 158 "TDS24_sintaxis.y"
                                {char * name = "%"; (yyval.arbol) = createTreeWhitSymbol(name,ERESTO,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1581 "TDS24_sintaxis.tab.c"
    break;

  case 45: /* expr: expr MAYORQUE expr  */
#line 159 "TDS24_sintaxis.y"
                                {char * name = ">"; (yyval.arbol) = createTreeWhitSymbol(name,EMAYORQUE,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1587 "TDS24_sintaxis.tab.c"
    break;

  case 46: /* expr: expr MENORQUE expr  */
#line 160 "TDS24_sintaxis.y"
                                {char * name = "<"; (yyval.arbol) = createTreeWhitSymbol(name,EMENORQUE,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1593 "TDS24_sintaxis.tab.c"
    break;

  case 47: /* expr: expr EQ expr  */
#line 161 "TDS24_sintaxis.y"
                                {char * name = "=="; (yyval.arbol) = createTreeWhitSymbol(name,EEQ,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1599 "TDS24_sintaxis.tab.c"
    break;

  case 48: /* expr: expr AND expr  */
#line 162 "TDS24_sintaxis.y"
                                {char * name = "&&"; (yyval.arbol) = createTreeWhitSymbol(name,EAND,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1605 "TDS24_sintaxis.tab.c"
    break;

  case 49: /* expr: expr OR expr  */
#line 163 "TDS24_sintaxis.y"
                                {char * name = "||"; (yyval.arbol) = createTreeWhitSymbol(name,EOR,blockNum,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1611 "TDS24_sintaxis.tab.c"
    break;

  case 50: /* expr: NOT expr  */
#line 164 "TDS24_sintaxis.y"
                                {char * name = "!"; (yyval.arbol) = createTreeWhitSymbol(name,ENOT,blockNum,yylineno,(yyvsp[0].arbol), NULL);}
#line 1617 "TDS24_sintaxis.tab.c"
    break;

  case 51: /* expr: TPAR_OP expr TPAR_CL  */
#line 165 "TDS24_sintaxis.y"
                                {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1623 "TDS24_sintaxis.tab.c"
    break;

  case 52: /* valor: INT  */
#line 170 "TDS24_sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1629 "TDS24_sintaxis.tab.c"
    break;

  case 53: /* valor: ID  */
#line 171 "TDS24_sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1635 "TDS24_sintaxis.tab.c"
    break;

  case 54: /* valor: TMENOS INT  */
#line 172 "TDS24_sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1641 "TDS24_sintaxis.tab.c"
    break;

  case 55: /* valor: TTRUE  */
#line 173 "TDS24_sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1647 "TDS24_sintaxis.tab.c"
    break;

  case 56: /* valor: TFALSE  */
#line 174 "TDS24_sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1653 "TDS24_sintaxis.tab.c"
    break;

  case 57: /* retorno: RETURN expr ';'  */
#line 177 "TDS24_sintaxis.y"
                         {char * name = "return";(yyval.arbol) = createTreeWhitSymbol(name,ERETURN,blockNum,yylineno,(yyvsp[-1].arbol), NULL);}
#line 1659 "TDS24_sintaxis.tab.c"
    break;

  case 58: /* if_else: IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sents TLLAVE_CL  */
#line 181 "TDS24_sintaxis.y"
                                                                     {char * name = "if_then"; (yyval.arbol) = createTreeWhitSymbol(name,EIF,blockNum,yylineno,(yyvsp[-5].arbol), (yyvsp[-1].arbol));}
#line 1665 "TDS24_sintaxis.tab.c"
    break;

  case 59: /* if_else: IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sents TLLAVE_CL ELSE TLLAVE_OP list_sents TLLAVE_CL  */
#line 182 "TDS24_sintaxis.y"
                                                                                                         { char * name = "then"; char * name2 = "else";
                                                                                                           struct AST* aux_else = createTreeWhitSymbol(name2,EELSE,blockNum,yylineno,(yyvsp[-1].arbol), NULL);
                                                                                                           struct AST* aux_then = createTreeWhitSymbol(name,ETHEN,blockNum,yylineno,(yyvsp[-5].arbol), aux_else);
                                                                                                           char * name3 = "if_else"; (yyval.arbol) = createTreeWhitSymbol(name3,EIF,blockNum,yylineno,(yyvsp[-9].arbol), aux_then);}
#line 1674 "TDS24_sintaxis.tab.c"
    break;

  case 60: /* while: WHILE TPAR_OP expr TPAR_CL TLLAVE_OP list_sents TLLAVE_CL  */
#line 188 "TDS24_sintaxis.y"
                                                                 {char * name = "while"; (yyval.arbol) = createTreeWhitSymbol(name,EWHILE,blockNum,yylineno,(yyvsp[-4].arbol), (yyvsp[-1].arbol));}
#line 1680 "TDS24_sintaxis.tab.c"
    break;


#line 1684 "TDS24_sintaxis.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 191 "TDS24_sintaxis.y"


void interprete(struct AST* ar){
    printDot(ar,"output/Arbol.dot");
    createTable(ar);
    typeError(ar);
    retError();
    if(getError()) {
        elimArbol(ar);
       exit(1);
    }

    //evaluate(ar);
    prinTable();
    elimArbol(ar);
}

struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r){
    struct Tsymbol* aux = CreateSymbol(name,type,size,yylineno);
    return createTree(aux,l,r);
}

