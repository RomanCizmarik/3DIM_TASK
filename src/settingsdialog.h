/******************************
 * Author by: Roman Cizmarik
 ******************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

signals:
    /**
     * @brief ratioModeChanged
     * @param ratioMode
     * Emitted when aspect ratio mode changed
     */
    void ratioModeChanged(Qt::AspectRatioMode ratioMode);

private slots:
    void on_ignoreAspectRatioRB_toggled(bool checked);

    void on_keepAspectRatioRB_toggled(bool checked);

    void on_aspectRatioExpandingRB_toggled(bool checked);

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
