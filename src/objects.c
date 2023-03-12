#include "objects.h"

void
_objects_succeed(objects *dst, objects *src, _objects_move_indicator_t _indic)
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
_objects_equals(objects *a, objects *b)
{
  return (_object_equals(a->_obj, b->_obj)
          && (a->_indic == b->_indic));
}

objects*
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
        tar->_indic += 1;
        return felloff;

      case BACKWARD:
        felloff = tar->_prev;
        tar->_prev = tar->_this;
        tar->_this = tar->_next;
        tar->_next = fillup;
        tar->_indic -= 1;
        return felloff;

      default:
        THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
              _EXCEP_FMT);
    }
}
