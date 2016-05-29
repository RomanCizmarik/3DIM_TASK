/******************************
 * Author by: Roman Cizmarik
 ******************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ratioMode(Qt::IgnoreAspectRatio)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    dicomLoader = new DicomSeriesLoader(ui->listWidget);
    settingsDialog = new SettingsDialog(this);

    ui->graphicsView->setScene(scene);

    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),
            this,SLOT(on_listWidget_selected_item(int)));
    connect(settingsDialog,SIGNAL(ratioModeChanged(Qt::AspectRatioMode)),
            this,SLOT(on_ratio_mode_changed(Qt::AspectRatioMode)));

    //maximize window
    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dicomImg;
    delete scene;
    delete dicomLoader;
    delete settingsDialog;
}

void MainWindow::on_ratio_mode_changed(Qt::AspectRatioMode ratioMode_)
{
    ratioMode = ratioMode_;
    ui->graphicsView->fitInView(scene->itemsBoundingRect(),ratioMode);
}


void MainWindow::on_actionOpen_Folder_triggered()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    if(dirName.isEmpty()) return;
    QDir dir(dirName);
    if (!dir.exists()){
        QMessageBox::critical(0,"Error","Could not open directory.");
        return;
    }

    ui->listWidget->clear();
    dicomLoader->loadSeries(dir);

    showDicom(dicomLoader->getCurrentImage());

    setLabels();
}

void MainWindow::on_listWidget_selected_item(int row)
{
    dicomLoader->setCurrentIndex(row);
    showDicom(dicomLoader->getCurrentImage());
}

void MainWindow::on_actionOpen_triggered()
{
    //opens file dialog and gets DICOM file name
    QString fileNameAbsolute = QFileDialog::getOpenFileName(this, tr("Open"),
                                                           QString(),tr("DICOM Files (*.dcm)"));


    if(fileNameAbsolute.isEmpty()) return;

    if (!QFile::exists(fileNameAbsolute)){
        QMessageBox::critical(0,"Error","Could not open file.");
        return;
    }

    ui->listWidget->clear();
    dicomLoader->loadSeries(fileNameAbsolute);


    showDicom(dicomLoader->getCurrentImage());
    setLabels();

}

void MainWindow::showDicom(QImage img)
{

    scene->clear();
    scene->addPixmap(QPixmap::fromImage(img));
    ui->graphicsView->fitInView(scene->itemsBoundingRect(),ratioMode);
    ui->graphicsView->repaint();

}




void MainWindow::setLabels()
{
    ui->patientNameLabel->setText(dicomLoader->getCurrentQDicomImage()->getPatientName());
    ui->institutionLabel->setText(dicomLoader->getCurrentQDicomImage()->getInstitutionName());
    QString dateRaw = dicomLoader->getCurrentQDicomImage()->getStudyDate();
    QString formatedDate = dateRaw.right(2)  + "." + dateRaw.mid(4,2) + "." + dateRaw.left(4) ;
    ui->dateLabel->setText(formatedDate);
}
void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(),ratioMode);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
     if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Down)
         showDicom(dicomLoader->getPreviousImage());

     if(event->key() == Qt::Key_Right || event->key() == Qt::Key_Up)
         showDicom(dicomLoader->getNextImage());
}

void MainWindow::on_nextButton_clicked()
{

    showDicom(dicomLoader->getNextImage());
}

void MainWindow::on_previousButton_clicked()
{

    showDicom(dicomLoader->getPreviousImage());
}

void MainWindow::on_actionClose_triggered()
{
    close();
}


void MainWindow::on_actionSettings_triggered()
{
    settingsDialog->show();
}
