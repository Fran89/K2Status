#K2Status

A K2/ETNA Status Monitoring Program for Earthworm

This K2 Status program is compiled for 64bit Intel, but can be compiled easily 
in any 32bit computer. It has been written in QT and C++ in order to have full 
compatibility for other platforms. The 32Bit statically link version availible
in the master branch for a previous version (I will update soon). A fully naitive 
64bit (dinamically linked) version is provided and run in the newest Ubuntu distros. 

###Features:

* Shows updated status for every station (it automatically configures stations)
* Shows you a lot of statistics from stations provided directly from the station.
* Table with all the data and colors that indicate the different status  gives you 'at a glance' overview of the network
* Potential for a lot of features to be added (see below)

###Instructions:

In EW:

1. Add the K2_K2STATUS_PACKET Message type to earthworm.d
2. Setup all the K2EW instances to transmit K2Info Packets. (Uncomment the last line) 
3. Setup a ringtocoax to transmit this particular packet to the computer which will run K2Status.

In K2Status:

1. In the Connections Menu:
2. Put the IP of the interface you are to recieve the UDP packets containing the K2 Info.
3. That's it.

Import/Export Capability: Is fully EXPERIMENTAL, use at your own risk.

###To Do:

1. Work out ~~various~~ bugs (Most are squashed).
2. ~~Test using multiple stations~~ (DONE).
3. Improve Import/Export Communications.
4. Add the ability to graph data.
5. Add the ability to request information from the Rock Family of instruments.

===

If anyone is interested in this proyect or would like to help, contact me!

#####Credits:
* The Puerto Rico Strong Motion Program for their help and support.
* The people over at Instrumental Software Technologies, Inc. (ISTI) @ http://www.isti.com/
* Everyone who has ever worked with in the development of earthworm @ http://earthwormcentral.org
* The QT Community @ http://qt-project.org/


Thanks,
Fran89.

