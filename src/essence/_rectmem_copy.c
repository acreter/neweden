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

int
_rectmem_copy(
		char** ref_from,
		char** ref_to,
		char* from_start,
		char* from_end,
		char* to,
		size_t element_size
) {
	return _rectmem_copy_range(ref_from, ref_to, from_start, to,
			_rectmem_xindex_of(ref_from, from_end, element_size) - _rectmem_xindex_of(ref_from, from_end, element_size) + 1,
			_rectmem_yindex_of(ref_from, from_end, element_size) - _rectmem_yindex_of(ref_from, from_end, element_size) + 1,
			element_size);
}
