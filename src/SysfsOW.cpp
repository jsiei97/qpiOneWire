/**
 * @file SysfsOW.cpp
 * @author Johan Simonsson
 * @brief A linux sysfs onewire wrapper
 */

/*
 * Copyright (C) 2015 Johan Simonsson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QDebug>
#include <QStringList>
#include <QString>
#include <QDir>

#include "SysfsOW.h"

QStringList SysfsOW::list()
{
    QDir d("/sys/bus/w1/devices/");

    QStringList filters;
    //Right now, only return a list with DS18B20, ignore the rest
    filters.append("28-*");
    d.setNameFilters(filters);
    return d.entryList();
}


/*
   /sys/bus/w1/devices/28-000000b51bac/w1_slave

   37 01 4b 46 7f ff 09 10 26 : crc=26 YES
   37 01 4b 46 7f ff 09 10 26 t=19437
   */
bool SysfsOW::getValue(QString addr, double *value)
{
    QString filename("/sys/bus/w1/devices/");
    filename.append(addr);
    filename.append("/w1_slave");
    //qDebug() << "[" << __PRETTY_FUNCTION__ << __LINE__ << "]" << filename;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QRegExp rxYes("(YES$)");
    QRegExp rxValue("t=([0-9]{1,6}$)");

    QTextStream in(&file);
    int linecnt = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();

        switch ( linecnt )
        {
            case 0 :
                {
                    //First line, her we find YES or NO
                    //If there is no YES, then abort!
                    if(-1 == rxYes.indexIn(line, 0))
                    {
                        qDebug() << "[" << __PRETTY_FUNCTION__ << __LINE__ << "]" << "Error no YES" << line;
                        return false;
                    }
                }
                break;
            case 1 :
                {
                    // Second line, here we should find the value
                    // t=19437
                    // divide 1000 and we get 19.437 degC
                    if(-1 != rxValue.indexIn(line, 0))
                    {
                        QString t = rxValue.cap(1);
                        bool ok;
                        *value = t.toDouble(&ok);
                        if(ok)
                        {
                            *value /= 1000;
                            return true;
                        }
                        qDebug() << "[" << __PRETTY_FUNCTION__ << __LINE__ << "]" << "Error" << line << t;
                    }
                    else
                    {
                        qDebug() << "[" << __PRETTY_FUNCTION__ << __LINE__ << "]" << "Error no value" << line;
                        return false;
                    }
                }
                break;
            default :
                break;
        }

        //qDebug() << "[" << __PRETTY_FUNCTION__ << __LINE__ << "]" << linecnt << line;
        linecnt++;
    }

    return false;
}
