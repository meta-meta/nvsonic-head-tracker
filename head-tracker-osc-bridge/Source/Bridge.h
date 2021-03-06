/*
	nvsonic Head Tracker OSC Bridge
	https://github.com/trsonic/nvsonic-head-tracker

	Copyright (c) 2017-2019 Tomasz Rudzki, Jacek Majer
	Email: tom@nvsonic.io
	Website: https://nvsonic.io/
	Twitter: @tomasz_rudzki

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "rs232.h"

class Bridge : private Timer

{
public:
    Bridge();    
    ~Bridge();
        
    int BaudR;
    int PortN;
    
    int port_number, port_index, port_state;
    
    char readBuffer[128];

	float qW, qX, qY, qZ;
	float qlW, qlX, qlY, qlZ;
	float qbW = 1, qbX = 0, qbY = 0, qbZ = 0;

	float RollOUT, PitchOUT, YawOUT;
    float RollOSC, PitchOSC, YawOSC;
    
	String RollOutput = "0";
	String PitchOutput = "0";
	String YawOutput = "0";
    
    bool connected = false;
    bool AXmuted = false;
    bool AYmuted = false;
    bool AZmuted = false;
    
    StringPairArray portlist;
    StringArray quaternions;
    
    StringArray GetPortInfo();
    bool Connect();
    void Disconnect();
	void resetOrientation();

	void timerCallback() override;

	OSCSender sender;
       
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Bridge)
};        
