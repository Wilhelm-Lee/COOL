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
