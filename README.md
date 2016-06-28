qirda
=====

	qirda - Send/Receive files to/from infrared-enabled devices
  GUI made with QT 5.5
  
 SYNOPSIS

	* qirda [--lang=fr]
	* qirdasend FILE1 [FILE2]...
	* qirdarcv [DIRECTORY]

 DESCRIPTION

	Qirda is aiming to be a comfortable data exchanger for infrared-enabled devices.
	It is written in C/C++ and uses the OpenObex libraries. 
	A French translation of the interface is provided.


 OPTIONS

	-h, --help  display available options

	-V, --version  display version information
        --lang=fr  bring up the UI with the french translation


 FEATURES

	* Accepted file types: jpg, png, wav, vcf
    	* File sending in single-thread mode        
	* File receiving in multi-thread mode
	* Receiving mode toggable with one click
    * System tray icon support with context menu
    * Detecting irda enabled devices nearby is NOT yet implemented.


 BUILDING QIRDA

 	The pre-built version has Openobex compiled-in statically.

	To build from scratch, make sure you have the development libraries of
        Openobex 2.0 and Qt 5.x installed.
  	In Ubuntu 16, install the packages libopenobex2 libopenobex2-dev irda-utils qtbase5-dev
  	
	Open src/qirda.pro with qt-creator or use the shell script src/build.bash.
	It will generate the binaries qirda, qirdasend, qirdarcv with debugging information.



 INSTALLING QIRDA

	Run as normal user, the shell script "src/install.bash". 
	It installs the stripped down version of qirda, qirdasend,
	qirdarcv in /usr/local/bin, after prompting for the root password.


 BUGS

	* Information related to files sent is displayed only after all
	transfers are completed. The GUI freezes during long transfers.

	* Received file information is not yet displayed by the GUI.


 AUTHOR: Makhtar Diouf

 COPYRIGHT

       Copyright (C) 2007-2016 Makhtar Diouf.
       The included irobex code is Copyright (C) Nick Protopapas.
       This is an open source software released under the GNU General Public
       License version 2. See the file COPYING for copying conditions. 

