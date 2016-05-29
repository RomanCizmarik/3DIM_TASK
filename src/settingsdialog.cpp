/******************************
 * Author by: Roman Cizmarik
 ******************************/

#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_ignoreAspectRatioRB_toggled(bool checked)
{
     if(checked) emit ratioModeChanged(Qt::IgnoreAspectRatio);
}

void SettingsDialog::on_keepAspectRatioRB_toggled(bool checked)
{
    if(checked) emit ratioModeChanged(Qt::KeepAspectRatio);
}

void SettingsDialog::on_aspectRatioExpandingRB_toggled(bool checked)
{
    if(checked) emit ratioModeChanged(Qt::KeepAspectRatioByExpanding);
}
