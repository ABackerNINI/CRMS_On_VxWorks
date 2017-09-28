#include "DBUtility.h"

DBUtility &DBUtility::getInstance() {
    static DBUtility dbUtility;

    return dbUtility;
}

string DBUtility::Add(const string &table, const map<string, string> &values) {
    string strSql = "";
    strSql = "INSERT INTO " + table + " (";

    for (map<string, string>::const_iterator it = values.begin(); it != values.end(); it++) {
        if (it != values.begin()) {
            strSql += ",";
        }

        strSql += "\'" + it->first + "\'";
    }

    strSql += ") ";

    strSql += " VALUES (";

    for (map<string, string>::const_iterator it = values.begin(); it != values.end(); it++) {
        if (it != values.begin()) {
            strSql += ",";
        }

        strSql += it->second;
    }

    strSql += ");";
    auto rc = sqlite3_exec(db, strSql.c_str(), NULL, NULL, &azErrMsg);

    if (rc != SQLITE_OK) {
        sqlite3_free(azErrMsg);
        throw ErrCode::DB_ADD_ERROR;
    }
    return strSql;
}

vector<string> DBUtility::Query(const string &table, const string &column, const string &where) {
    string strSql;
    vector<string> vector;
    char **dbResult;
    int nROw, nColumn;
    int index = 0;
    int i, j;

    strSql = "SELECT " + column + " FROM ";
    strSql += table + " WHERE " + where + ";";

    char *sql = new char[strSql.size() + 1]; //mark
    strcpy(sql, strSql.c_str()); //mark

//    rc = sqlite3_get_table(db, strSql.c_str(), &dbResult, &nROw, &nColumn, &azErrMsg); //mark
    auto rc = sqlite3_get_table(db, sql, &dbResult, &nROw, &nColumn, &azErrMsg);
    delete[] sql;
    if (rc == SQLITE_OK) {
        index = nColumn;
        for (i = 0; i < nROw; i++) {
            for (j = 0; j < nColumn; j++) {
                vector.push_back(dbResult[index]);
                index++;
            }
        }
    }

    if (vector.empty()) {
        sqlite3_free(azErrMsg);
        throw ErrCode::DB_QUERY_ERROR;
    }

    return vector;
}

int DBUtility::Update(const string &table, const map<string, string> &column, const string &where) {
    string strSql = "";
    for (map<string, string>::const_iterator it = column.begin(); it != column.end(); it++) {
        strSql = " UPDATE " + table + " SET \'";
        strSql += it->first + "\' = \'" + it->second;
        strSql += "\' WHERE " + where;
        strSql += ";";

        auto rc = sqlite3_exec(db, strSql.c_str(), NULL, NULL, &azErrMsg);

        if (rc != SQLITE_OK) {
            sqlite3_free(azErrMsg);
            throw ErrCode::DB_UPDATE_ERROR;
        }
    }

    return 0;
}

string DBUtility::Delete(const string &table, const string &where) {
    string strSql;
    strSql = "DELETE FROM " + table;
    strSql += " WHERE " + where;
    strSql += ";";

    auto rc = sqlite3_exec(db, strSql.c_str(), NULL, NULL, &azErrMsg);

    if (rc != SQLITE_OK) {
        //  cout << strSql << azErrMsg << endl;
        sqlite3_free(azErrMsg);
        throw ErrCode::DB_DELETE_ERROR;
//        fprintf(stderr, "%s:%s\n", strSql.c_str(), azErrMsg);
//        sqlite3_free(azErrMsg);
    }

    return strSql;
}

DBUtility::DBUtility() {
//    auto rc = sqlite3_open(DATA_BASE_PATH + "/SDK.db", &db);

    auto rc = sqlite3_open(std::string(Config::getResourcePath() + "/SDK.db").c_str(), &db);

    if (rc != SQLITE_OK) {
        throw ErrCode::DB_OPEN_ERROR;
    }
}
