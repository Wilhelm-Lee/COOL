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

#ifndef _STACK_H
# define _STACK_H

# include "_array.h"

#ifdef __cplusplus
__BEGIN_DECLS
#endif /* __cplusplus */

/* Extern from _exception.h */
extern __inline__ void
THROW(excep_e e, const char *__restrict__ __file__, long int __line__,
      const char *__restrict__ __function__, const char *__restrict__ _FMT, ...);

# ifndef STACK_MAX
#  define STACK_MAX 262144LL  /* 256KiB == 262144B <=> 2^18 */
# endif /* NO STACK_MAX */

typedef enum _stkoper_e
{
  PUSH,
  POP,
  PEEK
} _stkoper_e;

typedef struct stack_t
{
  array_t *_arrp;
  _stkoper_e _oper;
} stack_t;

typedef enum _stkerr_e
{
  NONE = 0,
  OVERFLOW,
} _stkerr_e;

/* Check whether or not _OPER would cause any known issues to STK if went on;
   Returns type of error that occurred
   Throws InvalidNullPointerException;
          IllegalMemoryAccessException;
          OutOfBoundException */
_stkerr_e
__stack_opercheck(stack_t *stk, _stkoper_e _oper);

void
_stack_newstk(stack_t *stk, array_t *_arrp);

void
_stack_delstk(stack_t *stk);

/* Throws InvalidNullPointerException;
          IllegalMemoryAccessException;
          OutOfBoundException */
void
_stack_push(stack_t *stk);

void
_stack_pop(stack_t *stk);

/* Returns length of stk;
   Throws InvalidNullPointerException;
          IllegalMemoryAccessException;
          OutOfBoundException */
length_t
_stack_calclen(stack_t *stk);

#ifdef __cplusplus
__END_DECLS
#endif /* __cplusplus */

#endif /* NO _STACK_H */
