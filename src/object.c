#include "object.h"

bool
_object_equals(object *a, object *b)
{
  return (
      _array_eqauls(a->_fields, b->_fields)
      && _array_eqauls(a->_methods, b->_methods)
  );
}
