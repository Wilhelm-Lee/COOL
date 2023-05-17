#include "object.h"

bool
_object_equals(object_t *a, object_t *b)
{
  return
    (_array_equals(a->_fields, b->_fields)
     && _array_equals(a->_methods, b->_methods));
}

void
_object_delobj(object_t *tar)
{
  if (tar == NULL)
    return;

  _array_delarr(tar->_fields);
  _array_delarr(tar->_methods);
  tar = NULL;
  free(tar);
}
