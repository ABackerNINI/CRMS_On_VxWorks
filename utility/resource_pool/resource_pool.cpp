#include "resource_pool.h"

resource_pool *resource_pool::instance = NULL;

int resource_pool::register_resource(const std::string &_Id, void *_Resource) {
    if (_Resource_Pool.find(_Id) == _Resource_Pool.end()) {
        _Resource_Pool[_Id] = _Resource;

        return 0;
    } else {
        return -1;//_Id already exists
    }
}

int resource_pool::unregister_resource(const std::string &_Id) {
    std::map<std::string, void *>::iterator _Iter = _Resource_Pool.find(_Id);
    if (_Iter != _Resource_Pool.end()) {
        _Resource_Pool.erase(_Iter);

        return 0;
    } else {
        return -1;//resource doesn't exist
    }
}

void *resource_pool::get_resource_from_id(const std::string &_Id) {
    std::map<std::string, void *>::iterator _Iter = _Resource_Pool.find(_Id);
    if (_Iter != _Resource_Pool.end()) {
        return _Iter->second;
    } else {
        return NULL;
    }
}