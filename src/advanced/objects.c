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

#include "objects.h"

void
_objects_succeed(objects_t *dst, objects_t *src,
                 _objects_move_indicator_t _indic)
{
  dst->_indic = _indic;
  dst->_obj = src->_obj;
  dst->_prev = src->_prev;
  dst->_next = src->_next;
  dst->_super = src;
  dst->_successor = nullobjsptr;
}

bool
_objects_equals(objects_t *a, objects_t *b)
{
  return (_object_equals(a->_obj, b->_obj)
          && (a->_indic == b->_indic));
}

bool
_objects_is(objects_t *a, objects_t *b)
{
  return (((void *)a) == ((void *)b));
}

_objects_relation_e
_objects_relation(objects_t *a, objects_t *b)
{
  if (_objects_equals(a, nullobjsptr)
      || _objects_equals(b, nullobjsptr))
    return (NONE);

  /* B is the PREV to A */
  if (_objects_equals(a->_prev, b))
    return (PREV);
  /* B is the NEXT to A */
  if (_objects_equals(a->_next, b))
    return (NEXT);
  /* B is the SUPER to A */
  if (_objects_equals(a->_super, b))
    return (SUPER);
  /* B is the SUCCESSOR to A */
  if (_objects_equals(a->_successor, b))
    return (SUCCESSOR);
  /* B equals as A */
  if (_objects_equals(a, b))
    return (EQUAL);
  /* B is A */
  if (_objects_is(a, b))
    return (SELF);

  return (UNKNOWN);
}

objects_t*
_objects_move(objects_t *tar, _objects_move_direction_e direction,
              objects_t *fillup)
{
  objects_t *felloff = NULL;
  switch (direction)
    {
      case STAY:
        return tar;

      case FORWARD:
        felloff = tar->_next;
        tar->_prev = fillup;
        tar->_indic += FORWARD;  /* +1 */
        return felloff;

      case BACKWARD:
        felloff = tar->_prev;
        tar->_next = fillup;
        tar->_indic += BACKWARD;  /* -1 */
        return felloff;

      default:
        THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
              _EXCEP_FMT);
    }
}
