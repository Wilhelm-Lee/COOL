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

#ifndef oBJECTS_H
# define oBJECTS_H

#include "object.h"

typedef enum _objects_move_direction_e
{
  STAY = 0,
  BACKWARD = -1,
  FORWARD = 1
} _objects_move_direction_e;

typedef uint16_t _objects_move_indicator_t;
# ifndef _OBJS_MOV_INDIC_MAX
#  define _OBJS_MOV_INDIC_MAX 0b10000000000000000L /* 65536 */
# endif /* NO _OBJS_MOV_INDIC_MAX */

# ifndef _OBJS_MOV_INDIC_MIN
#  define _OBJS_MOV_INDIC_MIN 0b0L /* 0 */
# endif /* NO _OBJS_MOV_INDIC_MIN */

# ifndef _OBJ_MOV_INDIC_DEF
#  define _OBJ_MOV_INDIC_DEF (_OBJS_MOV_INDIC_MAX / 2)
# endif /* NO _OBJ_MOV_INDIC_DEF */

typedef struct objects {

  _objects_move_indicator_t _indic;

  /* Horizontal logic */
  struct objects *_prev;
  struct objects *_this;
  struct objects *_next;

  /* Vertical logic */
  struct objects *_super;
  struct objects *_successor;
  
  object *_obj;
} objects;

static objects nullobjs = {_OBJS_MOV_INDIC_MIN,
                           &nullobjs, &nullobjs, &nullobjs,
                           &nullobjs, &nullobjs,
                           nullobjptr};
static objects *nullobjsptr = &nullobjs;

static __inline__ void
_objects_inherit(objects *dst, objects *src, _objects_move_indicator_t _indic)
{
  dst->_indic = _indic;
  dst->_obj = src->_obj;
  dst->_prev = src->_prev;
  dst->_this = src->_this;
  dst->_next = src->_next;
  dst->_super = src;
  dst->_successor = nullobjsptr;
}

static __inline__ objects*
_objects_move(objects *tar, _objects_move_direction_e direction,
              objects *fillup)
{
  objects *felloff = NULL;
  switch (direction)
    {
      case STAY:
        return tar;

      case FORWARD:
        felloff = tar->_next;
        tar->_next = tar->_this;
        tar->_this = tar->_prev;
        tar->_prev = fillup;
        return felloff;

      case BACKWARD:
        felloff = tar->_prev;
        tar->_prev = tar->_this;
        tar->_this = tar->_next;
        tar->_next = fillup;
        return felloff;
      
      default:
        THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
              _EXCEP_FMT);
    }
}

#endif /* NO oBJECTS_H */
