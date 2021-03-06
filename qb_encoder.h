/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Chung Leong <cleong@cal.berkeley.edu>                        |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef QB_ENCODER_H_
#define QB_ENCODER_H_

typedef struct qb_encoder_context			qb_encoder_context;

struct qb_encoder_context {
	qb_compiler_context *compiler_context;

	qb_op **ops;
	uint32_t op_count;
	int32_t position_independent;

	qb_storage *storage;

	uint32_t instruction_stream_length;
	uint32_t instruction_op_count;
	uint64_t instruction_crc64;
	int8_t *instructions;

	uintptr_t instruction_base_address;
	uintptr_t storage_base_address;

	void ***tsrm_ls;
};

qb_function * qb_encode_function(qb_encoder_context *cxt);
int8_t * qb_encode_instruction_stream(qb_encoder_context *cxt, int8_t *memory);
void qb_set_instruction_offsets(qb_encoder_context *cxt);

uint32_t qb_get_variable_length(qb_variable *qvar);
int8_t * qb_copy_variable(qb_variable *qvar, int8_t *memory);

void qb_initialize_encoder_context(qb_encoder_context *cxt, qb_compiler_context *compiler_cxt, int32_t position_independent TSRMLS_DC);
void qb_free_encoder_context(qb_encoder_context *cxt);

intptr_t qb_relocate_function(qb_function *qfunc, int32_t reentrance);
qb_function * qb_create_function_copy(qb_function *base, int32_t reentrance);
void qb_free_function(qb_function *qfunc);

#endif
