#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
#include <string.h>
void main ()
{
	MYSQL *conn;
	int err;
	
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	char consulta [80];
	char username[80];
	conn = mysql_init(NULL);
	if (conn==NULL)
	{
		printf ("Error al crear la conexión: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	conn = mysql_real_connect (conn, "localhost","root", "mysql",
							   "juego",0, NULL, 0);
	if (conn==NULL)
	{
		printf ("Error al inicializar la conexión: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	
	err=mysql_query (conn, "SELECT * FROM jugador");
	if (err!=0)
	{
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL)
	{
			printf ("Username: %s, password: %s\n", row[0], row[1]);
			row = mysql_fetch_row (resultado);
	}
		printf ("Dame el username del jugador del que quieres saber la contraseña\n");
		scanf("%s", username);
		
		strcpy(consulta, "SELECT contraseña FROM jugador WHERE username='");
		strcat (consulta, username);
		strcat (consulta, "'");
		
		err=mysql_query (conn, consulta);
		if (err!=0)
		{
			printf ("Error al consultar datos de la base %u %s\n",
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
		resultado = mysql_store_result (conn);
		row = mysql_fetch_row (resultado);
		if (row == NULL)
			printf ("No se han obtenido datos en la consulta\n");
		else
			while (row !=NULL)
		{
				printf ("Password: %s\n", row[0]);
				row = mysql_fetch_row (resultado);
		}

		
	mysql_close (conn);
}
