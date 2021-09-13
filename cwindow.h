#ifndef CWINDOW_H
#define CWINDOW_H

#include <QWidget>

namespace Ui {
class CWindow;
}

class CWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CWindow(QWidget *parent = nullptr);
    ~CWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CWindow *ui;
};

#endif // CWINDOW_H
