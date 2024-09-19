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
#line 1 "calc-sintaxis.y"


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AST.h"
void interprete(struct AST *arbol);
struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r);
extern int yylineno;

#line 83 "calc-sintaxis.tab.c"

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

#include "calc-sintaxis.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONSTANTE = 3,                  /* CONSTANTE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_TTRUE = 6,                      /* TTRUE  */
  YYSYMBOL_TFALSE = 7,                     /* TFALSE  */
  YYSYMBOL_TYPE_INT = 8,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_BOOL = 9,                  /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 10,                 /* TYPE_VOID  */
  YYSYMBOL_TMAS = 11,                      /* TMAS  */
  YYSYMBOL_TPOR = 12,                      /* TPOR  */
  YYSYMBOL_TMENOS = 13,                    /* TMENOS  */
  YYSYMBOL_TDIVISION = 14,                 /* TDIVISION  */
  YYSYMBOL_TRESTO = 15,                    /* TRESTO  */
  YYSYMBOL_ASIGNACION = 16,                /* ASIGNACION  */
  YYSYMBOL_TPAR_OP = 17,                   /* TPAR_OP  */
  YYSYMBOL_TPAR_CL = 18,                   /* TPAR_CL  */
  YYSYMBOL_TLLAVE_OP = 19,                 /* TLLAVE_OP  */
  YYSYMBOL_TLLAVE_CL = 20,                 /* TLLAVE_CL  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_MAYORQUE = 24,                  /* MAYORQUE  */
  YYSYMBOL_MENORQUE = 25,                  /* MENORQUE  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_PROGRAM = 27,                   /* PROGRAM  */
  YYSYMBOL_EXTERN = 28,                    /* EXTERN  */
  YYSYMBOL_THEN = 29,                      /* THEN  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_MAIN = 34,                      /* MAIN  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_list_declaraciones = 38,        /* list_declaraciones  */
  YYSYMBOL_list_sentencias = 39,           /* list_sentencias  */
  YYSYMBOL_sentencia = 40,                 /* sentencia  */
  YYSYMBOL_asignacion = 41,                /* asignacion  */
  YYSYMBOL_declaracion = 42,               /* declaracion  */
  YYSYMBOL_expr = 43,                      /* expr  */
  YYSYMBOL_valor = 44,                     /* valor  */
  YYSYMBOL_retorno = 45,                   /* retorno  */
  YYSYMBOL_if_else = 46,                   /* if_else  */
  YYSYMBOL_while = 47                      /* while  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  98

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    75,    78,    79,    81,    82,    85,
      86,    87,    88,    91,    95,    96,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   117,
     118,   119,   120,   121,   124,   128,   129,   135
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
  "\"end of file\"", "error", "\"invalid token\"", "CONSTANTE", "ID",
  "INT", "TTRUE", "TFALSE", "TYPE_INT", "TYPE_BOOL", "TYPE_VOID", "TMAS",
  "TPOR", "TMENOS", "TDIVISION", "TRESTO", "ASIGNACION", "TPAR_OP",
  "TPAR_CL", "TLLAVE_OP", "TLLAVE_CL", "OR", "AND", "NOT", "MAYORQUE",
  "MENORQUE", "EQ", "PROGRAM", "EXTERN", "THEN", "IF", "ELSE", "WHILE",
  "RETURN", "MAIN", "';'", "$accept", "prog", "list_declaraciones",
  "list_sentencias", "sentencia", "asignacion", "declaracion", "expr",
  "valor", "retorno", "if_else", "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -26,   -23,   -22,    21,     9,    25,    28,   -34,    22,
      29,    30,    31,    35,    39,   -34,   -34,   -34,    11,    11,
      11,    12,    55,    56,    46,    47,   127,    19,   -34,   -34,
     -34,   -34,   -34,   -34,    42,    53,   127,    32,    43,   127,
     127,   -34,   -34,   -34,   -34,    76,   127,   127,    88,   -34,
     -34,   -34,   -34,   -34,   104,   -34,   -34,   134,   150,   -34,
     166,   -34,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   -34,   -34,    51,    63,   -34,    10,   -34,    10,
     -34,   -34,   187,   187,   202,   202,   182,    69,    23,    23,
      57,    64,   -34,    60,    73,    23,    75,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     5,     5,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     9,
       6,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,    30,    29,    32,    33,     0,     0,     0,     0,    16,
       3,     8,     2,     4,     0,    14,    15,     0,     0,    31,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    13,     0,     0,    18,    19,    21,    20,
      22,    23,    28,    27,    24,    25,    26,     0,     0,     0,
       0,     0,    37,    35,     0,     0,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -12,   -19,   -25,   -34,   -34,   -33,   -34,   -34,
     -34,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,    18,    27,    28,    29,    30,    48,    49,    31,
      32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    35,    51,    54,    19,    20,    57,    58,     5,    51,
      51,     6,     7,    60,    61,    21,     1,     2,     3,    22,
      23,     8,    63,    21,    65,    66,     9,    21,    36,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    50,
      12,    24,    10,    25,    26,    11,    21,    13,    14,    24,
      15,    25,    26,    24,    16,    25,    26,    21,    17,    37,
      38,    21,    52,    39,    40,    51,    51,    55,    21,    90,
      91,    51,    24,    53,    25,    26,    96,    92,    56,    21,
      87,    59,    88,    24,    93,    25,    26,    24,    89,    25,
      26,    94,    95,     0,    24,    97,    25,    26,     0,    62,
      63,    64,    65,    66,     0,    24,     0,    25,    26,    67,
      68,     0,    69,    70,    71,    62,    63,    64,    65,    66,
       0,     0,     0,    72,     0,    67,    68,     0,    69,    70,
      71,    41,    42,    43,    44,     0,     0,     0,     0,    73,
      45,     0,     0,     0,    46,    62,    63,    64,    65,    66,
      47,     0,    74,     0,     0,    67,    68,     0,    69,    70,
      71,    62,    63,    64,    65,    66,     0,     0,    75,     0,
       0,    67,    68,     0,    69,    70,    71,    62,    63,    64,
      65,    66,     0,     0,    76,     0,     0,    67,    68,     0,
      69,    70,    71,    62,    63,    64,    65,    66,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,     0,     0,
       0,    69,    70,    62,    63,    64,    65,    66
};

static const yytype_int8 yycheck[] =
{
      19,    20,    27,    36,    16,    17,    39,    40,    34,    34,
      35,    34,    34,    46,    47,     4,     8,     9,    10,     8,
       9,     0,    12,     4,    14,    15,    17,     4,    16,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    20,
      18,    30,    17,    32,    33,    17,     4,    18,    18,    30,
      19,    32,    33,    30,    19,    32,    33,     4,    19,     4,
       4,     4,    20,    17,    17,    90,    91,    35,     4,    88,
      89,    96,    30,    20,    32,    33,    95,    20,    35,     4,
      29,     5,    19,    30,    20,    32,    33,    30,    19,    32,
      33,    31,    19,    -1,    30,    20,    32,    33,    -1,    11,
      12,    13,    14,    15,    -1,    30,    -1,    32,    33,    21,
      22,    -1,    24,    25,    26,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    35,    -1,    21,    22,    -1,    24,    25,
      26,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    35,
      13,    -1,    -1,    -1,    17,    11,    12,    13,    14,    15,
      23,    -1,    18,    -1,    -1,    21,    22,    -1,    24,    25,
      26,    11,    12,    13,    14,    15,    -1,    -1,    18,    -1,
      -1,    21,    22,    -1,    24,    25,    26,    11,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    21,    22,    -1,
      24,    25,    26,    11,    12,    13,    14,    15,    11,    12,
      13,    14,    15,    21,    22,    -1,    24,    25,    -1,    -1,
      -1,    24,    25,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    37,    34,    34,    34,     0,    17,
      17,    17,    18,    18,    18,    19,    19,    19,    38,    38,
      38,     4,     8,     9,    30,    32,    33,    39,    40,    41,
      42,    45,    46,    47,    39,    39,    16,     4,     4,    17,
      17,     4,     5,     6,     7,    13,    17,    23,    43,    44,
      20,    40,    20,    20,    43,    35,    35,    43,    43,     5,
      43,    43,    11,    12,    13,    14,    15,    21,    22,    24,
      25,    26,    35,    35,    18,    18,    18,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    29,    19,    19,
      39,    39,    20,    20,    31,    19,    39,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    40,
      40,    40,    40,    41,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    44,    44,    44,    45,    46,    46,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     8,     8,     0,     2,     1,     2,     1,
       1,     1,     1,     4,     3,     3,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     3,     8,    12,     7
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
  case 2: /* prog: TYPE_BOOL MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  */
#line 73 "calc-sintaxis.y"
                                                                                             {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETBOL,1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol)));}
#line 1192 "calc-sintaxis.tab.c"
    break;

  case 3: /* prog: TYPE_INT MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  */
#line 74 "calc-sintaxis.y"
                                                                                            {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETINT,1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol)));}
#line 1198 "calc-sintaxis.tab.c"
    break;

  case 4: /* prog: TYPE_VOID MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  */
#line 75 "calc-sintaxis.y"
                                                                                            {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETVOID,1,yylineno,(yyvsp[-2].arbol), (yyvsp[-1].arbol)));}
#line 1204 "calc-sintaxis.tab.c"
    break;

  case 5: /* list_declaraciones: %empty  */
#line 78 "calc-sintaxis.y"
                                                    {(yyval.arbol) = NULL;}
#line 1210 "calc-sintaxis.tab.c"
    break;

  case 6: /* list_declaraciones: list_declaraciones declaracion  */
#line 79 "calc-sintaxis.y"
                                                    {char * name = "DECLARACION"; (yyval.arbol) = createTreeWhitSymbol(name,DECLA,1,yylineno,(yyvsp[-1].arbol), (yyvsp[0].arbol));}
#line 1216 "calc-sintaxis.tab.c"
    break;

  case 7: /* list_sentencias: sentencia  */
#line 81 "calc-sintaxis.y"
                                                     {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1222 "calc-sintaxis.tab.c"
    break;

  case 8: /* list_sentencias: list_sentencias sentencia  */
#line 82 "calc-sintaxis.y"
                                                      {char * name = "SENTENCIA"; (yyval.arbol) = createTreeWhitSymbol(name,SENTEN,1,yylineno,(yyvsp[-1].arbol), (yyvsp[0].arbol));}
#line 1228 "calc-sintaxis.tab.c"
    break;

  case 9: /* sentencia: asignacion  */
#line 85 "calc-sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1234 "calc-sintaxis.tab.c"
    break;

  case 10: /* sentencia: retorno  */
#line 86 "calc-sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1240 "calc-sintaxis.tab.c"
    break;

  case 11: /* sentencia: if_else  */
#line 87 "calc-sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1246 "calc-sintaxis.tab.c"
    break;

  case 12: /* sentencia: while  */
#line 88 "calc-sintaxis.y"
                                                    {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1252 "calc-sintaxis.tab.c"
    break;

  case 13: /* asignacion: ID ASIGNACION expr ';'  */
#line 91 "calc-sintaxis.y"
                                   {char * name = (yyvsp[-3].symbol)->varname;struct AST* aux3 = createTreeWhitSymbol(name,EID,1,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";(yyval.arbol) = createTreeWhitSymbol(nameAsig,ASIG,1,yylineno,aux3, (yyvsp[-1].arbol));}
#line 1259 "calc-sintaxis.tab.c"
    break;

  case 14: /* declaracion: TYPE_INT ID ';'  */
#line 95 "calc-sintaxis.y"
                             {char * name = (yyvsp[-1].symbol)->varname; (yyval.arbol) = createTreeWhitSymbol(name,VARINT,1,yylineno,NULL, NULL);}
#line 1265 "calc-sintaxis.tab.c"
    break;

  case 15: /* declaracion: TYPE_BOOL ID ';'  */
#line 96 "calc-sintaxis.y"
                              {char * name = (yyvsp[-1].symbol)->varname;(yyval.arbol) = createTreeWhitSymbol(name,VARBOOL,1,yylineno,NULL, NULL);}
#line 1271 "calc-sintaxis.tab.c"
    break;

  case 16: /* expr: valor  */
#line 101 "calc-sintaxis.y"
                                {(yyval.arbol) = (yyvsp[0].arbol);}
#line 1277 "calc-sintaxis.tab.c"
    break;

  case 17: /* expr: NOT expr  */
#line 102 "calc-sintaxis.y"
                                {char * name = "!"; (yyval.arbol) = createTreeWhitSymbol(name,ENOT,1,yylineno,(yyvsp[0].arbol), NULL);}
#line 1283 "calc-sintaxis.tab.c"
    break;

  case 18: /* expr: TPAR_OP expr TPAR_CL  */
#line 103 "calc-sintaxis.y"
                                {(yyval.arbol) = (yyvsp[-1].arbol);}
#line 1289 "calc-sintaxis.tab.c"
    break;

  case 19: /* expr: expr TMAS expr  */
#line 104 "calc-sintaxis.y"
                                {char * name = "+"; (yyval.arbol) = createTreeWhitSymbol(name,SUMA,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1295 "calc-sintaxis.tab.c"
    break;

  case 20: /* expr: expr TMENOS expr  */
#line 105 "calc-sintaxis.y"
                                {char * name = "-"; (yyval.arbol) = createTreeWhitSymbol(name,RESTA,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1301 "calc-sintaxis.tab.c"
    break;

  case 21: /* expr: expr TPOR expr  */
#line 106 "calc-sintaxis.y"
                                {char * name = "*"; (yyval.arbol) = createTreeWhitSymbol(name,PROD,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1307 "calc-sintaxis.tab.c"
    break;

  case 22: /* expr: expr TDIVISION expr  */
#line 107 "calc-sintaxis.y"
                                {char * name = "/"; (yyval.arbol) = createTreeWhitSymbol(name,EDIV,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1313 "calc-sintaxis.tab.c"
    break;

  case 23: /* expr: expr TRESTO expr  */
#line 108 "calc-sintaxis.y"
                                {char * name = "%"; (yyval.arbol) = createTreeWhitSymbol(name,ERESTO,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1319 "calc-sintaxis.tab.c"
    break;

  case 24: /* expr: expr MAYORQUE expr  */
#line 109 "calc-sintaxis.y"
                                {char * name = ">"; (yyval.arbol) = createTreeWhitSymbol(name,EMAYORQUE,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1325 "calc-sintaxis.tab.c"
    break;

  case 25: /* expr: expr MENORQUE expr  */
#line 110 "calc-sintaxis.y"
                                {char * name = "<"; (yyval.arbol) = createTreeWhitSymbol(name,EMENORQUE,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1331 "calc-sintaxis.tab.c"
    break;

  case 26: /* expr: expr EQ expr  */
#line 111 "calc-sintaxis.y"
                                {char * name = "=="; (yyval.arbol) = createTreeWhitSymbol(name,EEQ,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1337 "calc-sintaxis.tab.c"
    break;

  case 27: /* expr: expr AND expr  */
#line 112 "calc-sintaxis.y"
                                {char * name = "&&"; (yyval.arbol) = createTreeWhitSymbol(name,EAND,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1343 "calc-sintaxis.tab.c"
    break;

  case 28: /* expr: expr OR expr  */
#line 113 "calc-sintaxis.y"
                                {char * name = "||"; (yyval.arbol) = createTreeWhitSymbol(name,EOR,1,yylineno,(yyvsp[-2].arbol), (yyvsp[0].arbol));}
#line 1349 "calc-sintaxis.tab.c"
    break;

  case 29: /* valor: INT  */
#line 117 "calc-sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1355 "calc-sintaxis.tab.c"
    break;

  case 30: /* valor: ID  */
#line 118 "calc-sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1361 "calc-sintaxis.tab.c"
    break;

  case 31: /* valor: TMENOS INT  */
#line 119 "calc-sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1367 "calc-sintaxis.tab.c"
    break;

  case 32: /* valor: TTRUE  */
#line 120 "calc-sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1373 "calc-sintaxis.tab.c"
    break;

  case 33: /* valor: TFALSE  */
#line 121 "calc-sintaxis.y"
                                {(yyval.arbol) = createTree((yyvsp[0].symbol), NULL, NULL);}
#line 1379 "calc-sintaxis.tab.c"
    break;

  case 34: /* retorno: RETURN expr ';'  */
#line 124 "calc-sintaxis.y"
                         {char * name = "return";(yyval.arbol) = createTreeWhitSymbol(name,ERETURN,1,yylineno,(yyvsp[-1].arbol), NULL);}
#line 1385 "calc-sintaxis.tab.c"
    break;

  case 35: /* if_else: IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sentencias TLLAVE_CL  */
#line 128 "calc-sintaxis.y"
                                                                          {char * name = "if_then"; (yyval.arbol) = createTreeWhitSymbol(name,ETHEN,1,yylineno,(yyvsp[-5].arbol), (yyvsp[-1].arbol));}
#line 1391 "calc-sintaxis.tab.c"
    break;

  case 36: /* if_else: IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sentencias TLLAVE_CL ELSE TLLAVE_OP list_sentencias TLLAVE_CL  */
#line 129 "calc-sintaxis.y"
                                                                                                                   {char * name = "then"; char * name2 = "else"; 
                                                                                                            struct AST* aux_else = createTreeWhitSymbol(name2,EELSE,1,yylineno,(yyvsp[-1].arbol), NULL);
                                                                                                            struct AST* aux_then = createTreeWhitSymbol(name,ETHEN,1,yylineno,(yyvsp[-5].arbol), aux_else);
                                                                                                           char * name3 = "if_else"; (yyval.arbol) = createTreeWhitSymbol(name3,EIF,1,yylineno,(yyvsp[-9].arbol), aux_then);}
#line 1400 "calc-sintaxis.tab.c"
    break;

  case 37: /* while: WHILE TPAR_OP expr TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL  */
#line 135 "calc-sintaxis.y"
                                                                      {char * name = "while"; (yyval.arbol) = createTreeWhitSymbol(name,EWHILE,1,yylineno,(yyvsp[-4].arbol), (yyvsp[-1].arbol));}
#line 1406 "calc-sintaxis.tab.c"
    break;


#line 1410 "calc-sintaxis.tab.c"

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

#line 138 "calc-sintaxis.y"


void interprete(struct AST* ar){
    createTable(ar);
    retError();
    typeError(ar);
    if(getError()) {
        elimArbol(ar);
       exit(1);
    }
    evaluate(ar);
    prinTable();
    printDot(ar,"Arbol.dot");
    elimArbol(ar); 

}

struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r){
    struct Tsymbol* aux = CreateSymbol(name,type,1,yylineno);
    return createTree(aux,l,r);
}

