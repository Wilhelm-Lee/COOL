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
   IN THIS FILE WOULD EVENTUALLY CAUSE UNMANAGEABLE MEMORY MANAGEMENT BY COOL.*/

#ifndef _ARRAY_H
# define _ARRAY_H

# include <stdio.h>
# include "_var.h"
# include "_rtn.h"

#ifdef __cplusplus
__BEGIN_DECLS
#endif /* __cplusplus */

# ifndef ARRAY_T
typedef var_t* array_t;
#  define ARRAY_T
# endif  /* ARRAY_T */

/* VARRP is stands for "Variadic size Array Pointer" */
# ifndef VARRP
typedef array_t* varrp;
#  define VARRP
# endif /* NO VARRP */

static const array_t nullarr = (array_t)(nullvarptr);
# define nullarrptr (array_t *)&nullarr

/* By calculating relative element size, then times idx to get the
   absolute position in array _SRC
   Throws InvalidArgumentException */
void
__array_pgoto(var_t *ptr, array_t *_src, index_t idx);

/* Returns length of given array of array_t; */
length_t
_array_calclen(const array_t *arr);

/* Returns length of given array of var_t*;
   -1 if not available. */
length_t
_array_calcvlen(const var_t **varr);

/* Throws InvalidArgumentException */
var_t*
_array_getelem(array_t *tar, index_t idx);

/* Throws InvalidArgumentException */
void
_array_setelem(array_t *tar, index_t idx, var_t *var);

/* As varr being initial source, tar will be validated within size _SZ, length
   for len.
   Throws InstanceFailureException
          InvalidArgumentException */
void
_array_newarr(array_t *tar, length_t len, var_t **varr);

void
_array_delarr(array_t *tar);

/* TipsForDevls: Reallocate DST's size when the size of SRC & DST
   does not match */
rtn_t
_array_mirror(array_t *dst, const array_t *src);

/* Returns subarray extracted from src
   start from index (off - 1) till index (off + len - 1)
   Throws OutOfBoundException */
array_t *
_array_subarr(index_t off, length_t len, array_t *tar);

/* Throws OutOfBoundException,
          InvalidArgumentException */
rtn_t
_array_insert(index_t off, const array_t *src);

/* Throws OutOfBoundException */
rtn_t
_array_cutoff(numeric_t off, length_t len, array_t *tar);

/* Returns true if identical */
bool
_array_equals(array_t *dst, array_t *src);

#ifdef __cplusplus
__END_DECLS
#endif /* __cplusplus */

#endif /* NO _ARRAY_H */
