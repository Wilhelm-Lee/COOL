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

# include "object.h"

typedef enum _objects_move_direction_e
{
  STAY = 0,
  BACKWARD = -1,
  FORWARD = 1
} _objects_move_direction_e;

typedef enum _objects_relation_e
{
  NONE = 0,
  NEXT = 1,
  PREV = -1,
  SUPER = 2,
  SUCCESSOR = -2,
  EQUAL = 3,
  SELF = 4,
  UNKNOWN = 5
} _objects_relation_e;

typedef int16_t _objects_move_indicator_t;
# ifndef _OBJS_MOV_INDIC_MAX
#  define _OBJS_MOV_INDIC_MAX INT16_MAX /* 32767 */
# endif /* NO _OBJS_MOV_INDIC_MAX */

# ifndef _OBJS_MOV_INDIC_MIN
#  define _OBJS_MOV_INDIC_MIN INT16_MIN /* -32767-1 */
# endif /* NO _OBJS_MOV_INDIC_MIN */

# ifndef _OBJS_MOV_INDIC_DEF
#  define _OBJS_MOV_INDIC_DEF (0)
# endif /* NO _OBJS_MOV_INDIC_DEF */ //aa

typedef struct objects_t {
/*
               Super
               O
               |
               |
O--------------O--------------O
prev                          next
               |
               |
               O
               Successor
*/
  _objects_move_indicator_t _indic;

  /* Horizontal logic */
  struct objects_t *_prev;
  struct objects_t *_next;

  /* Vertical logic */
  struct objects_t *_super;
  struct objects_t *_successor;

  object_t *_obj;
} objects_t;

static const objects_t nullobjs =
(objects_t) {
  0,
  (objects_t *)&nullobjs, (objects_t *)&nullobjs,
  (objects_t *)&nullobjs, (objects_t *)&nullobjs,
  nullobjptr
};
# define nullobjsptr ((objects_t *)&nullobjs)

void
_objects_succeed(objects_t *dst, objects_t *src,
                 _objects_move_indicator_t _indic);

bool
_objects_equals(objects_t *a, objects_t *b);

bool
_objects_is(objects_t *a, objects_t *b);

/* Returns 0 when A and B are not related at all;
           1 when A is the NEXT to B;
          -1 when A is the PREV to B;
           2 when A is the SUPER to B;
          -2 when A is the SUCCESSOR to B;
           3 when A equals as B;
           4 when A is B;
           5 when unknown */
_objects_relation_e
_objects_relation(objects_t *a, objects_t *b);

/* Throws InvalidArgumentException */
objects_t*
_objects_move(objects_t *tar, _objects_move_direction_e direction,
              objects_t *fillup);

/* Throws InvalidArgumentException;
          InvalidNullPointerException */
void
_objects_newobjs(objects_t *tar, _objects_move_indicator_t _indic,
                 objects_t *_prev, objects_t *_next,
                 objects_t *_super, objects_t *_successor,
                 object_t *_obj);

void
_objects_delobjs(objects_t *tar);

#endif /* NO oBJECTS_H */
