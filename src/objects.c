#include "objects.h"

void
_objects_succeed(objects_t *dst, objects_t *src,
                 _objects_move_indicator_t _indic)
{
  dst->_indic = _indic;
  dst->_obj = src->_obj;
  dst->_prev = src->_prev;
  dst->_this = src->_this;
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
        tar->_next = tar->_this;
        tar->_this = tar->_prev;
        tar->_prev = fillup;
        tar->_indic += FORWARD;  /* +1 */
        return felloff;

      case BACKWARD:
        felloff = tar->_prev;
        tar->_prev = tar->_this;
        tar->_this = tar->_next;
        tar->_next = fillup;
        tar->_indic += BACKWARD;  /* -1 */
        return felloff;

      default:
        THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
              _EXCEP_FMT);
    }
}
