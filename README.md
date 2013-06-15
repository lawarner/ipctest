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
- gtkmm (only for ipctest-gtk)
- qt (only for ipctest-qt)

One of the objectives of this project was to put as much common logic in the library
so that the UI code can be minimal.  Currently, 3 different UI's are provided as 
follows:
- ipctest-tui: This is a commandline utility that runs testcase provided on the 
commandline.  It outputs to standard output and is useful automating tests.
- ipctest-gtk: This program uses the gtkmm C++ user interface.
- ipctest-qt: This program uses Qt 5.0 user interface.

## Building
To build the ipctest library and tools, type 'make'.  You may need to edit some of 
the Makefile settings to, for example, skip building the gtkmm version.



