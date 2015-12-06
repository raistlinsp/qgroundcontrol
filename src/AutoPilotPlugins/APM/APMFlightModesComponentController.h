/*=====================================================================
 
 QGroundControl Open Source Ground Control Station
 
 (c) 2009, 2015 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 
 This file is part of the QGROUNDCONTROL project
 
 QGROUNDCONTROL is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 QGROUNDCONTROL is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.
 
 ======================================================================*/

#ifndef APMFlightModesComponentController_H
#define APMFlightModesComponentController_H

#include <QObject>
#include <QQuickItem>
#include <QList>
#include <QStringList>

#include "UASInterface.h"
#include "AutoPilotPlugin.h"
#include "FactPanelController.h"
#include "Vehicle.h"

/// MVC Controller for FlightModesComponent.qml.
class APMFlightModesComponentController : public FactPanelController
{
    Q_OBJECT
    
public:
    APMFlightModesComponentController(void);
    
    Q_PROPERTY(int      channelCount        MEMBER _channelCount        CONSTANT)
    Q_PROPERTY(bool     fixedWing           MEMBER _fixedWing           CONSTANT)
    Q_PROPERTY(QString  reservedChannels    MEMBER _reservedChannels    CONSTANT)
    
private slots:
    void _rcChannelsChanged(int channelCount, int pwmValues[Vehicle::cMaxRcChannels]);
    
private:
    void _init(void);
    void _validateConfiguration(void);
    
    bool _fixedWing;
    
    int _rcValues[Vehicle::cMaxRcChannels];
    
    bool    _validConfiguration;
    QString _configurationErrors;
    int     _channelCount;
    QString _reservedChannels;
};

#endif