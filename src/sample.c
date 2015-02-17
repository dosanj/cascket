#include<stdio.h>
#include <stdlib.h>
#include "cassandra.h"
#include "cfuhash.h"
int main(void)
{
	char *str;
	char *temp;

	if(cassandra_connect(9042,"127.0.0.1","cassandra","cassandra"))
		printf("Connected to Database\n");
	else 
		printf("Error in connecting the database\n");

	/* Create and send packet */
	str = "select * from demodb.users ;";
	//gets(str);
	result_set *rs;
	rs = cassandra_execute(str);
	while (has_next(rs))
	{
		int *n;
		temp = (char *)get_val(rs, "user");
		printf("got value as %s\n", temp);
		n = (int *)get_val(rs, "number");
		if(n != NULL)
			printf("surname value as %d \n", *n );
		else 
			printf("surname value as null\n");
	}
	result_set_destroy(rs);
	return 0;
}
