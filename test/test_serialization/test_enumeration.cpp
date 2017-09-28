
#include "../../protocol/resource/Serialization.h"
#include "../../protocol/resource/DefMem.h"

struct Foo{
public:
	bool serialize(JSON_Value *_doc_,const char *_key_ = NULL) const {
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			if(_key_==NULL){
				SET(cs);
				SET(mt);
				SET(nes);
				SET(o);
				SET(rsct);
				SET(rc);
				SET(so);
			} else {
				SET_IF_KEY(cs)
				SET_IF_KEY(mt)
				SET_IF_KEY(nes)
				SET_IF_KEY(o)
				SET_IF_KEY(rsct)
				SET_IF_KEY(rc)
				SET_IF_KEY(so)
				{
					return false;
				}
			}
		}

		return true;
	}
	void deserialize(JSON_Value *_doc_){
		JSON_Object *_root_obj_ = json_value_get_object(_doc_);
		{
			GET(cs);
			GET(mt);
			GET(nes);
			GET(o);
			GET(rsct);
			GET(rc);
			GET(so);
		}
	}

	DEFINE_MEMBER(cs,CRMS_ConsistencyStrategy)
	DEFINE_MEMBER(mt,CRMS_MemberType)
	DEFINE_MEMBER(nes,CRMS_NodeExecutionState)
	DEFINE_MEMBER(o,CRMS_Operation)
	DEFINE_MEMBER(rsct,CRMS_ResponseStatusCodeType)
	DEFINE_MEMBER(rc,CRMS_ResultContent)
	DEFINE_MEMBER(so,CRMS_SubscriptionOperation)

// 	CRMS_ConsistencyStrategy &get_cs(){return cs;}
// 	CRMS_MemberType &get_mt(){return mt;}
// 	CRMS_NodeExecutionState &get_nes(){return nes;}
// 	CRMS_Operation &get_o(){return o;}
// 	CRMS_ResponseStatusCodeType &get_rsct(){return rsct;}
// 	CRMS_ResultContent &get_rc(){return rc;}
// 	CRMS_SubscriptionOperation &get_so(){return so;}
// 	void set_cs(CRMS_ConsistencyStrategy cs){this->cs=cs;}
// 	void set_mt(CRMS_MemberType mt){this->mt=mt;}
// 	void set_nes(CRMS_NodeExecutionState nes){this->nes=nes;}
// 	void set_o(CRMS_Operation o){this->o=o;}
// 	void set_rsct(CRMS_ResponseStatusCodeType rsct){this->rsct=rsct;}
// 	void set_rc(CRMS_ResultContent rc){this->rc=rc;}
// 	void set_so(CRMS_SubscriptionOperation so){this->so=so;}

// private:
// 	CRMS_ConsistencyStrategy		cs;
// 	CRMS_MemberType					mt;
// 	CRMS_NodeExecutionState			nes;
// 	CRMS_Operation 					o;
// 	CRMS_ResponseStatusCodeType 	rsct;
// 	CRMS_ResultContent 				rc;
// 	CRMS_SubscriptionOperation 		so;
};

int main(){
	printf("debug begin\n");

	Foo Res;
	{
		Res.set_cs(1);
		Res.set_mt(1);
		Res.set_nes(1);
		Res.set_o(1);
		Res.set_rsct(1);
		Res.set_rc(1);
		Res.set_so(1);

		Res.set_cs(CRMS_ConsistencyStrategy::ABANDON_GROUP);
	}

	const char *s = serialize(Res,NULL);
	{
		printf("%s\n", s);

		Foo Res2;
		deserialize(&Res2,s);

		const char *s2 = serialize(Res2,NULL);

		printf("%s\n", s2);

		free((void *)s2);
	}
	free((void *)s);

	printf("debug end\n");

	return 0;
}