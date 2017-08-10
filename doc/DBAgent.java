package lab.mars.crms.dao;

import com.google.common.collect.Sets;
import lab.mars.crms.model.json.common.ChildResourceRef;
import lab.mars.crms.model.json.common.Subscription;
import lab.mars.crms.model.json.resource.Resource;
import lab.mars.util.async.AsyncStream;

import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * User: Gxkl
 * Time: 2017.4.26
 * Copyright © Gxkl. All Rights Reserved.
 */
public interface DBAgent {//todo 使用batchStatment,在相同的node中使用
    String ChildrenTag = "ch";
    String SubscriptionTag = "subs";
    String DataTableContentTag = "con";
    String DataTableTableNameTag = "tn";
    String DataTableAttributeTag = "columns";
    String ResourceIDTag = "\"ri\"";
    //children use only
    String ChildCreationTimeTag = "\"ct\"";
    String ChildResourceIDTag = "\"v\"";
    String ResourceTypeTag = "\"ty\"";
    String ResourceNameTag = "\"rn\"";
    Set<String> UpdateChildTags = Sets.newHashSet(
            ResourceIDTag,
            ChildCreationTimeTag,
            ChildResourceIDTag,
            ResourceTypeTag,
            ResourceNameTag);
    HashSet<String> RetrieveChildTags = Sets.newHashSet(
            ChildResourceIDTag,
            ResourceTypeTag,
            ResourceNameTag);

    //sub use only
    String SubIDTag = "\"id\"";
    String SubDescTag = "\"desc\"";
    String SubCreateTimeTag = "\"ct\"";
    String SubEventTypeTag = "\"ety\"";
    String SubExpirationCounterTag = "\"exc\"";
    String SubNotificationURITag = "\"nu\"";
    String SubNotificationForwardURITag = "\"nfu\"";
    String SubGroupIDTag = "\"gi\"";
    String SubBatchNotifyTag = "\"bn\"";
    String SubLatestNotifyTag = "\"ln\"";
    String SubNotificationContentTypeTag = "\"nct\"";
    String SubCreatorTag = "\"cr\"";
    String SubSubscriberURITag = "\"su\"";

    Set<String> UpdateSubTags = Sets.newHashSet(
            ResourceIDTag,
            SubIDTag,
            SubDescTag,
            SubCreateTimeTag,
            SubEventTypeTag,
            SubExpirationCounterTag,
            SubNotificationURITag,
            SubNotificationForwardURITag,
            SubGroupIDTag,
            SubBatchNotifyTag,
            SubLatestNotifyTag,
            SubNotificationContentTypeTag,
            SubCreatorTag,
            SubSubscriberURITag);
    HashSet<String> RetrieveSubTags = Sets.newHashSet(
            SubIDTag,
            SubDescTag,
            SubCreateTimeTag,
            SubEventTypeTag,
            SubExpirationCounterTag,
            SubNotificationURITag,
            SubNotificationForwardURITag,
            SubGroupIDTag,
            SubBatchNotifyTag,
            SubLatestNotifyTag,
            SubNotificationContentTypeTag,
            SubCreatorTag,
            SubSubscriberURITag);

    /**
     * 清空所有DataTable资源对应的表，只应该在数据库初始化的时候被调用
     */
    void clearDataTableMappedTable();

    /**
     * 创建资源，不会创建子资源与订阅属性。
     * 创建子资源需要调用addChild()。
     * 创建订阅属性需要调用addSubscriptions()。
     *
     * @param clz
     * @param representation
     * @param <R>
     * @return
     */
    <R extends Resource> AsyncStream create(Class<R> clz, Map<String, Object> representation);

    /**
     * 创建Table
     *
     * @return
     */
    AsyncStream createTable(String tableName, Map<String, String> columns);

    /**
     * 查询类型为clz的所有资源,这里返回的资源中不包含children
     *
     * @param clz
     * @param <R>
     * @return
     */
    <R extends Resource> AsyncStream retrieve(Class<R> clz);

    /**
     * 查询指定resourceID资源
     *
     * @param clz
     * @param resourceID
     * @param mainAttr     是否需要主属性
     * @param childrenAttr 是否需要包含子资源属性
     * @param <R>
     * @return 对应的资源，若存在订阅属性，则包含了订阅属性
     */
    <R extends Resource> AsyncStream retrieve(Class<R> clz, String resourceID, boolean mainAttr, boolean childrenAttr, boolean subAttr);

    <R extends Resource> AsyncStream retrieveWithoutChildren(Class<R> clz, String resourceID, Set<String> keys);

    AsyncStream queryTable(String resourceID, int len, int offset);

    AsyncStream insertTable(String tableName, List<Map<String, Object>> content);

    /**
     * 更新对应的资源的主属性，不包含children和subs
     *
     * @param clz
     * @param resourceID
     * @param updated
     * @return
     */
    AsyncStream update(Class<? extends Resource> clz, String resourceID, Map<String, Object> updated);

    /**
     * 删除指定的资源，没有删除了对应的订阅，没有删除children
     *
     * @param clz
     * @param resourceID
     * @return
     */
    AsyncStream delete(Class<? extends Resource> clz, String resourceID);

    AsyncStream deleteTable(String tableName);

    AsyncStream removeChildren(String resourceID);

    AsyncStream removeChild(String resourceID, String childResourceID);

    AsyncStream addChild(String resourceID, ChildResourceRef childRef);

    AsyncStream getChildren(String resourceID, int limit);

    AsyncStream getChildren(String resourceID, int limit, boolean asc);

    /**
     * @param resourceID
     * @param subscriptions
     * @return
     */
    AsyncStream addSubscriptions(String resourceID, List<Subscription> subscriptions);

    /**
     * 获取resourceID和subID唯一确定的一条sub
     *
     * @param resourceID
     * @param subID
     * @return
     */
    AsyncStream getSubscription(String resourceID, String subID);

    /**
     * 获取resourceID下的所有的subs
     *
     * @param resourceID
     * @param limit
     * @return
     */
    AsyncStream getSubscriptions(String resourceID, int limit);

    AsyncStream updateSubscriptions(String resourceID, List<Subscription> subscriptions);

    AsyncStream removeSubscriptions(String resourceID, List<Subscription> subscriptions);
}
