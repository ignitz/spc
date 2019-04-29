#!/bin/bash

PREFIX=2011039023

mkdir -p $PREFIX
cp solutions/uri/2674/2674.cpp $PREFIX/P1.cpp
cp solutions/uri/2123/2123.cpp $PREFIX/P2.cpp
cp solutions/uri/2337/2337.cpp $PREFIX/P3.cpp
cp solutions/uva/1347/1347.cpp $PREFIX/P4.cpp
cp solutions/icpc/7427/7427.cpp $PREFIX/P5.cpp
cp solutions/uri/2082/2082.cpp $PREFIX/P6.cpp
cp solutions/uri/2734/2734.cpp $PREFIX/P7.cpp
cp solutions/uri/1697/1697.cpp $PREFIX/P8.cpp
cp solutions/icpc/6887/6887.cpp $PREFIX/P9.cpp
cp solutions/uri/1602/1602.cpp $PREFIX/P10.cpp
cp solutions/uri/1207/1207.cpp $PREFIX/P11.cpp
cp solutions/uri/1716/1716.cpp $PREFIX/P12.cpp
cp solutions/uri/1904/1904.cpp $PREFIX/P13.cpp
cp solutions/uri/1394/1394.cpp $PREFIX/P14.cpp

(cd $PREFIX && zip -r ../$PREFIX.zip .)