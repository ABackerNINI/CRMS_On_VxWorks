
#include "../../resource/crms_resource/CRMS_Rsp.h"

int main(){
	printf("debug begin\n");

	CRMS_Rsp Res;
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

		CRMS_Rsp Res2;
		deserialize(&Res2,s);

		const char *s2 = serialize(Res2,NULL);

		printf("%s\n", s2);

		free((void *)s2);
	}
	free((void *)s);

	printf("debug end\n");

	return 0;
}