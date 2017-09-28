#pragma once

#ifndef _CRMS_PROTOCOL_RESOURCE_POOL_H_
#define _CRMS_PROTOCOL_RESOURCE_POOL_H_

#include <map>
#include <string>

class resource_pool {
public:
    static resource_pool &get_instance(){
        if (instance == NULL) {
            instance = new resource_pool();
        }
        return *instance;
    }

    int register_resource(const std::string &Id,void *_Resource);

    int unregister_resource(const std::string &_Id);

    void *get_resource_from_id(const std::string &_Id);

private:

    std::map<std::string, void *> _Resource_Pool;

    static resource_pool *instance;

    resource_pool(){}

    class gc{
    public:
        ~gc(){
            if(resource_pool::instance){
                delete resource_pool::instance;
            }
        }
    };
    static gc _gc;
};

#endif//_CRMS_PROTOCOL_RESOURCE_POOL_H_