ipctest
=======

Interactive testing tool based on sockstr IPC

There is also a test harness in the ipctest subdirectory.  This allows capturing test 
scenarios and saving these for later playback.

Note: Initially ipctest was part of the sockstr library, but has been split out recently.
The purposes of the two projects is really very different and I plan on porting sockstr
to many other platforms -- most likely starting with Android.  For now, ipctest is being
developed on Linux only.

How to Build on Linux
=====================
## Dependencies

You will need GNU make, g++ and pthreads to build this package.  Optionally you can 
generate documentation if you have doxygen.

Additional dependencies:
- sockstr
- expat
- gtkmm

## Building
To build the ipctest library and tools, type 'make'.  Additional prerequites 
are required to build ipctest, such as:


