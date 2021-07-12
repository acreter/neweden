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

#include <neweden/essence/allocate.h>
#include <neweden/everyshore/matrix.h>

#include <errno.h>
#include <string.h>

int
_matrix_insert_rows(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
) {
	if (!block || !*block || !n || !element_size)
	{ return (errno = EINVAL, 0); }

	dynmatrix* matrix = _matrix_self(*block);
	if (matrix->nRows < index)
	{ return (errno = EINVAL, 0); }

	if (reallocate((void**) &matrix, sizeof (*matrix) + (n + matrix->nRows) * matrix->nCols * element_size))
	{
		*block = matrix->block;
		memmove(
				*block + matrix->nCols * (index + n) * element_size,
				*block + matrix->nCols * index * element_size,
				(matrix->nRows - index) * matrix->nCols * element_size);
		memset(
				*block + matrix->nCols * index * element_size,
				0,
				n * matrix->nCols * element_size);
		matrix->nRows += n;
		return 1;
	}

	return 0;
}
