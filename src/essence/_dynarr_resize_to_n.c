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

#include <neweden/essence/macros.h>
#include <neweden/essence/dynamic_array.h>
#include <neweden/essence/allocate.h>

#include <errno.h>

int
_dynarr_resize_to_n(
		char** block,
		size_t n,
		size_t element_size
) {
	if (!block || !element_size)
		return (errno = EINVAL, 0);

	dynarr* array = NULL;

	if (!*block)
	{
		array = allocate(sizeof (dynarr) + n * element_size);
		if (!array)
		{ return 0; }
		else
		{
			array->len = 0;
			array->limit = n;
			*block = array->block;
			return 1;
		}
	}

	array = _dynarr_self(*block);
	if (reallocate((void**) &array, sizeof (*array) + n * element_size))
	{
		array->limit = n;
		array->len = min(array->len, n);
		*block = array->block;
		return 1;
	}

	return 0;
}
