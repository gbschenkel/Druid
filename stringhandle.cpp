/****************************************************************************
**
** <one line to give the program's name and a brief idea of what it does.>
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

#include "stringhandle.h"

#include <QtCore/QRegularExpression>
#include <QtCore/QRegularExpressionMatch>
#include <QtCore/QDebug>

StringHandle::StringHandle(QObject *parent) : QObject(parent)
{

}

void StringHandle::checkString(QString str)
{
    validate(str);
}

void StringHandle::validate(QString str){

    QRegularExpressionMatch match = stringCode.match(str);
    if (match.hasMatch()) {
        code = checkCode(match.captured("code"));
        emit codeChanged(code);
        switch (code){
        case PWETRT10:
            match = entry.match(str);
            if (match.hasMatch())
                emit dataValidated(match);
            break;
        case PWEUJI10:
            match = started.match(str);
            if (match.hasMatch())
                emit dataValidated(match);
            break;
        case PWETRT20:
            match = stepProcessed.match(str);
            if (match.hasMatch())
                emit dataValidated(match);
            break;
        case PWETRT40:
            match = checkIfOkay.match(str);
            if (match.hasMatch())
                emit dataValidated(match);
            break;
        case PWETRT30:
            match = ended.match(str);
            if (match.hasMatch())
                emit dataValidated(match);
            break;
        case NOT_DEFINED_CODE:
            break;
        default:
//            qDebug() << "StringHandle: " + match.captured(1) + " code not defined, yet!";
            break;
        }
    } else {
        qDebug() << "String doesn't have match:\n";
        qDebug() << str + "\n";
    }
}
