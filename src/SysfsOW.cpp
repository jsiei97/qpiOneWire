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
