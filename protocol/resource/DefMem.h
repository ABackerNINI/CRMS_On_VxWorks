#pragma once

#ifndef _CRMS_RESOURCE_DEFINE_MEMBER_H_
#define _CRMS_RESOURCE_DEFINE_MEMBER_H_

#define _DEFINE_MEMBER(A, M, ...)                       \
A:                                                      \
    __VA_ARGS__ M;                                      \
public:                                                 \
    const __VA_ARGS__ &get_##M()const{return M;}        \
    __VA_ARGS__ &get_##M(){return this->M;}             \
    void set_##M(const __VA_ARGS__ &M){this->M=M;}

#define DEFINE_MEMBER(M, ...) _DEFINE_MEMBER(private,M,__VA_ARGS__)

#define _DEFINE_POINTER_MEMBER(A, M, ...)               \
A:                                                      \
    __VA_ARGS__ M;                                      \
public:                                                 \
    __VA_ARGS__ const get_##M()const{return M;}         \
    __VA_ARGS__ get_##M(){return this->M;}              \
    void set_##M(__VA_ARGS__ M){this->M=M;}

#define DEFINE_POINTER_MEMBER(M, ...) _DEFINE_POINTER_MEMBER(private,M,__VA_ARGS__)

#endif//_CRMS_RESOURCE_DEFINE_MEMBER_H_