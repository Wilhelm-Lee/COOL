#include "object.h"

bool
_object_equals(object_t *a, object_t *b)
{
  return
    (_array_equals(a->_fields, b->_fields)
     && _array_equals(a->_methods, b->_methods));
}
