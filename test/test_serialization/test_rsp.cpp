
#include "../../protocol/resource/crms_resource/CRMS_Rsp.h"

int main(){
	printf("debug begin\n");

	CRMS_Rsp Res;
	{
		Res.set_to("rsp_to");
		Res.set_fr("rsp_fr");
		Res.set_rqi("rsp_rqi");
		Res.set_ot(DateTime::now());
		Res.set_rsc(CRMS_ResponseStatusCodeType::Success);
	}

	printf("%s\n", DateTime::now().to_string().c_str());

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