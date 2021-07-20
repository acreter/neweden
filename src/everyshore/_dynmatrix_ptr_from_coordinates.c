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

#include <neweden/everyshore/dynamic_matrix.h>

void
_dynmatrix_ptr_from_coordinates(
		char** block,
		char** rval,
		size_t col,
		size_t row,
		size_t element_size
) {
	*rval = rectmem_ptr_from_coordinates(*block, col * element_size, row);
	return;
}
