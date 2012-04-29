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
    linksdescriptor.cpp \
    path.cpp \
    constraint.cpp \
    solvers/backtracking/btsolver.cpp \
    constraintinterface.cpp \
    constraints/AllDifferentElements/alldifferentelementsconstraint.cpp \
    solver.cpp \
    constraints/MaxLength/maxlengthconstraint.cpp \
    constraints/MaxLength/maxlengthconstraintinterface.cpp \
    constraints/AllDifferentElements/alldifferentelementsconstraintinterface.cpp \
    constraints/MaxLength/maxlengthconstraintdialog.cpp \
    constraintchooserdialog.cpp \
    constraintpositionchooserdialog.cpp \
    constraints/AllConnectedToEachOther/allconnectedtoeachother.cpp \
    constraints/AllConnectedToEachOther/allconnectedtoeachotherconstraintinterface.cpp \
    constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraintinterface.cpp \
    constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraint.cpp \
    constraints/StartFromPoint/startfrompointconstraint.cpp \
    constraints/StartFromPoint/startfrompointconstraintinterface.cpp \
    solvers/dijkstra/dijkstrasolver.cpp \
    constraintdialog.cpp \
    solvers/genetic/geneticengine.cpp
    #solvers/flooding/floodingsolver.cpp \
    #solvers/flooding/floodingrouter.cpp \
    #solvers/flooding/floodingrouternetknowledge.cpp \
    #solvers/flooding/floodingpacket.cpp
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
    linksdescriptor.h \
    path.h \
    constraint.h \
    solvers/backtracking/btsolver.h \
    constraintinterface.h \
    constraints/AllDifferentElements/alldifferentelementsconstraint.h \
    solver.h \
    constraints/MaxLength/maxlengthconstraint.h \
    constraints/MaxLength/maxlengthconstraintinterface.h \
    constraints/AllDifferentElements/alldifferentelementsconstraintinterface.h \
    constraints/MaxLength/maxlengthconstraintdialog.h \
    constraintchooserdialog.h \
    constraintpositionchooserdialog.h \
    constraints/AllConnectedToEachOther/allconnectedtoeachother.h \
    constraints/AllConnectedToEachOther/allconnectedtoeachotherconstraintinterface.h \
    constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraintinterface.h \
    constraints/LastPointConnectedToFirst/lastpointconnectedtofirstconstraint.h \
    constraints/StartFromPoint/startfrompointconstraint.h \
    constraints/StartFromPoint/startfrompointconstraintinterface.h \
    solvers/dijkstra/dijkstrasolver.h \
    constraintdialog.h \
    solvers/genetic/geneticengine.h
    #solvers/flooding/floodingsolver.h \
    #solvers/flooding/floodingrouter.h \
    #solvers/flooding/floodingrouternetknowledge.h \
    #solvers/flooding/floodingpacket.h
OTHER_FILES += TODO.txt \
    testSalvataggio.txt
FORMS += updatelinkdialog.ui \
    propertiesdialog.ui \
    linkinfodialog.ui \
    reportviewerdialog.ui \
    nodesselectordialog.ui \
    constraints/MaxLength/maxlengthconstraintdialog.ui \
    constraintchooserdialog.ui \
    constraintpositionchooserdialog.ui
#RESOURCES +=

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp
