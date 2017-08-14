to compile Criteria you need to install the correct xerces libraries so we have to compile xerces for windows.

We need:

1. install MinGW and MSYS
2. install Win-Builds
3. compile xerces

#MinGW/MSYS

Go to [MinGW Sourceforge site](http://sourceforge.net/projects/mingw/) and download MinGW. 
<br>Download and run mingw-get-setup.exe to get MinGW package installer.

From MinGW installer mark **msys-base** and development tools (**gcc**, **make**, etc..) for Installation.

![mingw-32 packages](/img/mingw32.png "mingw-32 packages")

#Win-Builds
Once MinGW and MSYS have been installed go to [win-builds site](http://win-builds.org) and download win-build.
<br>Run the package manager *win-builds-1.5.exe*.

>You need to run this executable twice in order to get both 32bit and x64 build capability for MinGW. Make sure Cygwin or MSYS is selected in either case.

![win-build](/img/win-build.png "win-build")

The directory of the existing MSYS installation should be **C:\MinGW\msys\1.0**. 

All the necessary win-build packages will be installed to:
```
C:\MinGW\msys\1.0\opt\windows_32 
or 
C:\MinGW\msys\1.0\opt\windows_64
```

to check installation run the following command:
```
C:\MinGW\msys\1.0\opt\windows_64\bin\yypkg-1.5.0.exe
or
C:\MinGW\msys\1.0\opt\windows_32\bin\yypkg-1.5.0.exe
```

##Switch Between 32 and 64 Bit Build Architectures
Every time the msys.bat file is run the build architecture needs to be set. 
To select the architecture desired type the following:

>For Windows 32 built
```
source /opt/windows_32/bin/win-builds-switch 
```

>For Windows 64 built
```
source /opt/windows_64/bin/win-builds-switch
```

To avoid running the above code everytime msys.bat is run, the default build architecture can be set by adding it to the user profile demonstrated below. Follow windows 32 build or 64 build instructions according to your systems architecture.

>For Windows 32 build
```
echo 'source /opt/windows_32/bin/win-builds-switch' >> ~/.profile 
```

>For windows 64 build
```
echo 'source /opt/windows_64/bin/win-builds-switch' >> ~/.profile 
```
#Compile xerces-c
Download xerces-c-3.1.4.tar.gz (from xerces web site: http://xerces.apache.org/xerces-c/ or from archive directory: http://archive.apache.org/dist/xerces/c/3/binaries/) 
tar -xvf xerces-c-3.1.4.tar.gz (copy folder in C:\MinGW\msys\1.0\opt)

>For windows 32 build
```
./configure --build=i686-w64-mingw32 --prefix=/opt/windows_32/mingw
make
make install
```

>For windows 64 build
```
./configure --build=x86_64-w64-mingw32 --prefix=/opt/windows_64/mingw
make
make install
```

>the xerces-c libraries will be to:

```
C:\MinGW\msys\1.0\opt\xerces-c-3.1.4\build\dist\staged\bin\libxerces-c-3-1.dll
C:\MinGW\msys\1.0\opt\xerces-c-3.1.4\build\dist\staged\lib\libxerces-c.a 
C:\MinGW\msys\1.0\opt\xerces-c-3.1.4\build\dist\staged\lib\libxerces-c.dll.a 
```

>Use **libxerces-c.dll.a** library in link settings to compile Criteria.

##What are libtool's .la file for?
it is textual file that includes description of library.

It allows libtool create platform independent names.

For example, libfoo goes to:

>Under linux:
```
/lib/libfoo.so       # symlink to shared object
/lib/libfoo.so.1     # symlink to shared object
/lib/libfoo.so.1.0.1 # shared object
/lib/libfoo.a        # static library
/lib/libfoo.la       # libtool library
```

>Under cygwin:
```
/lib/libfoo.dll.a    # import library
/lib/libfoo.a        # static library
/lib/libfoo.la       # libtool library
/bin/cygfoo_1.dll    # dll
```

>Under windows mingw:
```
/lib/libfoo.dll.a    # import library
/lib/libfoo.a        # static library
/lib/libfoo.la       # libtool library
/bin/foo_1.dll       # dll
```

So libfoo.la is the only file that preserved between platforms by libtool allowing to understand, what happens with:

1. library dependencies
2. actual file names
3. library version and revision

