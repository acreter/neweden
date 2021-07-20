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
_dynmatrix_remove_entry(
		char** block,
		size_t col,
		size_t row,
		size_t element_size
) {
	_dynmatrix_remove_rows(block, row, 1);
	_dynmatrix_remove_cols(block, col, 1, element_size);
	return;
}
