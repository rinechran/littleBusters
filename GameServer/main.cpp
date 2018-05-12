

#include <my_global.h>
#include <mysql.h>

#pragma comment(lib, "libmysql")
#pragma comment(lib, "mysqlclient")
#include <iostream>


int main()
{
	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "kudwafter.moe", "rinechran", "dutajrdj!!1",
		NULL, 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	if (mysql_query(con, "CREATE DATABASE testdb"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	mysql_close(con);
	exit(0);
}