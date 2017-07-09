#pragma once

#ifndef _UTILITIES_JSON_JSON_H_
#define _UTILITIES_JSON_JSON_H_

#define MBTA(MEMBER) #MEMBER
#define _SET_KEY_VALUE set_key_value
#define _IS_DEFAULT_VALUE is_default_value
#define _SET(ROOT,M) if(!_IS_DEFAULT_VALUE(M))_SET_KEY_VALUE(ROOT,#M,M)

#define _GET_VALUE get_value
#define _GET(ROOT,M) _GET_VALUE(ROOT,#M,&M)

#include "support/basic_type.h"
#include "support/cstr_type.h"
#include "support/pointer_type.h"
#include "support/string_type.h"
#include "support/list_type.h"
#include "support/map_type.h"
#include "support/userdef_type.h"

/*Return c-style string,free it afterwards*/
template<typename _T>
inline const char *serialize(const _T &res){
	JSON_Value *doc = res.serialize();
	const char *s = json_serialize_to_string_pretty(doc);
	
	json_value_free(doc);

	return s;
}

template<typename _T>
inline void deserialize(_T *res, const char *s){
	JSON_Value *doc =json_parse_string(s);
	res->deserialize(doc);

	json_value_free(doc);
}


#endif//_UTILITIES_JSON_JSON_H_