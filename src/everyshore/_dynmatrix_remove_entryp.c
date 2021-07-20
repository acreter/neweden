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
_dynmatrix_remove_entryp(
		char** block,
		char* ptr,
		size_t element_size
) {
	_dynmatrix_remove_rows(block, rectmem_yindex_of(*block, ptr), 1);
	_dynmatrix_remove_cols(block, rectmem_yindex_of(*block, ptr) / element_size, 1, element_size);
	return;
}
