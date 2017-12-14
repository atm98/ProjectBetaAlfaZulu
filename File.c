Packet Tracer 6.1 tutorial - IP telephony basic configuration
3.87096774193551 1 1 1 1  Rating 3.87 (62 Votes)
 Last Updated: Monday, 23 February 2015 08:19
Tutorial description
This tutorial is designed to help you to configure the new voice over ip (voip) features available in Packet Tracer 6.0. It will show you the steps required to :

Configure Call Manager ExpressTM on a 2811 router,
Use the various telephony devices
Setup dial peers
Connect  CiscoTM IP phones as well as analogue phone on the network.

 
Network diagram
VOIP tutorial network diagram
Note : Connect only IP Phone 1 at the beginning of the lab. IP Phone 2 must be disconnected.

 

Tasks 1 : Configure interface FastEthernet 0/0 and DHCP server on RouterA (2811 router)
#Configure the FA 0/0 interface#

RouterA>enable

RouterA#configure terminal

RouterA(config)#interface FastEthernet0/0

RouterA(config-if)#ip address 192.168.10.1 255.255.255.0

RouterA(config-if)#no shutdown

 

The DHCP server is needed to provide an IP adress and the TFTP server location for each IP phone connected to the network.

RouterA(config)#ip dhcp pool VOICE #Create DHCP pool named VOICE

RouterA(dhcp-config)#network 192.168.10.0 255.255.255.0 #DHCP network network 192.168.10 with /24 mask#

RouterA(dhcp-config)#default-router 192.168.10.1 #The default router IP address#

RouterA(dhcp-config)#option 150 ip 192.168.10.1 #Mandatory for voip configuration.

 

After the configuration, wait a moment  and check that ‘IP Phone 1’ has received an IP address by placing your cursor over the phone until a configuration summary appears.

 

Tasks 2 : Configure the Call Manager Express telephony service on RouterA
You must now configure the Call Manager Express telephony service on RouterA  to enable voip on your network.

RouterA(config)#telephony-service #Configuring the router for telephony services#

RouterA(config-telephony)#max-dn 5 #Define the maximum number of directory numbers#

RouterA(config-telephony)#max-ephones 5 #Define the maximum number of phones#

RouterA(config-telephony)#ip source-address 192.168.10.1 port 2000 #IP Address source#

RouterA(config-telephony)#auto assign 4 to 6 #Automatically assigning ext numbers to buttons#

RouterA(config-telephony)#auto assign 1 to 5 #Automatically assigning ext numbers to buttons#

 

Task 4 : Configure a voice vlan on SwitchA
Apply the following configuration on SwitchA interfaces. This configuration will separate voice and data traffic in different vlans on SwitchA. data packets will be carried on the access vlan.

SwitchA(config)#interface range fa0/1 – 5 #Configure interface range#

SwitchA(config-if-range)#switchport mode access

SwitchA(config-if-range)#switchport voice vlan 1 #Define the VLAN on which voice packets will be handled#

 

Task 5 : Configure the phone directory for IP Phone 1
Although ‘IP Phone 1’ is already connected to SwitchA, it needs additionnal configuration before beeing able to communicate. You need to configure RouterA CME to assign a phone number to this IP phone.

RouterA(config)#ephone-dn 1 #Defining the first directory entry#

RouterA(config-ephone-dn)#number 54001 #Assign the phone number to this entry#

 

Task 5 : Verify the configuration
Ensure that the IP Phone receives an IP Address and a the phone number 54001 from RouterA  (this can take a short while).

IP Phone number 1 confgured with IP address and phone number
IP Phone 1 configured - Front view

 
Task 6 : Configure the phone directory for IP Phone 2
Connect IP Phone 2 to SwitchA and power the phone ON using the power adapter (Physical tab).

RouterA(config)#ephone-dn 2 #Defining the first directory entry#

RouterA(config-ephone-dn)#number 54002 #Assign the phone number to this entry#

 

Task 7 : Verify the configuration
Ensure that the IP Phone 2 receives an IP Address and a the phone number 54002 from RouterA  (this can take a short while). Same procedure as task n°5.

Dial 54001 and check if IP phone 1 correctly receives the call.