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

char*
_rectmem_xstep(
		char** block,
		char* current,
		unsigned int by,
		size_t element_size)
{
	if (!block || !(*block) || !current || !by || !element_size)
	{ return (errno = EINVAL, 0); }

	struct dimensions* dim = rectmem_dimensions(*block);
	size_t current_x_index = (current - *block) % dim->x;
	return current + (((current_x_index + by) % dim->x) - current_x_index) * element_size;
}
