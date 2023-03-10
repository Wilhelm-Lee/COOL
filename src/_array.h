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

/* PLEASE BE AWARE, DIRECTLY CALL ON ANY OF THESE METHODS OR VARIABLES
   IN THIS FILE WOULD EVENTUALLY CAUSE UNMANAGEABLE MEMORY MANAGEMENT. */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _ARRAY_H
# define _ARRAY_H

# include <stdio.h>
# include "_var.h"
# include "_rtn.h"

# ifndef ARRAY_T
typedef var_t* array_t;
#  define ARRAY_T
# endif  /* ARRAY_T */

/* VARRP is stands for "Variadic size Array Pointer" */
# ifndef VARRP
typedef array_t* varrp;
#  define VARRP
# endif /* NO VARRP */

static array_t nullarr = &nullvar;
static array_t *nullarrptr = &nullvarptr;

/* By calculating relative element size, then times idx to get the
   absolute position in array _SRC
   Throws IllegalArgumentException */
void
__array_pgoto(var_t *ptr, array_t *_src, index_t idx);

length_t
__array_arrlen();

/* Returns length of given array of array_t;
   -1 if not available. */
length_t
_array_calclen(const array_t *arr);

/* Returns length of given array of vat_t*;
   -1 if not available. k*/
length_t
_array_calcvlen(const var_t *varr);

/* Throws IllegalArgumentException */
var_t*
_array_getelem(array_t *tar, index_t idx);

/* Throws IllegalArgumentException */
void
_array_setelem(array_t *tar, index_t idx, var_t *var);

/* As varr being initial source, tar will be validated within size _SZ, length
   for len.
   Throws InstanceFailureException
          IllegalArgumentException */
void
_array_newarr(array_t *tar, size_t _sz, length_t len, const var_t *varr);

void
_array_delarr(array_t *tar);

/* TipsForDevls: Reallocate _DST's size when the size of _SRC & _DST
   does not match */
_rtn_t
_array_mirror(array_t *dst, const array_t *src);

/* Returns subarray extracted from _src
   start from index (off - 1) till index (off + len - 1)
   Throws OutOfBoundException */
array_t *
_array_subarr(index_t off, length_t len, array_t *tar);

/* Throws OutOfBoundException,
          IllegalArgumentException */
_rtn_t
_array_insert(index_t off, const array_t *src);

/* Throws OutOfBoundException */
_rtn_t
_array_cutoff(numberic_t off, length_t len, array_t *tar);

/* Returns true if identical */
bool
_array_cmparr(array_t *dst, const array_t *src);

#endif /* NO _ARRAY_H */

#ifdef __cplusplus
}
#endif /* __cplusplus */
