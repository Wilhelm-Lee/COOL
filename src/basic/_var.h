/*
 *     This file is part of project <https://github.com/WilliamPascal/COOL>
 *     Copyright (C) 2023  William Pascal
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _VAR_H
# define _VAR_H

# include <sys/cdefs.h> /* __BEGIN_DECLS; __END_DECLS */
# include <stdbool.h>
# include <stdint.h>
# include "_exception.h"

#ifdef __cplusplus
__BEGIN_DECLS
#endif /* __cplusplus */

/* Extern from _exception.h */
extern __inline__ void
THROW(excep_e e, const char *__restrict__ __file__, long int __line__,
      const char *__restrict__ __function__, const char *__restrict__ _FMT,...);

/* When converting void into ptr with 1 Byte size as char is, we call it vars.
   It stands for "variable size" */
# ifndef VARS
typedef char vars;
#  define VARS
# endif /* NO VARS */

/* When converting void into ptr with 8 Bytes size as char* is, we call it varp.
   It stands for "variable pointer" */
# ifndef VARP
typedef vars* varp;
#  define VARP
# endif /* NO VARP */

# ifndef NUMERIC_T
/**
 _______________________________________________
 |     TYPE      | 16 bits | 32 bits | 64 bits |
 |===============|=========|=========|=========|
 | char          |   1 B   |   1 B   |   1 B   |
 | short         |   2 B   |   2 B   |   2 B   |
 | int           |   2 B   |   4 B   |   4 B   |
 | unsigned int  |   2 B   |   4 B   |   4 B   |
 | float         |   4 B   |   4 B   |   4 B   |
 | double        |   8 B   |   8 B   |   8 B   |
 | long          |   4 B   |   4 B   |   8 B   |
 | long long     |   8 B   |   8 B   |   8 B   |
 | unsigned long |   4 B   |   4 B   |   8 B   |
 | ptr           |   2 B   |   4 B   |   8 B   |
 | MAX STORAGE   |   2^16  |   2^32  |   2^64  |
 -----------------------------------------------
 **/
#  if defined _WIN64 || defined __x86_64__ || defined __x86_64
typedef uint64_t numeric_t;
#  elif defined _WIN32 || defined __x86_32
typedef uint32_t numeric_t;
#  elif defined _WIN16
typedef uint16_t numeric_t;
#  else
#   error Platform is not supported!
#  endif /* _WIN64 */
#  define NUMERIC_T
# endif /* NO NUMERIC_T */

# ifndef INDEX_T
typedef numeric_t index_t;
#  define INDEX_T
# endif /* NO INDEX_T */

# ifndef LENGTH_T
typedef index_t length_t;
#  define LENGTH_T
# endif /* NO LENGTH_T */

typedef struct _var_t
{
  void *_addr;
  size_t _sz;  /* Used for regenerations of actual value */
  varp _val;   /* Used for temporary value of actual value */
} var_t;

static const var_t nullvar = ((var_t){NULL, 0, NULL});
# define nullvarptr ((var_t *)(&nullvar))

/* Throws InvalidNullPointerException */
void
__var_nullchk(var_t *v);

void
_var_new(var_t *v, size_t _sz, char *_val);

void
_var_del(var_t *v);

/* "ren" stands for "RENew" */
void
_var_ren(var_t *v, size_t _sz, char *_val);

/* Return delta of a->_sz and b->_sz
   If <0, then a<b;
   If =0, then a=b;
   If >0, then a>b;
   Throws InvalidArgumentException */
int
__var_szcmp(var_t *a, var_t *b);

/* Returns true if equals;
   Comparing _sz and _val;
   Throws InvalidNullPointerException */
bool
_var_equals(var_t *a, var_t *b);

/* Returns true if they are the same one;
   Comparing _addr and _sz;
   Throws InvalidNullPointerException */
bool
_var_is(var_t *a, var_t *b);

/* Returns size of copied buff. -1 for error;
   Throws InvalidNullPointerException */
int
_var_cpy(var_t *dst, const var_t *src);

/* Throws InvalidNullPointerException */
void
_var_swp(var_t *a, var_t *b);

#ifdef __cplusplus
__END_DECLS
#endif /* __cplusplus */

#endif /* NO _VAR_H */
