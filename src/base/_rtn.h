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

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _RTN_H
# define _RTN_H

# ifndef _RTN_T
#  define _RTN_T
typedef int rtn_t;
# endif /* NO _RTN_T */

# define RETURN_NULLERR -2
# define RETURN_UNKNOWN -1
# define RETURN_FAILURE 0
# define RETURN_SUCCESS 1

#endif /* NO _RTN_H */

#ifdef __cplusplus
}
#endif /* __cplusplus */

