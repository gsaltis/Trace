QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC                       = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

QMAKE_LFLAGS_WINDOWS            += -mwindows
#QMAKE_LFLAGS_WINDOWS            += -Wl,--subsystem,console

QMAKE_CXXFLAGS                  += 

QMAKE_LIBS                      = 

TARGET                          = TraceServer
RESOURCES                       += TraceServer.qrc

VERSION                         = "0.9.0"

QMAKE_TARGET_COMPANY            = "Vertiv Company"

QMAKE_TARGET_PRODUCT            = "TraceServer"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2023 Vertiv Company"

QT                              += core gui widgets network

DEFINES                         += \

SOURCES                         += \
				   ElementTypeLabel.cpp                         \
				   MainDisplayWindow.cpp                        \
				   MainDisplayWindowControlBar.cpp              \
				   MainWindow.cpp                               \
				   Server.cpp                                   \
				   SystemConfig.cpp                             \
				   TextDisplayWindow.cpp                        \
				   TextDisplayWindowDisplayArea.cpp             \
				   TextDisplayWindowDisplayElement.cpp          \
				   TextDisplayWindowScrollArea.cpp              \
				   main.cpp                                     \

HEADERS                         += \
				   ElementTypeLabel.h                           \
				   MainDisplayWindow.h                          \
				   MainDisplayWindowControlBar.h                \
				   MainWindow.h                                 \
				   Server.h                                     \
				   SystemConfig.h                               \
				   TextDisplayWindow.h                          \
				   TextDisplayWindowDisplayArea.h               \
				   TextDisplayWindowDisplayElement.h            \
				   TextDisplayWindowScrollArea.h                \

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
