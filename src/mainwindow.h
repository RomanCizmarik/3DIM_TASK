#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>

/******************************
 * Author by: Roman Cizmarik
 ******************************/

#include "qdicomimage.h"
#include "dicomseriesloader.h"
#include "settingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
     * @brief on_ratio_mode_changed
     * @param ratioMode_
     * Changes aspect ratio
     */
    void on_ratio_mode_changed(Qt::AspectRatioMode ratioMode_);
    /**
     * @brief on_listWidget_selected_item
     * @param row
     * Selects item from list widget
     */
    void on_listWidget_selected_item(int row);

protected slots:
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    /**
     * @brief on_actionOpen_triggered
     * Opens specified dicom file
     */
    void on_actionOpen_triggered();

    /**
     * @brief on_actionOpen_Folder_triggered
     * Opens whole directory, shows first dicom image
     */
    void on_actionOpen_Folder_triggered();

    void on_nextButton_clicked();

    void on_previousButton_clicked();

    void on_actionClose_triggered();

    void on_actionSettings_triggered();

    void on_actionZoom_out_triggered();

    void on_actionZoom_in_triggered();

    void on_action300_triggered();

    void on_action200_triggered();

    void on_action100_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QDicomImage *dicomImg;
    DicomSeriesLoader* dicomLoader;
    SettingsDialog *settingsDialog;

    Qt::AspectRatioMode ratioMode;

    /**
     * @brief showDicom
     * @param img
     * Renders image into graphics scene
     */
    void showDicom(QImage img);

    /**
     * @brief setLabels
     * Sets labels: patient name, date, institution
     */
    void setLabels();

};

/** TODO
*   zoom
*   listwidgetitem
*   commenty + autor
*
**/

#endif // MAINWINDOW_H
