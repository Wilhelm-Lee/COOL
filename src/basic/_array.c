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

#include <string.h>
#include "_array.h"

void
__array_pgoto(var_t *ptr, array_t *_src, index_t idx)
{
  if (ptr == NULL)
    THROW(InvalidArgumentException, __FILE__, __LINE__, __FUNCTION__,
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

length_t
_array_calclen(const array_t *arr)
{
  return (strlen((const char *)arr) + 1);
}

length_t
_array_calcvlen(const var_t **varr)
{
  nullchk(varr);

  if (varr[0]->_addr == nullvarptr)
    return -1;

  /* Since varp is used above, and since size of varp is as same as
  char (1 Byte). Thus, having strlen is the same for calculating the length for
  varr */
  return strlen((const char *)varr[0]);
}

var_t*
_array_getelem(array_t *tar, index_t idx)
{
  nullchk(tar);

  if (tar == nullarrptr)
    THROW(InvalidArgumentException, __FILE__, __LINE__, __FUNCTION__,
          "Nulled array(%H) does not support extracting element from it", tar);

  return tar[idx];
}

void
_array_setelem(array_t *tar, index_t idx, var_t *_var);

void
_array_newarr(array_t *tar, length_t len, var_t **varr)
{
  nullchk(varr);

  if (_array_calcvlen((const var_t **)varr) == -1)
    {
      THROW(InvalidArgumentException, __FILE__, __LINE__, __FUNCTION__,
      _EXCEP_FMT);
    }

  tar = (array_t *)malloc(sizeof(varr[0]->_sz) * len);
  for (register length_t i = 0; i < len; i ++)
    {
      if ( (tar[i] = (var_t *)malloc(sizeof(varr[0]->_sz))) == NULL ) /* YOU LEFT HERE */
        THROW(OutOfMemoryException, __FILE__, __LINE__, __FUNCTION__,
        _EXCEP_FMT);
    }
}

void
_array_delarr(array_t *tar)
{
  if (tar == NULL || tar == nullarrptr)
    return;

  for (register length_t i = 0; i < _array_calclen(tar); i ++)
    {
      /* TEST */
      fprintf(stdout, "delarr: [%llu]%p\n", i, tar[i]); /* YOU LEFT HERE */
      /* TEST OVER */
      // _var_del(tar[i]);  /* SEGMENTATION FAULT */
      free(tar[i]);
      // tar[i] = NULL;  /* SEGMENTATION FAULT */
    }
  free(tar);
  tar = NULL;
}

rtn_t
_array_mirror(array_t *dst, const array_t *src);

array_t *
_array_subarr(index_t off, length_t len, array_t *tar);

rtn_t
_array_insert(index_t off, const array_t *src);

rtn_t
_array_cutoff(index_t off, length_t len, array_t *tar);

bool
_array_equals(array_t *dst, array_t *src)
{
  nullchk(dst);
  nullchk(src);

  /* Skip checking once both parameters were "nullarrptr" */
  if (dst == nullarrptr && src == nullarrptr)
    return true;

  /* property storage */
  const length_t _dst_len = _array_calclen(dst);
  const length_t _src_len = _array_calclen(src);

  /* length comparison */
  if (_dst_len != _src_len)
    return false;
  else
    for (register index_t i = 0; i < _dst_len; i++)
      {
        auto var_t *_dst_elem = _array_getelem(dst, i);
        auto var_t *_src_elem = _array_getelem(src, i);
        if (_var_equals(_dst_elem, _src_elem))
          return false;
      }

   return true;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
