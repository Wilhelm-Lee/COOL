/*
 *     This file is part of project https://github.com/WilliamPascal/COOL
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

#ifndef IANDS_H
#define IANDS_H

#include <stdlib.h>

#define MAX_SBUFF 32

static char *__restrict__ _SBUFF = (char *)malloc(sizeof(char) * MAX_SBUFF);

static inline void
_erase_sbuff(char *__restrict__ _SBUFF)
{
  for (register int i = 0; i < MAX_SBUFF; i ++)
    {
      _SBUFF[i] = 0;
    }
}

#endif /* NO IANDS_H */
