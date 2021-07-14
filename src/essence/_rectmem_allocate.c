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
 * along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include <neweden/essence/rectangular_memory.h>
#include <neweden/essence/allocate.h>

#include <errno.h>

int
_rectmem_allocate(
		char** block,
		size_t x,
		size_t y,
		size_t element_size)
{
	if (!block || *block || !x || !y || !element_size )
	{ return (errno = EINVAL, 0); }

	struct rectmem* new = xallocate(sizeof (struct rectmem) + x * y * element_size);
	if (new) {
		*block = new->block;
		return 1;
	} else {
		return 0;
	}
}
