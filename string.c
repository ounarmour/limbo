/*
 * string.c
 *
 *  Created on: Aug 8, 2017
 *      Author: ln
 */

#include "object.h"

// definitions - methods

struct string_object* string_new()
{
	struct string_object *tmp_object;
	struct string_data *tmp_data;

	if((tmp_object = malloc(sizeof *tmp_object))==NULL || (tmp_data = malloc(sizeof *tmp_data))==NULL)
		return tmp_object;

	tmp_object->parent = new();
	tmp_object->data = tmp_data;
	tmp_object->data->value = "string_data_value";

	return tmp_object;
}









