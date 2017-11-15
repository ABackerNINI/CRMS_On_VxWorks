#include <iostream>

#include "protocol/resource/crms_resource/CRMS_Attribute.h"
#include "protocol/json_support/crms_serialization.h"

int main() {
    crms::protocol::resource::resource::CRMS_Attribute attribute;
    {
        attribute.set_ty(111);
        attribute.set_ro(false);
    }

    char *s = njson_serialize(attribute);

    printf("%s\n", s);

    delete[]s;

    std::cout << "Hello, World!" << std::endl;

    return 0;
}