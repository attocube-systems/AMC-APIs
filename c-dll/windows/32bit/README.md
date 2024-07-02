# attocube C-Library

This is the C-Library for attocube products.

Copyright (C) 2020 attocube systems AG

Usage is up to a separate agreement

## Getting Started

### Prerequisites

You need a C compiler for your platform and CMake for your platform


### Installing

First compile the API for your platform. This is done with CMake. 
It is highly recommended to use an out of souce build in the buld directory.

You can build release and debug code. 
To build release code start CMake like this:
cmake -DCMAKE_BUILD_TYPE=Release ..

To build debug code start CMake like this:
cmake -DCMAKE_BUILD_TYPE=Debug ..

####
Linux:

> cd ...../API_AMC_IDS/build
> cmake -DCMAKE_BUILD_TYPE=Release ..
> make

That's it

####
Windows:

Start the initialization script for your compiler. E.g.
>c:\Program Files\Microsoft\MicrosoftVisualStudio\....\vcvars64.bat
>
> cd .....\API_AMC_IDS\build
> cmake -DCMAKE_BUILD_TYPE=Release ..
> nmake


### Usage

Have a look at the supplied tester.c file

