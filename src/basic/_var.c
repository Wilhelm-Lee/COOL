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

#include "_var.h"

void
_var_new(var_t *v, size_t _sz, char *_val)
{
  v->_addr = malloc(_sz);

  /* Null pointer check */
  if (v->_addr == NULL)
    THROW(InstanceFailureException, __FILE__, __LINE__, __FUNCTION__,
          "Cannot properly malloc");

  v->_val = _val;
}

void
_var_del(var_t *v)
{
  free(v->_val);
  free(v->_addr);
  free(v);

  /* Since a pointer would not be removed after it has been freed, therefor
  the best way to make it still legal to access is to let it point towards NULL
  */
  v = NULL;
}

void
_var_ren(var_t *v, size_t _sz, char *_val)
{
  /* Detect _v had not been allocated */
  if (v->_addr == NULL && v->_sz == 0)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Cannot reallocate before any initial allocations being done first.");

  _var_del(v);
  _var_new(v, _sz, _val);
}

int
__var_szcmp(var_t *a, var_t *b)
{
  return (a->_sz - b->_sz);
}

int
_var_cmp(var_t *a, var_t *b)
{
  /* Not identical sizes */
  if (__var_szcmp(a, b))
    return 2;

  return (memcmp(a->_addr, b->_addr, a->_sz));
}

int
_var_cpy(var_t *dst, const var_t *src);

void
_var_swp(var_t *a, var_t *b)
{
  var_t *c;
  _var_new(c, a->_sz, a->_val);

  _var_ren(a, b->_sz, b->_val);
  _var_ren(b, c->_sz, c->_val);

  _var_del(c);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
