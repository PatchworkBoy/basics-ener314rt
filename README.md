# basics-ener314rt
The basics for the [Energenie ENER314-RT (aka Two Way Pi-Mote)](https://energenie4u.co.uk/catalogue/product/ENER314-RT) - turn [ENER002 dumb sockets](https://energenie4u.co.uk/catalogue/product/ENER002-4) on and off.

Inspect the contents of the [HopeRF_TRX(ENER002) folder](https://github.com/PatchworkBoy/basics-ener314rt/tree/master/HopeRF_TRX(ENER002)). Each file has [lines](https://github.com/PatchworkBoy/basics-ener314rt/blob/master/HopeRF_TRX(ENER002)/app_main.c#L30) [commented](https://github.com/PatchworkBoy/basics-ener314rt/blob/master/HopeRF_TRX(ENER002)/dev_HRF.c#L155)... amend as necessary.

Make a copy of the [Energenie-issued](https://energenie4u.co.uk/catalogue/download_software/ENER314-RT%20programs.zip) HopeRF_TRX(ENER002) folder (which in turn is inside the ENER002 folder), overwrite app_main.c, dev_HRF.c & Makefile with the ones from this Git repo, and make away!

If you've already managed to pair your sockets, you can try the 4 files in the binaries folder. Download them into a folder, then navigate into that folder and run...

```
sudo chmod +x s*
```

...to make them executable, and test with...

```
./s1on && ./s1off && ./s2on && ./s2off
```

If that works copy or symlink them into /usr/local/bin to use them from anywhere on the system.

## Sample Use Case
I call the binaries from [Domoticz](http://www.domoticz.com), via a virtual switch which simply uses script://home/pi/s1on for the On command and script://home/pi/s1off for the off command. Domoticz is hooked up to iOS HomeKit apps via [eDomoticz and Homebridge](https://www.domoticz.com/forum/viewtopic.php?f=36&t=10272), which means I can then use "Hey Siri, turn the {name of domoticz virtual switch} on/off" to voice-control the energenie sockets.
