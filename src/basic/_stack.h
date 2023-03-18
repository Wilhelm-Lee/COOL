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

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _STACK_H
# define _STACK_H

# include "_array.h"

/* Extern from _exception.h */
extern __inline__ void
THROW(excep_e e, const char *__restrict__ __file__, long int __line__,
      const char *__restrict__ __function__, const char *__restrict__ _FMT, ...);

# ifndef STACK_MAX
#  define STACK_MAX 262144LL  /* 256KiB == 262144B <=> 2^18 */
# endif /* NO STACK_MAX */

typedef struct _stack_t
{
  array_t _store;
  /* ... */
} stack_t;

enum _stkoper_e
{
  PUSH,
  POP,
  PEEK
};

/* Check whether or not _OPERATION would cause any known issues to _STK
   Throws IllegalMemoryAccessException,
          OutOfBoundException */
void
__stack_opercheck(stack_t _stk, _stkoper_e _operation);

void
_stack_newstk(stack_t *_stk);

void
_stack_delstk(stack_t *_stk);

/* Throws EXCEP(__stack_safetycheck) */
void
_stack_push(stack_t *_stk);

void
_stack_pop(stack_t *_stk);

#endif /* NO _STACK_H */

#ifdef __cplusplus
}
#endif /* __cplusplus */

