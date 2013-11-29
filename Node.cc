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

#include "Node.h"
#include "MyHeader_m.h"

Define_Module(Node);

void Node::initialize()
{
    cMessage * reminder = new cMessage("Interval");
    TxEnergy.setName("NodePower");
    tx_interval = par("Tx_interval");
    energy=par("Energy");
    scheduleAt(simTime() + tx_interval,reminder);
    WATCH(tx_interval);
    WATCH(energy);
}

void Node::handleMessage(cMessage *msg)
{
    if(msg-> isSelfMessage())
    {
     //   cMessage *data=new cMessage("data");
       cPacket *IPdata = new cPacket("IP");
       MyHeader *myHeader = new MyHeader("myHeader");
       myHeader->setName("KIT");
       myHeader->setYear(2013);
       myHeader->setID(12345);
       cPacket *MACdata = new cPacket("MAC");
       myHeader->encapsulate(IPdata);
       MACdata->encapsulate(myHeader);

        int gateCount=this->gateSize("out");
        int destination=intrand(gateCount);//intrand() range: 0.. (gateCount-1)
        //send(data,"out",destination);
        send(MACdata, "out", destination);
        //double tx_interval=0.1;
        energy = energy - 0.8;      //Assume each packet needs 0.8mW to be transmitted.
        TxEnergy.record(energy);    //updating node energy records
        EV<<"I'm "<< this->getName()<<". A packet was sent "
                "and the remaining energy is "<<energy<<"mW."<<endl;


        if(energy>=0.8){
            scheduleAt(simTime()+tx_interval,msg);
        } else{
            DTime= simTime().dbl();
            EV<<this->getName()<<"is dead."<<endl;
        }
        //cMessage * reminder=new cMessage("Interval");
        //scheduleAt(simTime()+tx_interval,reminder);
    } else
    {
        //A message is received, we have nothing to do with it (delete it).
        delete(msg);
    }
}


void Node::finish()
{
    recordScalar("Node Life Time",DTime);

}
