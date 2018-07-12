# papie
mini game console based on raspberry pi zero and waveshare display hat

## Hardware

The hardware uses mini-computer Raspberry pi zero (with the w option for wireless) :
https://www.raspberrypi.org/products/raspberry-pi-zero/


On top of it, there is a hat from waveshare that provides a screen and some inputs, while keeping the form factor of the raspberry pi zero :
https://www.waveshare.com/wiki/1.44inch_LCD_HAT

## Raspbian configuration
Linux ditribution is based on raspbian. Extra configuration to set it as access point has been made by following this post :
https://www.raspberrypi.org/forums/viewtopic.php?t=196263#p1227552

Note that in order to work correctly, the service dhcpcd has to be disabled :
```
sudo systemctl disable dhcpcd
```

## Wifi configuration
The system runs an access point under the name "papie". It is accessible at the address 10.0.0.1 and should allocate an IP in the 10.0.0.* range upon connection. 

To configure the external wifi connection, simply modify ssid and passphrase in the /etc/network/interfaces file, and ifdown / ifup the wlan0 interface.

