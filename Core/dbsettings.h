#pragma once
#include <QSqlDatabase>

namespace Settings {
/*
 * Simple class that saves a QSqlDatabase settings to QSettings.
*/
class DBsettings{
public:
    DBsettings();
    static void save(QSqlDatabase db);
    static QSqlDatabase lastSaved(QString connectionName = QLatin1String(QSqlDatabase::defaultConnection));
    };
}

