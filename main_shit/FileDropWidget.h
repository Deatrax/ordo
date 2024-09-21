#ifndef FILEDROPWIDGET_H
#define FILEDROPWIDGET_H

#include <QWidget>

class FileDropWidget : public QWidget {
    Q_OBJECT

public:
    explicit FileDropWidget(QWidget* parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
};

#endif // FILEDROPWIDGET_H
