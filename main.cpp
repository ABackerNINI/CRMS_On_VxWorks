#include <stdio.h>
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include "protocol/resource/crms_resource/CRMS_RootResource.h"

int main(){
	printf("debug begin\n");

	CRMS_RootResource Res;
	{
		Res.set_ri("root_res");
		Res.set_pa("");
		Res.set_rn("root_res");
		Res.set_ty(1);
	}

	const char *s = serialize(Res,NULL);
	{
		printf("%s\n", s);

		CRMS_RootResource Res2;
		deserialize(&Res2,s);

		const char *s2 = serialize(Res2,NULL);

		printf("%s\n", s2);

		free((void *)s2);
	}
	free((void *)s);

	printf("debug end\n");

	return 0;
}