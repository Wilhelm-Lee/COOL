/*
 *     This file is part of project  <https://github.com/WilliamPascal/COOL>
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

#include "_array.h"

/* By calculating relative element size, then times idx to get the
   absolute position in array _SRC
   Throws IllegalArgumentException
          OutOfBoundException */
void
__array_pgoto(var_t *ptr, array_t *_src, index_t idx)
{
  if (ptr == NULL)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Variable %H is improperly nulled", ptr);

  length_t _src_len = _array_calclen(_src);
  if (idx > _src_len)
    THROW(OutOfBoundException, __FILE__, __LINE__, __FUNCTION__,
          "Array %H\nStarts at %H\nEnds at %H\nLength is %lu\n\
Given idx was %lu which is out of bound for %lu",
          _src, _src,
          (_src + _src_len), _src_len, idx,
          (idx - _src_len));

  ptr = _array_getelem(_src, idx);
}

/* Returns length of given array of array_t;
   -1 if not available. */
length_t
_array_calclen(const array_t *arr)
{
  /* TEST: NOT FINISHED */
  return 0;
  /* TEST OVER */

}

/* Returns length of given array of vat_t*;
   -1 if not available. */
length_t
_array_calcvlen(const var_t *varr)
{
  if (varr->_addr == NULL)
    return -1;

  /* Since varp is used above, and since size of varp is as same as
  char (1 Byte), Thus, having strlen is the same for calculating the length for
  varr */
  return strlen((const char *)varr);
}

/* Throws IllegalArgumentException */
var_t*
_array_getelem(array_t *tar, index_t idx)
{
  if (tar == NULL)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Nulled array(%H) does not support extracting element from it", tar);

  return tar[idx];
}

/* Throws IllegalArgumentException */
void
_array_setelem(array_t *tar, index_t idx, var_t *_var);

/* As arr being initial source, tar will be validated within size _SZ, length
   for len.
   To be able to fit function strlen from string.h, a null character will be
   added in order to make sense for it.
   Throws InstanceFailureException
          IllegalArgumentException */
void
_array_newarr(array_t *tar, size_t _sz, length_t len, const var_t *varr)
{
  if (varr == NULL)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Initial arr should not be NULL");

  if (varr->_sz != _sz)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Sizes do not match, cannot start initalisation");

  const length_t _vlen = _array_calcvlen(varr);
  if (_vlen == -1)
    THROW(IllegalArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Cannot instant an array with varr(%H:%llu) given nulled",
          varr->_addr, 	varr->_sz);
  else /* Start allocatoins */
    {
      /* Inorder to properly handle strings, '\0' would requires one more byte while
         allocating.
      Plus one for null character ('\0') */
      tar = (varrp)malloc(_sz * len + 1);
      for (register length_t i = 0; i < len; i ++)
        {
          tar[i]->_addr = malloc(_sz);
        }

      /* Stamp on null character ('\0') */
      tar[len + 1]->_addr = malloc(sizeof(vars));
      tar[len + 1] = NULL;
    }
}

void
_array_delarr(array_t *tar);
/* PLEASE DO REMEMBER TO REMOVE NULL CHARACTER AT THE END OF THE ARRAY */

/* TipsForDevls: Reallocate _DST's size when the size of _SRC & _DST
   does not match */
_rtn_t
_array_mirror(array_t *dst, const array_t *src);

/* Returns subarray extracted from _src
   start from index (	off - 1) till index (	off + len - 1)
   Throws OutOfBoundException */
array_t *
_array_subarr(index_t off, length_t len, array_t *tar);

/* Throws OutOfBoundException,
          IllegalArgumentException */
_rtn_t
_array_insert(index_t off, const array_t *src);

/* Throws OutOfBoundException */
_rtn_t
_array_cutoff(index_t off, length_t len, array_t *tar);

/* Returns true if identical */
bool
_array_cmparr(array_t *dst, const array_t *src);

#ifdef __cplusplus
}
#endif /* __cplusplus */
