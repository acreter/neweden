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

char*
rectmem_allocate(
		size_t x,
		size_t y
) {
	struct rectmem* new = xallocate(sizeof (struct rectmem) + x * y);
	new->dim.x = x;
	new->dim.y = y;
	return new->block;
}
