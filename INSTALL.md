Compiling
=========

Make sure the Qt (>= 4.6) development libraries are installed:

* In Ubuntu/Debian: `sudo apt-get install libqt4-dev`
* In Fedora:        `yum install qt-devel`
* In Arch Linux:    `pacman -S qt`
* In Mac OS X with [Homebrew](http://mxcl.github.io/homebrew/): `brew install qt`


Release
-------

To do a release build, you can run qmake from the build directory and refer
it to KAuth.pro :

    $ cd build
    $ qmake ../KAuth.pro
    $ make

You can now simply run KAuth using bin/release/KAuth.


Debug
-----
To do a debug build, you can run qmake from the build directory and refer
it to KAuth.pro :

    $ cd build
    $ qmake ../KAuth.pro "CONFIG+=debug" "CONFIG+=declarative_debug" "CONFIG+=qml_debug"
    $ make

You can now simply run KAuth using bin/debug/KAuth.