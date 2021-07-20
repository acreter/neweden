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
_matrix_insert_cols(
		char** block,
		size_t index,
		size_t n,
		size_t element_size
) {
	struct dimensions* old_dim = rectmem_dimensions(*block);
	char* new = rectmem_allocate(old_dim->x + n * element_size, old_dim->y);

	rectmem_copy_range(*block, new, *block, new, index * element_size, old_dim->y);
	rectmem_copy_range(*block, new, rectmem_xstep(*block, *block, index * element_size), rectmem_xstep(new, new, (index + n) * element_size), old_dim->x - index * element_size, old_dim->y);
	
	rectmem_free(block);
	*block = new;
	return;
}
