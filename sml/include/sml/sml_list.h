

#ifndef _SML_LIST_H
#define	_SML_LIST_H

#include "sml_time.h"
#include "sml_octet_string.h"
#include "sml_number.h"
#include "sml_status.h"
#include "sml_value.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct sml_list_entry {
	octet_string *obj_name;
	sml_status *status; // optional
	sml_time *val_time; // optional
	sml_unit unit; // optional
	i8 scaler; // optional
	sml_value *value;
	sml_signature *value_signature; // optional
	
	// list specific
	struct sml_list_entry *next;
} sml_list;

sml_list *sml_list_init();

void sml_list_write(sml_list *list, sml_buffer *buf);

sml_list *sml_list_parse(sml_buffer *buf);

void sml_list_free(sml_list *list);

#ifdef __cplusplus
}
#endif


#endif
