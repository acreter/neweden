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
dynmatrix_insert_rows(
		char** block,
		size_t index,
		size_t n
) {
	struct dimensions* old_dim = rectmem_dimensions(*block);
	char* new = rectmem_allocate(old_dim->x, old_dim->y + n);

	rectmem_copy_range(*block, new, *block, new, old_dim->x, index);
	rectmem_copy_range(*block, new, rectmem_ystep(*block, *block, index), rectmem_ystep(new, new, index + n), old_dim->x, old_dim->y - index);
	
	rectmem_free(block);
	*block = new;
	return;
}
