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

int
_matrix_init(
		char** block,
		size_t nCols,
		size_t nRows,
		size_t element_size
) {
	if (!block || !element_size || !nRows || !nCols || *block)
	{ return (errno = EINVAL, 0); }

	dynmatrix* matrix = NULL;
	matrix = allocate(sizeof (dynmatrix) + nCols * nRows * element_size);
	if (!matrix)
	{ return 0; }
	else
	{
		matrix->nCols = nCols;
		matrix->nRows = nRows;
		*block = matrix->block;
		return 1;
	}

}
