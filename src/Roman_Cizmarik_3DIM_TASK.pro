#-------------------------------------------------
#
# Project created by QtCreator 2016-05-29T15:12:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Roman_Cizmarik_3DIM_TASK
TEMPLATE = app

############# CHANGE THIS ####################
DCMTK_PATH = C:/dcmtk-3.6.1/
DCMTK_BUILD_PATH = C:/dcmtk-3.6.1/build/
##############################################

INCLUDEPATH += $$DCMTK_PATH"dcmdata/include"
INCLUDEPATH += $$DCMTK_PATH"ofstd/include"
INCLUDEPATH += $$DCMTK_PATH"oflog/include"
INCLUDEPATH += $$DCMTK_PATH"dcmsr/include"
INCLUDEPATH += $$DCMTK_PATH"dcmimgle/include"
INCLUDEPATH += $$DCMTK_PATH"dcmimage/include"
INCLUDEPATH += $$DCMTK_PATH"dcmjpls/include"
INCLUDEPATH += $$DCMTK_BUILD_PATH"config/include"


QMAKE_LIBDIR += $$DCMTK_BUILD_PATH"bin/Release"
QMAKE_LIBDIR += $$DCMTK_BUILD_PATH"lib/Release"

DCMTK_LIBS = -LC:/dcmtk-3.6.1/build/bin/Release \
            -ldcmdata \
            -lofstd\
            -ldcmimgle\
            -ldcmimage\
            -ldcmjpls

LIBS += $${DCMTK_LIBS}

INCLUDEPATH += $$DCMTK_BUILD_PATH"bin/Release"
DEPENDPATH += $$DCMTK_BUILD_PATH"bin/Release"

INCLUDEPATH += $$DCMTK_BUILD_PATH"lib/Release"
DEPENDPATH += $$DCMTK_BUILD_PATH"lib/Release"

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
