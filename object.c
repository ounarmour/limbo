/*
 * limbo.c
 *
 *  Created on: Aug 7, 2017
 *      Author: ln
 */

#include "object.h"

// definitions - methods

struct object* new()
{
	struct object *tmp_object;
	struct data *tmp_data;

	if((tmp_object = malloc(sizeof *tmp_object))==NULL || (tmp_data = malloc(sizeof *tmp_data))==NULL)
		return tmp_object;

	tmp_object->hashcode = cnt++;
	tmp_object->data = tmp_data;
	tmp_object->data->value = "object_data_value";
	tmp_object->to_string = to_string;
	tmp_object->get_hashcode = get_hashcode;

	return tmp_object;
}

char *to_string(struct object *obj)
{
	return obj->data->value;
}

int get_hashcode(struct object *obj)
{
	return obj->hashcode;
}


// testing entry point

int main() {

	struct object *obj0 = new();
	struct object *obj1 = new();
	struct object *obj2 = new();
	struct object *obj3 = new();
	struct object *obj4 = new();

	printf("obj0 hascode: %d\n", obj0->hashcode);
	printf("obj1 hascode: %d\n", obj1->hashcode);
	printf("obj2 hascode: %d\n", obj2->hashcode);
	printf("obj3 hascode: %d\n", obj3->hashcode);
	printf("obj4 hascode: %d\n", obj4->hashcode);

	struct string_object *str0 = string_new();
	str0->data->value = "This is a string!";
	printf("str0->to_string(): %s\n", str0->parent->to_string(str0->parent));

	return 0;
}














