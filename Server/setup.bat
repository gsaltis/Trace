@echo off
doskey m=make -j 4 -f Makefile.Release $T make -j 4 -f Makefile.Debug
doskey mr=make -j 4 -f Makefile.Release
doskey md=make -j 4 -f Makefile.Debug
doskey mc=make cleanall
doskey mq=qmake
doskey ts=release\TraceServer $*
doskey tsd=debug\TraceServer $*
title TraceServer
