/**
 * @file main.cpp
 * @author Johan Simonsson
 * @brief A test application for SysfsOW.
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

#include "SysfsOW.h"

int main()
{
    QStringList l = SysfsOW::list();

    for (int i = 0; i < l.size(); ++i)
    {
        qDebug() << l.at(i);

        double value = 85.0;
        if(SysfsOW::getValue(l.at(i), &value))
        {
            qDebug() << "ok" << value;
        }
        else
        {
            qDebug() << "fail" << value;
        }
    }

    /*
	double value = 85.0;
	if(SysfsOW::getValue("28-000000b51bac", &value))
	{
		qDebug() << "ok" << value;
	}
	else
	{
		qDebug() << "fail" << value;
	}
    */
    return 0;
}
