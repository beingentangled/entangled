// Copyright 2018 IOTA Foundation

#ifndef CCLIENT_SERIALIZATION_SERIALIZER_H
#define CCLIENT_SERIALIZATION_SERIALIZER_H

#include <stdlib.h>
#include "request/requests.h"
#include "response/responses.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct serializer_base serializer_t;

typedef struct {
  // find_transactions_request
  void (*find_transactions_serialize_request)(
      const serializer_t* const, const find_transactions_req_t* const obj,
      char* out);

  void (*find_transactions_deserialize_response)(const serializer_t* const,
                                                 const char* const obj,
                                                 find_transactions_res_t* out);

  size_t (*find_transactions_serialize_request_get_size)(
      const serializer_t* const,
      const find_transactions_req_t* const toSerialize);

  size_t (*find_transactions_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

  // get_balances_response
  void (*get_balances_serialize_request)(const serializer_t* const,
                                         const get_balances_req_t* const obj,
                                         char* out);

  void (*get_balances_deserialize_response)(const serializer_t* const,
                                            const char* const obj,
                                            get_balances_res_t* out);

  size_t (*get_balances_serialize_request_get_size_)(
      const serializer_t* const, const get_balances_req_t* const toSerialize);

  size_t (*get_balances_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

  // get_inclusion_state_response
  void (*get_inclusion_state_serialize_request)(
      const serializer_t* const, const get_inclusion_state_req_t* const obj,
      char* out);

  void (*get_inclusion_state_deserialize_response)(
      const serializer_t* const, const char* const obj,
      get_inclusion_state_res_t* out);

  size_t (*get_inclusion_state_serialize_request_get_size)(
      const serializer_t* const,
      const get_inclusion_state_req_t* const toSerialize);

  size_t (*get_inclusion_state_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

  // get_neighbors_request

  void (*get_neighbors_deserialize_response)(const serializer_t* const,
                                             const char* const obj,
                                             get_neighbors_res_t* out);

  size_t (*get_neighbors_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

  // get_node_info_request

  size_t (*get_node_info_serialize_request_get_size)(
      const serializer_t* const s);
  void (*get_node_info_serialize_request)(const serializer_t* const, char* out);

  void (*get_node_info_deserialize_response)(const serializer_t* const,
                                             const char* const obj,
                                             get_node_info_res_t* out);

  size_t (*get_node_info_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

  // get_tips_request

  void (*get_tips_deserialize_response)(const serializer_t* const,
                                        const char* const obj,
                                        get_tips_res_t* out);

  size_t (*get_tips_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

  // get_transactions_to_approve_response
  void (*get_transactions_to_approve_serialize_request)(
      const serializer_t* const, int depth, char* out);

  void (*get_transactions_to_approve_deserialize_response)(
      const serializer_t* const, const char* const obj,
      get_transactions_to_approve_res_t* out);

  size_t (*get_transactions_to_approve_serialize_request_get_size)(
      const serializer_t* const);

  size_t (*get_transactions_to_approve_deserialize_response_get_size)(
      const serializer_t* const, const char* const toDeserialize);

} serializer_vtable;

typedef struct serializer_base {
  serializer_vtable vtable;

} serializer_base;

#ifdef __cplusplus
}
#endif

#endif  // CCLIENT_SERIALIZATION_SERIALIZER_H
