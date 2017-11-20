cmake_minimum_required(VERSION 3.6)
project(CRMS_On_VxWOrks)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

##############################################################################################
##Utility
set(UTILITY_DATETIME
        utility/TimeUtil/DateTime.h
        utility/TimeUtil/Duration.h
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
        utility/nJson/type_traits/type_traits.h
        utility/nJson/support/basic_type.h
        utility/nJson/support/cstr_type.h
        utility/nJson/support/list_type.h
        utility/nJson/support/map_type.h
        utility/nJson/support/pointer_type.h
        utility/nJson/support/string_type.h
        utility/nJson/support/support_base.h
        utility/nJson/support/vector_type.h
        utility/nJson/DEF.h
        utility/nJson/nJson.h
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
        protocol/agent/resource_handler/subscription_handler.cpp
        protocol/agent/resource_handler/subscription_handler.h
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
###Protocol_json_support
set(PROTOCOL_JSON_SUPPORT
        protocol/json_support/crms_common/crms_batch_notify_support.h
        protocol/json_support/crms_common/crms_child_resource_ref_support.h
        protocol/json_support/crms_common/crms_filter_criteria_support.h
        protocol/json_support/crms_common/crms_subscription_support.h

        protocol/json_support/crms_enumeration/crms_enumeration_support.h

        protocol/json_support/crms_primitive_content_type_serialization.cpp
        protocol/json_support/crms_primitive_content_type_serialization.h
        protocol/json_support/crms_primitive/crms_primitive_content_type_support.h

        protocol/json_support/crms_resource/crms_attribute_support.h
        protocol/json_support/crms_resource/crms_command_support.h
        protocol/json_support/crms_resource/crms_data_table_support.h
        protocol/json_support/crms_resource/crms_group_support.h
        protocol/json_support/crms_resource/crms_has_children_support.h
        protocol/json_support/crms_resource/crms_node_support.h
        protocol/json_support/crms_resource/crms_remote_attribute_support.h
        protocol/json_support/crms_resource/crms_remote_command_support.h
        protocol/json_support/crms_resource/crms_remote_resource_object_support.h
        protocol/json_support/crms_resource/crms_resource_object_support.h
        protocol/json_support/crms_resource/crms_resource_support.h
        protocol/json_support/crms_resource/crms_root_resource_support.h

        protocol/json_support/crms_serialization.h
        protocol/json_support/datetime_support.h
        protocol/json_support/duration_support.h
        protocol/json_support/support_base.h
        )
###Protocol_resource
set(PROTOCOL_RESOURCE_CRMS_COMMON
        protocol/resource/crms_common/CRMS_AggregatedNotification.h
        protocol/resource/crms_common/CRMS_AggregatedResponse.h
        protocol/resource/crms_common/CRMS_BatchNotify.h
        protocol/resource/crms_common/CRMS_ChildResourceRef.h
        protocol/resource/crms_common/CRMS_FilterCriteria.h
        protocol/resource/crms_common/CRMS_Notification.h
        protocol/resource/crms_common/CRMS_RetrieveQuery.h
        protocol/resource/crms_common/CRMS_Subscription.h
        protocol/resource/crms_common/CRMS_SubscriptionRef.h
        )
set(PROTOCOL_RESOURCE_CRMS_ENUMERATION
        protocol/resource/crms_enumeration/CRMS_ConsistencyStrategy.h
        protocol/resource/crms_enumeration/CRMS_MemberType.h
        protocol/resource/crms_enumeration/CRMS_NodeExecutionState.h
        protocol/resource/crms_enumeration/CRMS_NotificationContentType.h
        protocol/resource/crms_enumeration/CRMS_Operation.h
        protocol/resource/crms_enumeration/CRMS_ResourceStatus.h
        protocol/resource/crms_enumeration/CRMS_ResourceType.h
        protocol/resource/crms_enumeration/CRMS_ResponseStatusCodeType.h
        protocol/resource/crms_enumeration/CRMS_ResultContent.h
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
        protocol/resource/crms_resource/CRMS_RemoteAttribute.h
        protocol/resource/crms_resource/CRMS_RemoteCommand.h
        protocol/resource/crms_resource/CRMS_RemoteResourceObject.h
        protocol/resource/crms_resource/CRMS_Resource.h
        protocol/resource/crms_resource/CRMS_ResourceObject.h
        protocol/resource/crms_resource/CRMS_RootResource.h
        )

set(PROTOCOL_RESOURCE
        protocol/resource/ResourceBase.h
        protocol/resource/DefMem.h
        protocol/json_support/crms_serialization.h
        protocol/resource/Type.h
        ${PROTOCOL_RESOURCE}
        ${PROTOCOL_RESOURCE_CRMS_COMMON}
        ${PROTOCOL_RESOURCE_CRMS_ENUMERATION}
        ${PROTOCOL_RESOURCE_CRMS_PRIMITIVE}
        ${PROTOCOL_RESOURCE_CRMS_RESOURCE}
        )
set(PROTOCOL
        protocol/keyword.h
        ${PROTOCOL_AGENT}
        ${PROTOCOL_JSON_SUPPORT}
        ${PROTOCOL_RESOURCE}
        protocol/common.h
        )

##############################################################################################

set(TEST_TOOL
        test/Test_Tool.cpp
        test/Test_Tool.h
        )

##############################################################################################

add_executable(CRMS_On_VxWOrks main.cpp
        ${UTILITY}
        )
target_link_libraries(CRMS_On_VxWOrks pthread)

##############################################################################################

add_executable(launcher launch/launcher.cpp
        ${PROTOCOL}
        ${UTILITY}
        )
target_link_libraries(launcher pthread)

##############################################################################################

add_executable(test_create test/test_crud/test_create.cpp
        ${PROTOCOL}
        ${UTILITY}
        ${TEST_TOOL}
        )
target_link_libraries(test_create pthread)

##############################################################################################

add_executable(test_retrieve test/test_crud/test_retrieve.cpp
        ${PROTOCOL}
        ${UTILITY}
        ${TEST_TOOL}
        )
target_link_libraries(test_retrieve pthread)

##############################################################################################

add_executable(test_update test/test_crud/test_update.cpp
        ${PROTOCOL}
        ${UTILITY}
        ${TEST_TOOL}
        )
target_link_libraries(test_update pthread)

##############################################################################################

add_executable(test_delete test/test_crud/test_delete.cpp
        ${PROTOCOL}
        ${UTILITY}
        ${TEST_TOOL}
        )
target_link_libraries(test_delete pthread)

##############################################################################################


