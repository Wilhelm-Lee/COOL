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

#ifndef oBJECT_H
# define oBJECT_H

# include "_array.h"

/* object created here would eventually appears to chained up to a full iterable
   array driven by _array.h named Object. */
typedef struct object
{
  array_t *_fields;
  array_t *_methods;
} object;

static object nullobj = {nullarrptr, nullarrptr};
static object *nullobjptr = &nullobj;

bool
_object_equals(object *a, object *b);

#endif /* NO oBJECT.h */
