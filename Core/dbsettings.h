/*********************************************************************
 *MyBank
 *Copyright (C) 2020 By Zibusiso N Mangoye
 *Contact : znmangoye@gmail.com
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.
************************************************************************/

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

