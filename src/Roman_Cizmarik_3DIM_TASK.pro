#-------------------------------------------------
#
# Project created by QtCreator 2016-05-29T15:12:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Roman_Cizmarik_3DIM_TASK
TEMPLATE = app


INCLUDEPATH += C:/dcmtk-3.6.1/dcmdata/include
INCLUDEPATH += C:/dcmtk-3.6.1/build/config/include
INCLUDEPATH += C:/dcmtk-3.6.1/ofstd/include
INCLUDEPATH += C:/dcmtk-3.6.1/oflog/include
INCLUDEPATH += C:/dcmtk-3.6.1/dcmsr/include
INCLUDEPATH += C:/dcmtk-3.6.1/dcmimgle/include
INCLUDEPATH += C:/dcmtk-3.6.1/dcmimage/include
INCLUDEPATH += C:/dcmtk-3.6.1/dcmjpls/include


QMAKE_LIBDIR += "C:/dcmtk-3.6.1/build/bin/Release"
QMAKE_LIBDIR += "C:/dcmtk-3.6.1/build/lib/Release"

DCMTK_LIBS = -LC:/dcmtk-3.6.1/build/bin/Release \
            -ldcmdata \
            -lofstd\
            -ldcmimgle\
            -ldcmimage\
            -ldcmjpls

LIBS += $${DCMTK_LIBS}

INCLUDEPATH += C:/dcmtk-3.6.1/build/bin/Release
DEPENDPATH += C:/dcmtk-3.6.1/build/bin/Release

INCLUDEPATH += C:/dcmtk-3.6.1/build/lib/Release
DEPENDPATH += C:/dcmtk-3.6.1/build/lib/Release

DEFINES -= UNICODE

SOURCES += main.cpp\
        mainwindow.cpp \
    qdicomimage.cpp \
    dicomseriesloader.cpp \
    settingsdialog.cpp \
    graphicsview.cpp

HEADERS  += mainwindow.h \
    qdicomimage.h \
    dicomseriesloader.h \
    settingsdialog.h \
    graphicsview.h

FORMS    += mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    res.qrc
