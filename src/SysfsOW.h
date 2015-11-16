/**
 * @file SysfsOW.h
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

#ifndef  __SYSFSOW_H
#define  __SYSFSOW_H

#include <QDebug>
#include <QStringList>
#include <QString>

class SysfsOW
{
    private:
    public:
        static QStringList list();
        static bool getValue(QString addr, double *value);
};

#endif  // __SYSFSOW_H
