/* Copyright (C) 2021 Peter Markfelder
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public
 * License version 3 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef __ALLOCATE_H_INCLUDED
#define __ALLOCATE_H_INCLUDED 1

#include <neweden/essence/types.h>

#include <stddef.h>
#include <stdlib.h> /* Or any other header that declares malloc, realloc etc. */

void*
allocate(
	size_t size);

int
reallocate(
	void** array,
	size_t size);

int
unallocate(
	void** array);

#endif
