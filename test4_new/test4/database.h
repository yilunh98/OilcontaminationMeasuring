#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QWidget>
#include <string>
class Database
{
public:
	QSqlDatabase db2;
	void database_process(QString sta);

};
#endif //DATABASE_H