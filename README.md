
# ABOUT

**DSBAutostart**
is a Qt program that allows you to add commands to be executed at session start.

# INSTALLATION

## Dependencies

**DSBAutostart**
depends on
*devel/qt5-buildtools*, *devel/qt5-core*, *devel/qt5-linguisttools*,
*devel/qt5-qmake*, *x11-toolkits/qt5-gui*,
and
*x11-toolkits/qt5-widgets*

## Getting the source code

	# git clone https://github.com/mrclksr/DSBAutostart.git
	# git clone https://github.com/mrclksr/dsbcfg.git

## Building and installation

	# cd DSBAutostart && qmake && make
	# make install

# SETUP

Add the following command to your ~/.xinitrc, or to your window manager's
startup script (e.g. ~/.config/openbox/autostart.sh):

	sh ~/.config/DSB/autostart.sh&
