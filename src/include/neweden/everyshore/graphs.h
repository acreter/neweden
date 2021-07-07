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

#ifndef __GRAPHS_H_INCLUDED
#define __GRAPHS_H_INCLUDED 1

#include <stddef.h>

typedef int* graph;
typedef graph dyngraph;

int
graph_add_nodes(dyngraph g, int number_of_nodes);

int
graph_edit_edges(graph g, size_t number_of_edges, size_t from_node, int* edges);

#endif
