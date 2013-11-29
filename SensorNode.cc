//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SensorNode.h"

Define_Module(SensorNode);

void SensorNode::initialize()
{
    cMessage * reminder = new cMessage("Interval");
    TxEnergy.setName("NodePower");
    tx_interval = par("Tx_interval");
    energy=par("Energy");
    scheduleAt(simTime() + tx_interval,reminder);
    WATCH(tx_interval);
    WATCH(energy);
}

void SensorNode::handleMessage(cMessage *msg)
{
    if(msg-> isSelfMessage())
        {

            cMessage *data=new cMessage("Temp="+par("temperature"));
            int gateCount=this->gateSize("out");
            int destination=intrand(gateCount);//intrand() range: 0.. (gateCount-1)
            send(data,"out",destination);
            cMessage * reminder=new cMessage("Interval");
            scheduleAt(simTime()+tx_interval,reminder);
        } else
        {
            //A message is received, we forward it
            send(msg, "out");
        }
}

void SensorNode::finish()
{
    recordScalar("Node Life Time",DTime);
}
