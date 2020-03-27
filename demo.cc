#include <iostream>

#include "mysqlx/xdevapi.h"

using namespace mysqlx;
using namespace std;

int main() {
  Client cli("root:@localhost/mysql", ClientOption::POOL_MAX_SIZE, 7);
  Session sess = cli.getSession();
  Session sess2 = cli.getSession();

  Schema myDb = sess.getSchema("mysql");

  // Accessing an existing table
  Table myTable = myDb.getTable("user");

  // Find a row in the SQL Table
  RowResult myResult = myTable.select("host", "user").execute();

  // Print result
  Row row = myResult.fetchOne();
  cout << "    host: " << row[0] << endl;
  cout << "    user: " << row[1] << endl;

  cli.close(); // close all Sessions
}
