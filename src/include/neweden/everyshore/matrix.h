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

#ifndef __MATRIX_H_INCLUDED
#define __MATRIX_H_INCLUDED 1

#include <stddef.h>

typedef struct
{
	size_t nCols, nRows;
	char block[];
} dynmatrix;

dynmatrix*
_matrix_self(
		char* block
);

int
_matrix_init(
		char** block,
		size_t nCols,
		size_t nRows,
		size_t element_size
);

int
_matrix_free(
		char** block
);

int
_matrix_insert_rows(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
);

int /* not yet implemented */
_matrix_insert_cols(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
);

int /* not yet implemented */
_matrix_remove_rows(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
);

int /* not yet implemented */
_matrix_remove_entry(
		char** block,
		size_t col,
		size_t row,
		size_t element_size
);

int /* not yet implemented */
_matrix_remove_entryp(
		char** block,
		void* ptr,
		size_t element_size
);

#endif
