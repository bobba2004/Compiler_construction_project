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
#line 2 "calcilist.y"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "calcilist.h"
#include "calcilist.tab.h"

extern int yylex(void);
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int yywrap() {
    return 1;
}

#define println printf("\n")
#define printlist(l) PrintList(l, 0); println

/* Function prototypes */
list *ReverseList(list *);
char *EvaluateToLiteral(list *, int);
list *ExecuteExternalCall(char *, list *);

/* Function pointer type for external calls */
typedef double (*MathFunc)(double);

/* Table of supported math functions */
struct MathFunction {
    char *name;
    MathFunc func;
} mathFunctions[] = {
    {"sin", sin},
    {"cos", cos},
    {"sqrt", sqrt},
    {"tan", tan},
    {NULL, NULL}
};


#line 115 "calcilist.tab.c"

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

#include "calcilist.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_TYPE = 4,                       /* TYPE  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NEQ = 10,                       /* NEQ  */
  YYSYMBOL_LT = 11,                        /* LT  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_17_n_ = 17,                     /* '\n'  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* '{'  */
  YYSYMBOL_22_ = 22,                       /* '}'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '['  */
  YYSYMBOL_29_ = 29,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_PROGRAM = 31,                   /* PROGRAM  */
  YYSYMBOL_STATEMENTS = 32,                /* STATEMENTS  */
  YYSYMBOL_STATEMENT = 33,                 /* STATEMENT  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_IF_STATEMENT = 35,              /* IF_STATEMENT  */
  YYSYMBOL_WHILE_STATEMENT = 36,           /* WHILE_STATEMENT  */
  YYSYMBOL_FUNCTION_CALL = 37,             /* FUNCTION_CALL  */
  YYSYMBOL_EXPR_LIST = 38,                 /* EXPR_LIST  */
  YYSYMBOL_EXPR_TAIL = 39,                 /* EXPR_TAIL  */
  YYSYMBOL_EXPR = 40,                      /* EXPR  */
  YYSYMBOL_TERM = 41,                      /* TERM  */
  YYSYMBOL_FACTOR = 42,                    /* FACTOR  */
  YYSYMBOL_LIST = 43,                      /* LIST  */
  YYSYMBOL_NUM_LIST = 44                   /* NUM_LIST  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


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
      17,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    26,    24,    23,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    65,    68,    69,    70,    71,    72,
      73,    74,    75,    78,    79,    80,    83,    92,   104,   111,
     114,   115,   118,   119,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   135,   136,   137,   140,   141,
     142,   143,   144,   145,   148,   151,   152,   153
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "TYPE", "ID",
  "IF", "ELSE", "WHILE", "EQ", "NEQ", "LT", "GT", "LE", "GE", "AND", "OR",
  "'\\n'", "'='", "'('", "')'", "'{'", "'}'", "','", "'+'", "'-'", "'*'",
  "'/'", "'['", "']'", "$accept", "PROGRAM", "STATEMENTS", "STATEMENT",
  "ASSIGN", "IF_STATEMENT", "WHILE_STATEMENT", "FUNCTION_CALL",
  "EXPR_LIST", "EXPR_TAIL", "EXPR", "TERM", "FACTOR", "LIST", "NUM_LIST", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -62,    11,    95,   -62,   -62,   -62,     2,    -3,     7,   -62,
      90,    90,     0,   -62,    14,   -62,   -62,    15,   122,    -4,
     -62,   102,    90,    90,    90,    23,   -62,   139,   -62,    30,
       5,   -62,   -62,    90,    90,    90,    90,    90,    90,    90,
      90,   -62,    90,    90,    90,    90,    27,     1,   207,   -62,
      29,   156,   173,   190,   -62,   -62,     6,   -62,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,   -62,   -62,
     -62,    90,   -62,    32,    34,   -62,   -62,   156,   -62,   -62,
     -62,    35,    42,    44,   -62,    37,   -62,    69,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    39,     8,    41,     0,     0,     6,
       0,     0,     0,     3,     0,    10,    11,    43,     0,    26,
      37,     0,    21,     0,     0,    41,    43,     0,    42,    47,
       0,     7,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,    39,    47,    15,    14,
       0,    23,     0,     0,    38,    46,     0,    40,    27,    28,
      29,    30,    31,    32,    33,    34,    24,    25,    35,    36,
      19,     0,    20,     0,     0,    45,    44,    23,     4,     4,
      22,     0,     0,    16,    18,     0,     4,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -61,   -62,   -62,   -62,   -62,    -2,   -62,   -21,
      -9,   200,    -8,    45,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    14,    15,    16,    26,    50,    72,
      18,    19,    20,    30,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    27,    -9,    28,    55,    -9,    -9,    -9,    -9,    75,
      -9,     3,    48,    51,    52,    53,    23,    81,    82,    -9,
      21,    22,    44,    45,    -9,    87,    24,    -9,    29,    29,
      -9,    31,    32,    55,    57,    76,    68,    69,     4,     5,
       6,     7,    22,     8,   -13,     4,     5,     6,     7,    70,
       8,    85,     9,    78,    10,    79,    80,    83,    86,     9,
      11,    10,    77,    12,    84,     0,    49,    11,     0,     0,
      12,     0,     4,     5,     6,     7,     0,     8,     0,    17,
      17,     0,     0,     0,     0,    17,     9,     0,    10,     0,
       0,    88,     0,     4,    11,    25,     0,    12,     4,     5,
       6,     7,     0,     8,     0,    46,     0,    25,     0,    10,
       0,     0,     9,     0,    10,    11,     0,     0,    12,     0,
      11,    10,     0,    12,     0,     0,     0,    11,     0,     0,
      47,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,     0,     0,     0,    42,    43,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,    54,
       0,     0,     0,    42,    43,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,    71,
      42,    43,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,    73,     0,     0,     0,    42,    43,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
      74,     0,     0,     0,    42,    43,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,     0,     0,     0,
       0,    42,    43,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67
};

static const yytype_int8 yycheck[] =
{
       2,    10,     0,    11,     3,     3,     4,     5,     6,     3,
       8,     0,    21,    22,    23,    24,    19,    78,    79,    17,
      18,    19,    26,    27,    22,    86,    19,    25,    28,    28,
      28,    17,    17,     3,    29,    29,    44,    45,     3,     4,
       5,     6,    19,     8,    17,     3,     4,     5,     6,    20,
       8,     7,    17,    21,    19,    21,    77,    22,    21,    17,
      25,    19,    71,    28,    22,    -1,    21,    25,    -1,    -1,
      28,    -1,     3,     4,     5,     6,    -1,     8,    -1,    81,
      82,    -1,    -1,    -1,    -1,    87,    17,    -1,    19,    -1,
      -1,    22,    -1,     3,    25,     5,    -1,    28,     3,     4,
       5,     6,    -1,     8,    -1,     3,    -1,     5,    -1,    19,
      -1,    -1,    17,    -1,    19,    25,    -1,    -1,    28,    -1,
      25,    19,    -1,    28,    -1,    -1,    -1,    25,    -1,    -1,
      28,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    25,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,     0,     3,     4,     5,     6,     8,    17,
      19,    25,    28,    33,    34,    35,    36,    37,    40,    41,
      42,    18,    19,    19,    19,     5,    37,    40,    42,    28,
      43,    17,    17,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    24,    25,    26,    27,     3,    28,    40,    43,
      38,    40,    40,    40,    20,     3,    44,    29,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    42,    42,
      20,    23,    39,    20,    20,     3,    29,    40,    21,    21,
      39,    32,    32,    22,    22,     7,    21,    32,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    34,    34,    35,    35,    36,    37,
      38,    38,    39,    39,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    41,    41,    41,    42,    42,
      42,    42,    42,    42,    43,    44,    44,    44
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     2,     3,     3,     3,     7,    11,     7,     4,
       2,     0,     3,     0,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     1,     0
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
  case 2: /* PROGRAM: STATEMENTS  */
#line 61 "calcilist.y"
                                               { printf("Program execution complete.\n"); (yyval.list_val) = (yyvsp[0].list_val); }
#line 1224 "calcilist.tab.c"
    break;

  case 3: /* STATEMENTS: STATEMENTS STATEMENT  */
#line 64 "calcilist.y"
                                               { (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1230 "calcilist.tab.c"
    break;

  case 4: /* STATEMENTS: %empty  */
#line 65 "calcilist.y"
                                              { (yyval.list_val) = NULL; }
#line 1236 "calcilist.tab.c"
    break;

  case 5: /* STATEMENT: EXPR '\n'  */
#line 68 "calcilist.y"
                                               { printlist((yyvsp[-1].list_val)); (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1242 "calcilist.tab.c"
    break;

  case 6: /* STATEMENT: '\n'  */
#line 69 "calcilist.y"
                                               { (yyval.list_val) = NULL; }
#line 1248 "calcilist.tab.c"
    break;

  case 7: /* STATEMENT: ASSIGN '\n'  */
#line 70 "calcilist.y"
                                               { (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1254 "calcilist.tab.c"
    break;

  case 8: /* STATEMENT: TYPE  */
#line 71 "calcilist.y"
                                               { free((yyvsp[0].str_val)); (yyval.list_val) = NULL; }
#line 1260 "calcilist.tab.c"
    break;

  case 9: /* STATEMENT: ID  */
#line 72 "calcilist.y"
                                               { printf("Value of %s: ", (yyvsp[0].str_val)); PrintList(getVarVal((yyvsp[0].str_val)), 0); free((yyvsp[0].str_val)); (yyval.list_val) = NULL; }
#line 1266 "calcilist.tab.c"
    break;

  case 10: /* STATEMENT: IF_STATEMENT  */
#line 73 "calcilist.y"
                                               { (yyval.list_val) = (yyvsp[0].list_val); }
#line 1272 "calcilist.tab.c"
    break;

  case 11: /* STATEMENT: WHILE_STATEMENT  */
#line 74 "calcilist.y"
                                               { (yyval.list_val) = (yyvsp[0].list_val); }
#line 1278 "calcilist.tab.c"
    break;

  case 12: /* STATEMENT: FUNCTION_CALL '\n'  */
#line 75 "calcilist.y"
                                               { printlist((yyvsp[-1].list_val)); (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1284 "calcilist.tab.c"
    break;

  case 13: /* ASSIGN: ID '=' NUM  */
#line 78 "calcilist.y"
                                               { list *n = NewNode(); n->value = (yyvsp[0].num_val); updateVar((yyvsp[-2].str_val), n); free((yyvsp[-2].str_val)); (yyval.list_val) = n; }
#line 1290 "calcilist.tab.c"
    break;

  case 14: /* ASSIGN: ID '=' LIST  */
#line 79 "calcilist.y"
                                               { list *reversed = ReverseList((yyvsp[0].list_val)); updateVar((yyvsp[-2].str_val), reversed); free((yyvsp[-2].str_val)); (yyval.list_val) = reversed; }
#line 1296 "calcilist.tab.c"
    break;

  case 15: /* ASSIGN: ID '=' EXPR  */
#line 80 "calcilist.y"
                                               { updateVar((yyvsp[-2].str_val), (yyvsp[0].list_val)); free((yyvsp[-2].str_val)); (yyval.list_val) = (yyvsp[0].list_val); }
#line 1302 "calcilist.tab.c"
    break;

  case 16: /* IF_STATEMENT: IF '(' EXPR ')' '{' STATEMENTS '}'  */
#line 84 "calcilist.y"
                                               { 
                                                   if (EvaluateCondition((yyvsp[-4].list_val)) != 0.0) {
                                                       printf("Condition evaluated to true.\n");
                                                   } else {
                                                       printf("Condition evaluated to false.\n");
                                                   }
                                                   (yyval.list_val) = (yyvsp[-1].list_val);
                                               }
#line 1315 "calcilist.tab.c"
    break;

  case 17: /* IF_STATEMENT: IF '(' EXPR ')' '{' STATEMENTS '}' ELSE '{' STATEMENTS '}'  */
#line 93 "calcilist.y"
                                               { 
                                                   if (EvaluateCondition((yyvsp[-8].list_val)) != 0.0) {
                                                       printf("If-block executed.\n");
                                                       (yyval.list_val) = (yyvsp[-5].list_val);
                                                   } else {
                                                       printf("Else-block executed.\n");
                                                       (yyval.list_val) = (yyvsp[-1].list_val);
                                                   }
                                               }
#line 1329 "calcilist.tab.c"
    break;

  case 18: /* WHILE_STATEMENT: WHILE '(' EXPR ')' '{' STATEMENTS '}'  */
#line 105 "calcilist.y"
                                               {
                                                   printf("While loop encountered.\n");
                                                   (yyval.list_val) = (yyvsp[-1].list_val);
                                               }
#line 1338 "calcilist.tab.c"
    break;

  case 19: /* FUNCTION_CALL: ID '(' EXPR_LIST ')'  */
#line 111 "calcilist.y"
                                              { (yyval.list_val) = ExecuteExternalCall((yyvsp[-3].str_val), (yyvsp[-1].list_val)); free((yyvsp[-3].str_val)); }
#line 1344 "calcilist.tab.c"
    break;

  case 20: /* EXPR_LIST: EXPR EXPR_TAIL  */
#line 114 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[-1].list_val); /* EXPR_TAIL handles chaining */ }
#line 1350 "calcilist.tab.c"
    break;

  case 21: /* EXPR_LIST: %empty  */
#line 115 "calcilist.y"
                                              { (yyval.list_val) = NULL; }
#line 1356 "calcilist.tab.c"
    break;

  case 22: /* EXPR_TAIL: ',' EXPR EXPR_TAIL  */
#line 118 "calcilist.y"
                                              { (yyvsp[-1].list_val)->rest = (yyvsp[0].list_val); (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1362 "calcilist.tab.c"
    break;

  case 23: /* EXPR_TAIL: %empty  */
#line 119 "calcilist.y"
                                              { (yyval.list_val) = NULL; }
#line 1368 "calcilist.tab.c"
    break;

  case 24: /* EXPR: EXPR '+' TERM  */
#line 122 "calcilist.y"
                                              { (yyval.list_val) = Add((yyvsp[-2].list_val), (yyvsp[0].list_val)); }
#line 1374 "calcilist.tab.c"
    break;

  case 25: /* EXPR: EXPR '-' TERM  */
#line 123 "calcilist.y"
                                              { (yyval.list_val) = Subtract((yyvsp[-2].list_val), (yyvsp[0].list_val)); }
#line 1380 "calcilist.tab.c"
    break;

  case 26: /* EXPR: TERM  */
#line 124 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[0].list_val); }
#line 1386 "calcilist.tab.c"
    break;

  case 27: /* EXPR: EXPR EQ TERM  */
#line 125 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 1); }
#line 1392 "calcilist.tab.c"
    break;

  case 28: /* EXPR: EXPR NEQ TERM  */
#line 126 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 2); }
#line 1398 "calcilist.tab.c"
    break;

  case 29: /* EXPR: EXPR LT TERM  */
#line 127 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 3); }
#line 1404 "calcilist.tab.c"
    break;

  case 30: /* EXPR: EXPR GT TERM  */
#line 128 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 4); }
#line 1410 "calcilist.tab.c"
    break;

  case 31: /* EXPR: EXPR LE TERM  */
#line 129 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 5); }
#line 1416 "calcilist.tab.c"
    break;

  case 32: /* EXPR: EXPR GE TERM  */
#line 130 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 6); }
#line 1422 "calcilist.tab.c"
    break;

  case 33: /* EXPR: EXPR AND TERM  */
#line 131 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 7); }
#line 1428 "calcilist.tab.c"
    break;

  case 34: /* EXPR: EXPR OR TERM  */
#line 132 "calcilist.y"
                                              { (yyval.list_val) = Compare((yyvsp[-2].list_val), (yyvsp[0].list_val), 8); }
#line 1434 "calcilist.tab.c"
    break;

  case 35: /* TERM: TERM '*' FACTOR  */
#line 135 "calcilist.y"
                                              { (yyval.list_val) = Multiply((yyvsp[-2].list_val), (yyvsp[0].list_val)); }
#line 1440 "calcilist.tab.c"
    break;

  case 36: /* TERM: TERM '/' FACTOR  */
#line 136 "calcilist.y"
                                              { (yyval.list_val) = Divide((yyvsp[-2].list_val), (yyvsp[0].list_val)); }
#line 1446 "calcilist.tab.c"
    break;

  case 37: /* TERM: FACTOR  */
#line 137 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[0].list_val); }
#line 1452 "calcilist.tab.c"
    break;

  case 38: /* FACTOR: '(' EXPR ')'  */
#line 140 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1458 "calcilist.tab.c"
    break;

  case 39: /* FACTOR: NUM  */
#line 141 "calcilist.y"
                                              { list *n = NewNode(); n->value = (yyvsp[0].num_val); (yyval.list_val) = n; }
#line 1464 "calcilist.tab.c"
    break;

  case 40: /* FACTOR: '[' LIST ']'  */
#line 142 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1470 "calcilist.tab.c"
    break;

  case 41: /* FACTOR: ID  */
#line 143 "calcilist.y"
                                              { (yyval.list_val) = getVarVal((yyvsp[0].str_val)); free((yyvsp[0].str_val)); }
#line 1476 "calcilist.tab.c"
    break;

  case 42: /* FACTOR: '-' FACTOR  */
#line 144 "calcilist.y"
                                              { (yyval.list_val) = Negate((yyvsp[0].list_val)); }
#line 1482 "calcilist.tab.c"
    break;

  case 43: /* FACTOR: FUNCTION_CALL  */
#line 145 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[0].list_val); }
#line 1488 "calcilist.tab.c"
    break;

  case 44: /* LIST: '[' NUM_LIST ']'  */
#line 148 "calcilist.y"
                                              { (yyval.list_val) = (yyvsp[-1].list_val); }
#line 1494 "calcilist.tab.c"
    break;

  case 45: /* NUM_LIST: NUM_LIST NUM  */
#line 151 "calcilist.y"
                                              { list *n = NewNode(); n->value = (yyvsp[0].num_val); n->rest = (yyvsp[-1].list_val); (yyval.list_val) = n; printf("NUM_LIST: Added %g\n", (yyvsp[0].num_val)); }
#line 1500 "calcilist.tab.c"
    break;

  case 46: /* NUM_LIST: NUM  */
#line 152 "calcilist.y"
                                              { list *n = NewNode(); n->value = (yyvsp[0].num_val); (yyval.list_val) = n; printf("NUM_LIST: Started with %g\n", (yyvsp[0].num_val)); }
#line 1506 "calcilist.tab.c"
    break;

  case 47: /* NUM_LIST: %empty  */
#line 153 "calcilist.y"
                                              { (yyval.list_val) = NULL; }
#line 1512 "calcilist.tab.c"
    break;


#line 1516 "calcilist.tab.c"

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

#line 155 "calcilist.y"


/* C Code Section */

int varCount = 0;
#define MAX_VARS 150
Variable *symbolTable[MAX_VARS];

int nodecount = 0;

/* Function to reverse a list */
list *ReverseList(list *lst) {
    list *prev = NULL;
    list *current = lst;
    list *next = NULL;

    while (current) {
        next = current->rest;
        current->rest = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/* Evaluate expression to C literal */
char *EvaluateToLiteral(list *expr, int use_c_delimiters) {
    if (!expr) return strdup("0.0");

    char *result = (char *)malloc(1024 * sizeof(char));
    result[0] = '\0';

    if (!expr->rest && !expr->first) {
        /* Scalar */
        snprintf(result, 1024, "%g", expr->value);
    } else {
        /* Vector */
        list *current = expr;
        strcat(result, use_c_delimiters ? "{" : "[");
        while (current) {
            char temp[32];
            snprintf(temp, 32, "%g", current->value);
            strcat(result, temp);
            current = current->rest;
            if (current) strcat(result, use_c_delimiters ? ", " : " ");
        }
        strcat(result, use_c_delimiters ? "}" : "]");
    }

    return result;
}

/* Execute external function call */
list *ExecuteExternalCall(char *func_name, list *args) {
    /* Find function in table */
    MathFunc func = NULL;
    for (int i = 0; mathFunctions[i].name; i++) {
        if (strcmp(func_name, mathFunctions[i].name) == 0) {
            func = mathFunctions[i].func;
            break;
        }
    }

    if (!func) {
        printf("Error: Unknown function %s\n", func_name);
        list *result = NewNode();
        result->value = 0.0;
        return result;
    }

    list *result = NewNode();

    if (!args) {
        /* No arguments - invalid */
        printf("Error: Function %s requires arguments\n", func_name);
        result->value = 0.0;
        return result;
    }

    if (!args->rest && !args->first) {
        /* Single scalar argument */
        result->value = func(args->value);
    } else {
        /* Vector argument */
        list *current = args;
        list *result_current = result;
        while (current) {
            result_current->value = func(current->value);
            current = current->rest;
            if (current) {
                result_current->rest = NewNode();
                result_current = result_current->rest;
            }
        }
    }

    return result;
}

/* Modified PrintList to support C-style delimiters */
void PrintList(list *l, int use_c_delimiters) {
    if (!l) return;
    printf("%s", use_c_delimiters ? "{" : "[");
    list *current = l;
    while (current) {
        printf("%g", current->value);
        current = current->rest;
        if (current) printf("%s", use_c_delimiters ? ", " : " ");
    }
    printf("%s", use_c_delimiters ? "}" : "]");
}

int findVar(char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(symbolTable[i]->name, name) == 0)
            return i;
    }
    return -1;
}

void insertVar(char *name, list *value) {
    if (varCount >= MAX_VARS) {
        printf("Error: Variable table is full! Please retry.\n");
        exit(1);
    }
    
    if (findVar(name) != -1) {
        printf("Error: Variable '%s' is already declared! Please retry.\n", name);
        exit(1);
    }
    symbolTable[varCount] = (Variable *)malloc(sizeof(Variable));
    strcpy(symbolTable[varCount]->name, name);
    symbolTable[varCount]->value = value;
    varCount++;
}

void updateVar(char *name, list *value) {
    int index = findVar(name);
    
    if (index == -1) {
        insertVar(name, value);
        return;
    }

    symbolTable[index]->value = value;
}

list *CopyList(list *src) {
    if (!src) return NULL;

    list *head = NewNode();
    list *current = head;
    list *src_current = src;

    current->value = src_current->value;
    while (src_current->rest) {
        src_current = src_current->rest;
        current->rest = NewNode();
        current = current->rest;
        current->value = src_current->value;
    }

    return head;
}

list *getVarVal(char *name) {
    int index = findVar(name);
    
    if (index == -1) {
        list *defaultVal = NewNode();
        defaultVal->value = 0.0;
        insertVar(name, defaultVal);
        return CopyList(defaultVal);
    }
    return CopyList(symbolTable[index]->value);
}

list *NewNode(void) {
    list *temp = (list *)malloc(sizeof(list));
    if (temp) {
        nodecount++;
        temp->first = NULL;
        temp->rest = NULL;
        temp->value = 0.0;
        temp->name = (char *)malloc(100 * sizeof(char));
        if (!temp->name) {
            printf("Memory allocation failed for node name\n");
            exit(1);
        }
        temp->name[0] = '\0';
    } else {
        printf("Memory allocation failed for new node\n");
        exit(1);
    }
    return temp;
}

void FreeRecursive(list *l) {
    while (l) {
        list *next = l->rest;
        free(l->name);
        free(l);
        nodecount--;
        l = next;
    }
}

void AddAtomToList(double num, list *l) {
    list *current = l;
    while (current) {
        current->value += num;
        current = current->rest;
    }
}

list *Add(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) return CopyList(two);
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        result = CopyList(one);
        AddAtomToList(two->value, result);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        AddAtomToList(one->value, result);
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            current->value = p1->value + p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

void MultiplyAtomToList(double num, list *l) {
    list *current = l;
    while (current) {
        current->value *= num;
        current = current->rest;
    }
}

list *Multiply(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) return CopyList(two);
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        result = CopyList(one);
        printf("Multiplying list by scalar %g\n", two->value);
        MultiplyAtomToList(two->value, result);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        printf("Multiplying list by scalar %g\n", one->value);
        MultiplyAtomToList(one->value, result);
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            current->value = p1->value * p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

void SubtractAtomFromList(double num, list *l) {
    list *current = l;
    while (current) {
        current->value -= num;
        current = current->rest;
    }
}

list *Subtract(list *one, list *two) {
    if (!(one || two)) return NULL;
    if (one && !two) return CopyList(one);
    if (!one && two) {
        list *result = CopyList(two);
        MultiplyAtomToList(-1, result);
        return result;
    }
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        result = CopyList(one);
        SubtractAtomFromList(two->value, result);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        MultiplyAtomToList(-1, result);
        AddAtomToList(one->value, result);
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            current->value = p1->value - p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

void DivideListByAtom(list *l, double num) {
    if (num == 0) {
        printf("Error: Division by zero!\n");
        exit(1);
    }
    list *current = l;
    while (current) {
        current->value /= num;
        current = current->rest;
    }
}

list *Divide(list *one, list *two) {
    if (!one) return NULL;
    if (!two) {
        printf("Error: Division by NULL!\n");
        exit(1);
    }
    
    list *result = NewNode();
    
    if (two->rest == NULL && !two->first) {
        if (two->value == 0) {
            printf("Error: Division by zero!\n");
            exit(1);
        }
        result = CopyList(one);
        DivideListByAtom(result, two->value);
    } else if (one->rest == NULL && !one->first) {
        result = CopyList(two);
        list *current = result;
        while (current) {
            if (current->value == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            current->value = one->value / current->value;
            current = current->rest;
        }
    } else {
        list *p1 = one, *p2 = two;
        list *current = result;
        while (p1 && p2) {
            if (p2->value == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            current->value = p1->value / p2->value;
            p1 = p1->rest;
            p2 = p2->rest;
            if (p1 && p2) {
                current->rest = NewNode();
                current = current->rest;
            }
        }
    }
    
    return result;
}

list *Negate(list *l) {
    if (!l) return NULL;
    
    list *result = CopyList(l);
    MultiplyAtomToList(-1, result);
    
    return result;
}

list *Compare(list *one, list *two, int operation) {
    if (!(one && two)) return NULL;
    
    list *result = NewNode();
    
    if (one->rest == NULL && !one->first && two->rest == NULL && !two->first) {
        switch (operation) {
            case 1: // EQ
                result->value = (one->value == two->value) ? 1.0 : 0.0;
                break;
            case 2: // NEQ
                result->value = (one->value != two->value) ? 1.0 : 0.0;
                break;
            case 3: // LT
                result->value = (one->value < two->value) ? 1.0 : 0.0;
                break;
            case 4: // GT
                result->value = (one->value > two->value) ? 1.0 : 0.0;
                break;
            case 5: // LE
                result->value = (one->value <= two->value) ? 1.0 : 0.0;
                break;
            case 6: // GE
                result->value = (one->value >= two->value) ? 1.0 : 0.0;
                break;
            case 7: // AND
                result->value = (one->value && two->value) ? 1.0 : 0.0;
                break;
            case 8: // OR
                result->value = (one->value || two->value) ? 1.0 : 0.0;
                break;
            default:
                result->value = 0.0;
        }
    } else {
        result->value = 0.0;
    }
    
    return result;
}

double EvaluateCondition(list *expr) {
    if (!expr) return 0.0;
    
    if (expr->rest || expr->first) {
        return EvaluateCondition(expr->rest ? expr->rest : expr->first);
    } else {
        return expr->value;
    }
}

int main(int argc, char *argv[]) {
    printf("WizuAll Vector Calculator\n");
    printf("Start Typing: \n");
    yyparse();
    return 0;
}
