QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

#QMAKE_LFLAGS_WINDOWS            += -mwindows
QMAKE_LFLAGS_WINDOWS            += -Wl,--subsystem,console

QMAKE_CXXFLAGS                  += 

QMAKE_LIBS                      = 

TARGET                          = TraceServer

VERSION                         = "0.0.0"
QMAKE_TARGET_COMPANY            = "Vertiv Company"

QMAKE_TARGET_PRODUCT            = "TraceServer"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Vertiv Company"

QT                              += core gui widgets network

DEFINES                         += \

SOURCES                         += \
				   MainDisplayWindow.cpp                        \
                                   MainDisplayWindowControlBar.cpp              \
                                   MainWindow.cpp                               \
				   Server.cpp                                   \
				   SystemConfig.cpp                             \
				   main.cpp                                     \
                                   TextDisplayWindow.cpp                        \
                                   TextDisplayWindowScrollArea.cpp              \
                                   TextDisplayWindowDisplayArea.cpp             \
                                   TextDisplayWindowDisplayElement.cpp          \

HEADERS                         += \
				   MainDisplayWindow.h                          \
                                   MainDisplayWindowControlBar.h                \
				   MainWindow.h                                 \
				   Server.h                                     \
				   SystemConfig.h                               \
                                   TextDisplayWindow.h                          \
                                   TextDisplayWindowScrollArea.h                \
                                   TextDisplayWindowDisplayArea.h               \
                                   TextDisplayWindowDisplayElement.h            \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = 
cleanall.depends                = junkclean                                     \
                                  clean
