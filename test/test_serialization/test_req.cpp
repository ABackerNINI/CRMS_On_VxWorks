
#include "../../protocol/resource/crms_primitive/CRMS_Req.h"

int main(){
	printf("debug begin\n");

	CRMS_Req Res;
	{
		Res.set_op(CRMS_Operation::Create);
		Res.set_to("req_to");
		Res.set_fr("req_fr");
		Res.set_rqi("req_rqi");
		Res.set_ty(0);
		Res.set_rn("req_rn");

		// PrimitiveContentType pc;
		// {
		// 	pc.set_value();
		// 	pc.set_type("int");
		// }
		// Res.set_pc(pc);
	}

	const char *s = serialize(Res,NULL);
	{
		printf("%s\n", s);

		CRMS_Req Res2;
		deserialize(&Res2,s);

		const char *s2 = serialize(Res2,NULL);

		printf("%s\n", s2);

		free((void *)s2);
	}
	free((void *)s);

	printf("debug end\n");

	return 0;
}