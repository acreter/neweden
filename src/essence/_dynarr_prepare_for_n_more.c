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

#include <errno.h>

int
_dynarr_prepare_for_n_more(
		char** block,
		size_t n,
		size_t element_size
) {
	if (!block || !*block)
	{ return (errno = EINVAL, 0); }

	dynarr* array = _dynarr_self(*block);
	size_t new_size = (n + array->len) * element_size;
	if (new_size < array->len * element_size)
	{ return (errno = ERANGE, 0); }

	size_t new_n = n + array->len;
	return _dynarr_prepare_for_n(block, new_n, element_size);
}
