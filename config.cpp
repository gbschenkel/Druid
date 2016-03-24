/****************************************************************************
**
** Druid - Is a piece of program for read text file and store as json data.
** This is part of it's code.
** Copyright (C) 2016  Gustavo Brondani Schenkel
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include "config.h"

Config::Config(QObject *parent) : QObject(parent)
{
    QCoreApplication::setOrganizationName("Banrisul S.A.");
    QCoreApplication::setOrganizationDomain("banrisul.com.br");
    QCoreApplication::setApplicationName("Druid");

    settings = new QSettings();

    readSettings();
}

qint64 Config::getIndex()
{
    return index;
}

QString Config::getLastLine()
{
    return lastLine;
}

void Config::setIndex(qint64 newIndex)
{
    index = newIndex;
}

void Config::setLastLine(QString line)
{
    lastLine = line;
}

void Config::doWrite()
{
    writeSettings();
}

void Config::writeSettings()
{
    settings->setValue("File/index", index);
    settings->setValue("File/lastLine", lastLine);
}

void Config::readSettings()
{
    index = settings->value("file/index").toInt();
    lastLine = settings->value("File/lastLine").toString();
}