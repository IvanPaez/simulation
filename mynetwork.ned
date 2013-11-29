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

package myproject;

network Mynetwork
{
    @display("bgb=526,445;bgi=background/terrain");
    submodules:
        node1: Node {
            @display("p=39,50");
        }
        node: Node {
            @display("p=167,28");
        }
        node2: Node {
            @display("p=128,149");
        }
        node3: Node {
            @display("p=252,191");
        }
        node4: Node {
            @display("p=330,98");
        }
        dataCollector: DataCollector {
            @display("i=,gold;p=410,309");
        }
        sensorNode: SensorNode {
            @display("p=185,289");
        }
        sensorNode1: SensorNode {
            @display("p=78,244");
        }
        dataCollector1: DataCollector {
            @display("p=396,49");
        }
    connections:
        node1.out++ --> node2.in++;
        node2.out++ --> node1.in++;
        node.out++ --> node3.in++;
        node3.out++ --> node4.in++;
        node4.out++ --> node3.in++;
        node.out++ --> node2.in++;
        node2.out++ --> node.in++;
        node3.out++ --> node.in++;
        node1.out++ --> node.in++;
        node.out++ --> node1.in++;
        node4.out++ --> dataCollector.in++;
        node3.out++ --> dataCollector.in++;
        sensorNode1.out++ --> sensorNode.in++;
        sensorNode.out++ --> dataCollector.in++;
        sensorNode.out++ --> sensorNode1.in++;
}
