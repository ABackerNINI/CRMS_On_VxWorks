use crms;

CREATE TABLE IF NOT EXISTS crms_children(
    "ri"     text,
    "ct"   timestamp,
    "rn"    text,
   "v" text,
    "ty"        int,
    PRIMARY KEY ("ri","ct","v")
)WITH CLUSTERING ORDER BY ("ct" DESC, "v" ASC)
AND caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE INDEX ON crms_children("v");

CREATE TABLE IF NOT EXISTS crms_subscription(
    "ri" text,
    "desc" text,
    "ct" timestamp,
    "id" text,
    "ety" blob,
    "exc" int,
    "nu" blob,
    "nfu" blob,
    "gi" text,
    "bn" blob,
    "ln" boolean,
    "nct" blob,
    "cr" text,
    "su" text,
    PRIMARY KEY ("ri","id")
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_rootResource(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text
 --root
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_resourceObject(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text
 --resouceObject
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_remote_resourceObject(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --resouceObject
 --remote
 "rm" int,
 "rri" text,
 "alive" boolean,
 "proxy" boolean
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_attribute(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --attribute
 "nm" text,
 "data" blob,
 "ro" boolean
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_remote_attribute(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --attribute
 "name" text,
 "value" blob,
 "readOnly" boolean,
 --remote
 "rm" int,
  "rri" text,
  "proxy" boolean
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_command(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --command
 "desc" text,
 "con" text
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_remote_command(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --command
 "desc" text,
 "con" text,
 --remote
  "rm" int,
  "rri" text,
  "proxy" boolean
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_node(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --node
 "desc" text,
 "params" blob,
 "nno" boolean,
 "result" blob,
 --maychange
 "st" blob
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_datatable(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --table
 "tn" text,
 "desc" text,
 "cnt" int,
 "col" blob
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};

CREATE TABLE IF NOT EXISTS crms_group(
--resource
"ri"  text PRIMARY KEY,
 "ty"  int,
 "pa"  text,
 "ct"  timestamp,
 "lt"    timestamp,
 "rn" text,
 "onto" text,
 --table
 "mt" text,
 "cnm" int,
 "mnm" int,
 "mid" blob,
 "mtv" boolean,
 "csy" blob,
 "gn" text,
 "cr" text
)with caching = {'keys':'ALL', 'rows_per_partition':'10'};