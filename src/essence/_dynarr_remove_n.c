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

#include <neweden/essence/dynamic_array.h>

#include <string.h>
#include <errno.h>

int
_dynarr_remove_n(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
) {
	if (index + n < index)
	{ return (errno = ERANGE, 0); }

	if (!block || dynarr_len(*block) < index + n)
	{ return (errno = EINVAL, 0); }

	memcpy(*block + index * element_size,
			*block + (index + n) * element_size,
			n * element_size);

	_dynarr_self(*block)->len -= n;
	return 1;
}
