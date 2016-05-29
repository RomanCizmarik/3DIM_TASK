/******************************
 * Author by: Roman Cizmarik
 ******************************/

#include "dicomseriesloader.h"
#include <QDebug>

DicomSeriesLoader::DicomSeriesLoader():
    currentIndex(-1)
{

}

DicomSeriesLoader::DicomSeriesLoader(QListWidget *listWidget_):
    currentIndex(-1),
    listWidget(listWidget_)
{

}

DicomSeriesLoader::DicomSeriesLoader(QDir dir_):
    currentIndex(-1)
{
    setDir(dir_);
}

DicomSeriesLoader::~DicomSeriesLoader()
{
    for (int i = 0; i < qDicomImagesVector.length(); ++i) {
        delete qDicomImagesVector.at(i);
    }

}

void DicomSeriesLoader::loadSeries()
{
    if(fileList.isEmpty()) return;

    if(!qDicomImagesVector.isEmpty()){
        for (int i = 0; i < qDicomImagesVector.length(); ++i) {
            delete qDicomImagesVector.at(i);

        }
        qDicomImagesVector.resize(0);
    }

    for (int i = 0; i < fileList.length(); ++i) {
        qDicomImagesVector.append(new QDicomImage(currentDir.absolutePath() +"/"+ fileList.at(i)));
        qImagesVector.append( qDicomImagesVector.last()->outputData());
        if(listWidget != NULL){
            QIcon ico(QPixmap::fromImage(qImagesVector.last()));
            QListWidgetItem* item = new QListWidgetItem(ico,QString::number(i+1));
            item->setSizeHint(QSize(40,40));
            listWidget->addItem(item);
        }


    }

}

void DicomSeriesLoader::loadSeries(QDir dir_)
{
    setDir(dir_);
    currentIndex = 0;
    loadSeries();

}

void DicomSeriesLoader::loadSeries(QString fileNameAbsolute)
{
    currentFileNameAbsolute = fileNameAbsolute;
    setDir(QFileInfo(fileNameAbsolute).absoluteDir());
    setCurrentIndexInDir();
    loadSeries();
}

void DicomSeriesLoader::setDir(QDir dir_)
{
    currentDir = dir_;
    currentDir.setNameFilters(QStringList()<<"*.dcm");
    fileList = currentDir.entryList();

}

QImage DicomSeriesLoader::getQImage(int index)
{
    if(qImagesVector.isEmpty()) return QImage();

    if(index < 0 || index > qImagesVector.length()) return QImage();

    return qImagesVector.at(index);
}

QImage DicomSeriesLoader::getQImage(QString fileName)
{

    return getQImage(fileList.indexOf(QRegExp(fileName)));
}

QImage DicomSeriesLoader::getCurrentImage()
{
    return getQImage(currentIndex);
}

QImage DicomSeriesLoader::getNextImage()
{
    if(currentIndex == -1) return QImage();

    if(currentIndex +1 >= fileList.length() )
        currentIndex = 0;
    else
        currentIndex ++;

    return getQImage(currentIndex);
}

QImage DicomSeriesLoader::getPreviousImage()
{
    if(currentIndex == -1) return QImage();

     if(currentIndex -1 <= 0 )
         currentIndex = fileList.length()-1;
     else
         currentIndex --;

     return getQImage(currentIndex);
}

QDicomImage *DicomSeriesLoader::getCurrentQDicomImage()
{
    return getQDicomImage(currentIndex);
}

QDicomImage *DicomSeriesLoader::getQDicomImage(int index)
{
    if(index < 0 || index > qDicomImagesVector.length()) return NULL;

    return qDicomImagesVector.at(index);
}

int DicomSeriesLoader::getCurrentIndex() const
{
    return currentIndex;
}

void DicomSeriesLoader::setCurrentIndex(int value)
{
    currentIndex = value;
}

void DicomSeriesLoader::setCurrentIndexInDir()
{
    if(fileList.isEmpty()) return;

    //current file name without absolute path
    currentFileName = QFileInfo(currentFileNameAbsolute).fileName();

    //index of current file in dir
    currentIndex = fileList.indexOf(QRegExp(currentFileName));
}
