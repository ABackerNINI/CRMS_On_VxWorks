//
// Created by nini on 9/27/17.
//

#include <stdio.h>
#include "../../utility/nJson/DEF.h"
#include "../../protocol/resource/crms_primitive/CRMS_Req_Rsp.h"
#include "../../protocol/resource/crms_resource/CRMS_RootResource.h"
#include "../../protocol/resource/crms_resource/CRMS_Attribute.h"

int main() {
    printf("debug begin\n");

    crms::protocol::resource::primitive::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Attribute>Res;
    {
        Res.set_ty(0);
        crms::protocol::resource::resource::CRMS_Attribute attribute;
        {
            attribute.set_ty(1);
            attribute.set_nm("/attribute");
        }
        Res.set_val(&attribute);
    }

    const char *s = serialize(Res, NULL);
    {
        printf("%s\n", s);

        crms::protocol::resource::primitive::CRMS_Req_Rsp<crms::protocol::resource::resource::CRMS_Attribute>Res2;
        deserialize(&Res2, s);

        const char *s2 = serialize(Res2, NULL);

        printf("%s\n", s2);

        free((void *) s2);
    }
    free((void *) s);

    printf("debug end\n");

    return 0;
}