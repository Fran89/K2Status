K2Status
========

A K2/ETNA Status Monitoring Program for Earthworm

This K2 Status program is compiled for 32bit Intel, but can run neatly in 64Bit. 
It has been written in QT and C++ in order for to full compatibility for other 
platforms. The binaries provided here are statically linket to the latest QT 
sources (5.3). A fully naitive 64bit (dinamically linked) version is now availible 
in the dev64 branch and can run in a modern Ubuntu distro.

===

Instructions:
In EW:

1. Add the K2_INFO_PACKET Message type to earthworm.d
2. Setup all the K2EW instances to transmit K2Info Packets. (Uncomment the last line) 
3. Setup a ringtocoax to transmit this particular packet to the computer which will run K2Status.

In K2Status:

1. In the Connections Menu:
2. Put the IP of the interface you are to recieve the UDP packets containing the K2 Info.
3. That's it.

Import/Export Capability: Is fully EXPERIMENTAL, use at your own risk.

===

To Do:

1. Work out various bugs. (Workaround for gnome, toolbar now opens the connection dialog, debug, etc...)
2. Test using multiple stations.
3. Improve Import/Export Communications.
4. Add the ability to graph data.
5. Add the ability to request information from the Rock Family of instruments.

===

If anyone is interested in this proyect or would like to help, contact me!

Credits:
* The people over at Instrumental Software Technologies, Inc. (ISTI) @ http://www.isti.com/
* Everyone who has ever worked with in the development of earthworm @ http://earthwormcentral.org
* The QT Community @ http://qt-project.org/


Thanks,
Fran89.

