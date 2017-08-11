#pragma once

#ifndef _DATABASE_UTILITY_BASE_ON_SQLITE3_H_
#define _DATABASE_UTILITY_BASE_ON_SQLITE3_H_

#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include "sqlite3/sqlite3.h"

class DBUtility {
public:
    static DBUtility &getInstance();

    string Add(const string &table, const map<string, string> &values);

    vector<string> Query(const string &table, const string &column, const string &where);

    int Update(const string &table, const map<string, string> &column, const string &where);

    string Delete(const string &table, const string &where);
private:
    DBUtility();

    sqlite3 *db;
    char *azErrMsg;
};

#endif//_DATABASE_UTILITY_BASE_ON_SQLITE3_H_
