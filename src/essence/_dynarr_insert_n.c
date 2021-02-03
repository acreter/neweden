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
_dynarr_insert_n(
		char** block,
		size_t index,
		void* elements,
		size_t n,
		size_t element_size
) {
	if (!block || _dynarr_len(*block) < index || !n)
	{ return (errno = EINVAL, 0); }

	if (!_dynarr_prepare_for_n_more(block, n, element_size))
	{ return 0; }

	memmove(*block + (index + n) * element_size,
			*block + index * element_size,
			(dynarr_len(*block) - index) * element_size);
	memcpy(*block + index * element_size,
			elements,
			n * element_size);

	_dynarr_self(*block)->len += n;
	return 1;
}
