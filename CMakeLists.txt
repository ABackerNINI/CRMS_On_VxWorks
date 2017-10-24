cmake_minimum_required(VERSION 3.6)
project(CRMS_On_VxWOrks)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

##############################################################################################
##Utility
set(UTILITY_DATETIME
        utility/DateTime/DateTime.h
        utility/DateTime/Duration.h
)
set(UTILITY_DBUTIL

        )
set(UTILITY_HTTPUTIL
        utility/HttpUtil/Client.cpp
        utility/HttpUtil/Client.h
        utility/HttpUtil/HttpUtil.h
        utility/HttpUtil/mongoose.c
        utility/HttpUtil/mongoose.h
        utility/HttpUtil/Server.cpp
        utility/HttpUtil/Server.h
        )
set(UTILITY_NETWORK

        )
set(UTILITY_NJSON
        utility/nJson/parson/parson.c
        utility/nJson/parson/parson.h
        utility/nJson/support/basic_type.h
        utility/nJson/support/cstr_type.h
        utility/nJson/support/list_type.h
        utility/nJson/support/map_type.h
        utility/nJson/support/pointer_type.h
        utility/nJson/support/string_to.h
        utility/nJson/support/string_type.h
        utility/nJson/support/to_string.h
        utility/nJson/support/userdef_type.h
        utility/nJson/DEF.h
        utility/nJson/nJson.h
        utility/nJson/parson.h
        )
set(UTILITY_RESOURCE_POOL
        utility/resource_pool/resource_pool.cpp
        utility/resource_pool/resource_pool.h
        )
set(UTILITY
        ${UTILITY_DATETIME}
        ${UTILITY_DBUTIL}
        ${UTILITY_HTTPUTIL}
        ${UTILITY_NETWORK}
        ${UTILITY_NJSON}
        ${UTILITY_RESOURCE_POOL}
        )

##############################################################################################
##Protocol
###Protocol_agent
set(PROTOCOL_AGENT_REQUEST_HANDLER
        protocol/agent/request_handler/request_handler.cpp
        protocol/agent/request_handler/request_handler.h
        )
set(PROTOCOL_AGENT_RESOURCE_HANDLER
        protocol/agent/resource_handler/attribute_handler.cpp
        protocol/agent/resource_handler/attribute_handler.h
        protocol/agent/resource_handler/command_handler.cpp
        protocol/agent/resource_handler/command_handler.h
        protocol/agent/resource_handler/data_table_handler.cpp
        protocol/agent/resource_handler/data_table_handler.h
        protocol/agent/resource_handler/group_handler.cpp
        protocol/agent/resource_handler/group_handler.h
        protocol/agent/resource_handler/resource_handler.cpp
        protocol/agent/resource_handler/resource_handler.h
        protocol/agent/resource_handler/node_handler.cpp
        protocol/agent/resource_handler/node_handler.h
        protocol/agent/resource_handler/remote_attribute_handler.cpp
        protocol/agent/resource_handler/remote_attribute_handler.h
        protocol/agent/resource_handler/remote_command_handler.cpp
        protocol/agent/resource_handler/remote_command_handler.h
        protocol/agent/resource_handler/remote_resource_object_handler.cpp
        protocol/agent/resource_handler/remote_resource_object_handler.h
        protocol/agent/resource_handler/resource_object_handler.cpp
        protocol/agent/resource_handler/resource_object_handler.h
        protocol/agent/resource_handler/root_resource_handler.cpp
        protocol/agent/resource_handler/root_resource_handler.h
        )
set(PROTOCOL_AGENT_RESOURCE_OPERATOR
        protocol/agent/resource_operator/resource_operator.cpp
        protocol/agent/resource_operator/resource_operator.h
        )
set(PROTOCOL_AGENT
        ${PROTOCOL_AGENT_REQUEST_HANDLER}
        ${PROTOCOL_AGENT_RESOURCE_HANDLER}
        ${PROTOCOL_AGENT_RESOURCE_OPERATOR}
        )

###Protocol_resource
set(PROTOCOL_RESOURCE_CRMS_COMMON
        protocol/resource/crms_common/CRMS_AggregatedNotification.h
        protocol/resource/crms_common/CRMS_AggregatedResponse.h
        protocol/resource/crms_common/CRMS_BatchNotify.h
        protocol/resource/crms_common/CRMS_ChildResourceRef.h
        protocol/resource/crms_common/CRMS_FilterCriteria.h
        protocol/resource/crms_common/CRMS_Notification.h
        protocol/resource/crms_common/CRMS_Pagination.h
        protocol/resource/crms_common/CRMS_PartialRetrieve.h
        protocol/resource/crms_common/CRMS_Subscription.h
        protocol/resource/crms_common/CRMS_SubscriptionRef.h
        protocol/resource/crms_common/CRMS_SubscriptionRetrieve.h
        )
set(PROTOCOL_RESOURCE_CRMS_ENUMERATION
        protocol/resource/crms_enumeration/CRMS_ConsistencyStrategy.h
        protocol/resource/crms_enumeration/CRMS_MemberType.h
        protocol/resource/crms_enumeration/CRMS_NodeExecutionState.h
        protocol/resource/crms_enumeration/CRMS_NotificationContentType.h
        protocol/resource/crms_enumeration/CRMS_Operation.h
        protocol/resource/crms_enumeration/CRMS_PartialRetrieveType.h
        protocol/resource/crms_enumeration/CRMS_ResourceStatus.h
        protocol/resource/crms_enumeration/CRMS_ResourceType.h
        protocol/resource/crms_enumeration/CRMS_ResponseStatusCodeType.h
        protocol/resource/crms_enumeration/CRMS_ResultContent.h
        protocol/resource/crms_enumeration/CRMS_RetrieveQueryType.h
        protocol/resource/crms_enumeration/CRMS_SubscriptionEventType.h
        protocol/resource/crms_enumeration/CRMS_SubscriptionOperation.h
        protocol/resource/crms_enumeration/EnumerationBase.h
        )
set(PROTOCOL_RESOURCE_CRMS_PRIMITIVE
        protocol/resource/crms_primitive/CRMS_PrimitiveContentType.h
        protocol/resource/crms_primitive/CRMS_Req.h
        protocol/resource/crms_primitive/CRMS_Rsp.h
        )
set(PROTOCOL_RESOURCE_CRMS_RESOURCE
        protocol/resource/crms_resource/CRMS_Attribute.h
        protocol/resource/crms_resource/CRMS_Command.h
        protocol/resource/crms_resource/CRMS_DataTable.h
        protocol/resource/crms_resource/CRMS_Group.h
        protocol/resource/crms_resource/CRMS_HasChildren.h
        protocol/resource/crms_resource/CRMS_Node.h
        protocol/resource/crms_resource/CRMS_RemoteAttribut.h
        protocol/resource/crms_resource/CRMS_RemoteCommand.h
        protocol/resource/crms_resource/CRMS_RemoteResourceObject.h
        protocol/resource/crms_resource/CRMS_Resource.h
        protocol/resource/crms_resource/CRMS_ResourceObject.h
        protocol/resource/crms_resource/CRMS_RootResource.h
        )
set(PROTOCOL_RESOURCE_SUPPORT
        protocol/resource/support/DateSupport.h
        protocol/resource/support/DurationSupport.h
        protocol/resource/support/EnumerationSupport.h
        )
set(PROTOCOL_RESOURCE
        protocol/resource/DEF.h
        protocol/resource/DefMem.h
        protocol/resource/Serialization.h
        protocol/resource/Type.h
        ${PROTOCOL_RESOURCE}
        ${PROTOCOL_RESOURCE_CRMS_COMMON}
        ${PROTOCOL_RESOURCE_CRMS_ENUMERATION}
        ${PROTOCOL_RESOURCE_CRMS_PRIMITIVE}
        ${PROTOCOL_RESOURCE_CRMS_RESOURCE}
        ${PROTOCOL_RESOURCE_SUPPORT}
        )
set(PROTOCOL
        protocol/keyword.h
        ${PROTOCOL_AGENT}
        ${PROTOCOL_RESOURCE}
        protocol/common.h)

##############################################################################################

add_executable(CRMS_On_VxWOrks main.cpp)

##############################################################################################

add_executable(launcher launch/launcher.cpp
        ${PROTOCOL}
        ${UTILITY}
        )
target_link_libraries(launcher pthread)

##############################################################################################

add_executable(test_req_rsp test/test_serialization/test_req_rsp.cpp
        ${PROTOCOL_RESOURCE}
        ${UTILITY_NJSON}
        )

##############################################################################################

add_executable(test_root_resource test/test_crud/test_root_resource.cpp
        ${PROTOCOL}
        ${UTILITY}
        )
target_link_libraries(test_root_resource pthread)

##############################################################################################

add_executable(testt test/test_crud/test.cpp
        ${PROTOCOL}
        ${UTILITY}
        )
target_link_libraries(testt pthread)

##############################################################################################