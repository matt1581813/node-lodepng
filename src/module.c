#include <assert.h>

#define NAPI_VERSION 8
#include <node_api.h>

#include "decode.h"
#include "encode.h"

static napi_value Init(napi_env env, napi_value exports) {
  napi_value result;
  assert(napi_create_object(env, &result) == napi_ok);

  napi_value decode_fn;
  assert(napi_create_function(env, "decode", NAPI_AUTO_LENGTH, decode, NULL, &decode_fn) == napi_ok);
  assert(napi_set_named_property(env, result, "decode", decode_fn) == napi_ok);

  napi_value encode_fn;
  assert(napi_create_function(env, "encode", NAPI_AUTO_LENGTH, encode, NULL, &encode_fn) == napi_ok);
  assert(napi_set_named_property(env, result, "encode", encode_fn) == napi_ok);


  napi_value encodeSync_fn;
  assert(napi_create_function(env, "encodeSync", NAPI_AUTO_LENGTH, encodeSync, NULL, &encodeSync_fn) == napi_ok);
  assert(napi_set_named_property(env, result, "encodeSync", encodeSync_fn) == napi_ok);

  napi_value decodeSync_fn;
  assert(napi_create_function(env, "decodeSync", NAPI_AUTO_LENGTH, decodeSync, NULL, &decodeSync_fn) == napi_ok);
  assert(napi_set_named_property(env, result, "decodeSync", decodeSync_fn) == napi_ok);

  return result;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
