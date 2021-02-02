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
_dynarr_prepare_for_n(
		char** block,
		size_t n,
		size_t element_size
) {
	if (!block)
	{ return (errno = EINVAL, 0); }

	if (!*block)
	{ return _dynarr_resize_to_n(block, n, element_size); }
	else
	{
		dynarr* self = _dynarr_self(*block);
		return self->limit < n ? _dynarr_resize_to_n(block, n, element_size) : 1;
	}
}
