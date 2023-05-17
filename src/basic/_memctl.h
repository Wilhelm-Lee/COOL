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

/* Semi-Auto release malloc-ed memory spaces by using _stack.h */

#ifndef _MEMCTL_H
# define _MEMCTL_H

# include <stdint.h>
# include "_rtn.h"
# include "_array.h"

#ifdef __cplusplus
__BEGIN_DECLS
#endif /* __cplusplus */

# define _MEMSTK_MAX UINT16_MAX

// array_t *__restrict __memstk;
/* TODO */

/**
 * Free all addresses >= IDX in __memstk
 * Throws OutOfBoundException
 */
void
_memctl_stkfree(index_t idx);

#ifdef __cplusplus
__END_DECLS
#endif /* __cplusplus */

#endif /* NO _MEMCTL_H */
