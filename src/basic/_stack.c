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

#include "_stack.h"

_stkerr_e
__stack_opercheck(stack_t *_stk, _stkoper_e _oper)
{
  /* Over flowed */
  if ((_stack_calclen(_stk) + 1) == 0)
    {
      return OVERFLOW;
    }
  return NONE;
}

void
_stack_newstk(stack_t *_stk, array_t *_arrp);

void
_stack_delstk(stack_t *_stk);

void
_stack_push(stack_t *_stk);

void
_stack_pop(stack_t *_stk);

length_t
_stack_calclen(stack_t *stk)
{
  return _array_calclen(stk->_arrp);
}
