/******************************
 * Author by: Roman Cizmarik
 ******************************/

#ifndef DICOMSERIESLOADER_H
#define DICOMSERIESLOADER_H

#include <QDir>
#include <QVector>
#include <QListWidget>
#include "qdicomimage.h"

class DicomSeriesLoader
{
public:
    DicomSeriesLoader();
    DicomSeriesLoader(QListWidget *listWidget_);
    DicomSeriesLoader(QDir dir_);
    ~DicomSeriesLoader();

    /**
     * @brief loadSeries
     * Loads all DICOM files from current directory
     */
    void loadSeries();
    void loadSeries(QDir dir_);
    void loadSeries(QString fileNameAbsolute);

    /**
     * @brief setDir
     * @param dir_
     * Sets current directory
     */
    void setDir(QDir dir_);

    /**
     * @brief getQImage
     * @param index
     * @return QImage extracted from dicom
     * Returns QImage on given index
     */
    QImage getQImage(int index);
    /**
     * @brief getQImage
     * @param fileName
     * @return QImage extracted from dicom
     * Returns QImage based on file name
     */
    QImage getQImage(QString fileName);

    /**
     * @brief getCurrentImage
     * @return QImage
     * Returns QImage at current index
     */
    QImage getCurrentImage();

    /**
     * @brief getCurrentImage
     * @return QImage
     * Increments current index and returns QImage
     */
    QImage getNextImage();

    /**
     * @brief getCurrentImage
     * @return QImage
     * Decrements current index and returns QImage
     */
    QImage getPreviousImage();

    /**
     * @brief getCurrentQDicomImage
     * @return QDicomImage *
     * Returns pointer on QDicomImage at current index
     */
    QDicomImage* getCurrentQDicomImage();

    /**
     * @brief getCurrentQDicomImage
     * @return QDicomImage *
     * Returns pointer on QDicomImage at given index
     */
    QDicomImage* getQDicomImage(int index);

    int getCurrentIndex() const;
    void setCurrentIndex(int value);

private:

    /**
     * @brief currentIndex
     * Index of currently shown file within current directory
     */
    int currentIndex;
    /**
     * @brief currentDir
     * Directory from wich DICOM files are loaded
     */
    QDir currentDir;
    QListWidget *listWidget;
    QStringList fileList;
    QString currentFileNameAbsolute;
    QString currentFileName;

    QVector<QImage> qImagesVector;
    QVector<QDicomImage*> qDicomImagesVector;
    void setCurrentIndexInDir();
};

#endif // DICOMSERIESLOADER_H
