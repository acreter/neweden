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

#ifndef __DYNAMIC_MATRIX_H_INCLUDED
#define __DYNAMIC_MATRIX_H_INCLUDED 1

#include <neweden/essence/rectangular_memory.h>

void
_dynmatrix_init(
		char** block,
		size_t nCols,
		size_t nRows,
		size_t element_size
);

#define dynmatrix_init(block, nCols, nRows) \
	_dynmatrix_init( \
			(char**) (block), \
			(nCols), \
			(nRows), \
			sizeof **(block))

#define dynmatrix_free(block) \
	rectmem_free((char**) (block))

struct dimensions
_dynmatrix_dimensions(
		char** block,
		size_t element_size
);

#define dynmatrix_dimensions(block) \
	_dynmatrix_dimensions( \
			(char**) (block), \
			sizeof **(block))

void
_dynmatrix_ptr_from_coordinates(
		char** block,
		char** rval,
		size_t col,
		size_t row,
		size_t element_size
);

#define dynmatrix_ptr_from_coordinates(block, rval, col, row) \
		_dynmatrix_ptr_from_coordinates( \
				(char**) (block), \
				(char**) (rval), \
				(col), \
				(row), \
				sizeof **(block))

void
_dynmatrix_insert_rows(
		char** block,
		size_t index,
		size_t n
);

void
_dynmatrix_insert_cols(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
);

#define dynmatrix_insert_rows(block, index, n) \
	_dynmatrix_insert_rows( \
			(char**) (block), \
			(index), \
			(n))

#define dynmatrix_insert_cols(block, index, n) \
	_dynmatrix_insert_cols( \
			(char**) (block), \
			(index), \
			(n), \
			sizeof **(block))

void
_dynmatrix_remove_rows(
		char** block,
		size_t index,
		size_t n
);

void
_dynmatrix_remove_cols(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
);

#define dynmatrix_remove_rows(block, index, n) \
	_dynmatrix_remove_rows( \
			(char**) (block), \
			(index), \
			(n))

#define dynmatrix_remove_cols(block, index, n) \
	_dynmatrix_remove_cols( \
			(char**) (block), \
			(index), \
			(n), \
			sizeof **(block))

void
_dynmatrix_remove_entry(
		char** block,
		size_t col,
		size_t row,
		size_t element_size
);

void
_dynmatrix_remove_entryp(
		char** block,
		char* ptr,
		size_t element_size
);

#define dynmatrix_remove_entry(block, col, row) \
	_dynmatrix_remove_entry( \
			(char**) (block), \
			(col), \
			(row) \
			sizeof **(block))

#define dynmatrix_remove_entryp(block, ptr) \
	_dynmatrix_remove_entryp( \
			(char**) (block), \
			(char*) (ptr), \
			sizeof **(block))

#endif
