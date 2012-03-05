# -------------------------------------------------
# Project created by QtCreator 2011-05-31T12:04:13
# -------------------------------------------------
QT += core \
    gui \
    webkit \
    script
TARGET = RoadRage
TEMPLATE = app
SOURCES += main.cpp \
    updatelinkdialog.cpp \
    propertiesdialog.cpp \
    node.cpp \
    linkinfodialog.cpp \
    link.cpp \
    graphinformationhandler.cpp \
    diagramwindow.cpp \
    reportviewerdialog.cpp \
    nodesselectordialog.cpp \
    linksdescriptor.cpp 
HEADERS += updatelinkdialog.h \
    ui_linkinfodialog.h \
    propertiesdialog.h \
    node.h \
    linkinfodialog.h \
    link.h \
    graphinformationhandler.h \
    diagramwindow.h \
    reportviewerdialog.h \
    nodesselectordialog.h \
    linksdescriptor.h 
OTHER_FILES += TODO.txt \
    testSalvataggio.txt
FORMS += updatelinkdialog.ui \
    propertiesdialog.ui \
    linkinfodialog.ui \
    reportviewerdialog.ui \
    nodesselectordialog.ui 
#RESOURCES +=

#QMAKE_CXXFLAGS += -fopenmp
#QMAKE_LFLAGS += -fopenmp
