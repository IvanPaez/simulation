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

#include "Queue.h"

Define_Module(Queue);

void Queue::initialize()
{
    cQueue queue("my-queue");
    cMessage *msg;
    for(int i=0; i<10; i++){
        msg = new cMessage;
        queue.insert(msg);
     }
    //remove messages
    while(!queue.empty())
    {
        msg = (cMessage *) queue.pop();
        delete msg;
    }

    // Iterator
        for(cQueue::Iterator iter(queue); !iter.end(); iter++)
        {
            cMessage *msg= (cMessage *) iter();
            //...
        }

}

void Queue::handleMessage(cMessage *msg)
{

}

void Queue::finish()
{

}
