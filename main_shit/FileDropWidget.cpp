#include "FileDropWidget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

FileDropWidget::FileDropWidget(QWidget* parent) : QWidget(parent) {
    setAcceptDrops(true);  // Enable drag and drop
}

void FileDropWidget::dragEnterEvent(QDragEnterEvent* event) {
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void FileDropWidget::dropEvent(QDropEvent* event) {
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty()) return;

    QString destinationFolder = "C:/Users/PC/Documents/1. All My Stuff/Coding/system Scripting/";

    for (const QUrl& url : urls) {
        QString filePath = url.toLocalFile();
        QFileInfo fileInfo(filePath);
        QString destinationFilePath = destinationFolder + fileInfo.fileName();

        if (QFile::rename(filePath, destinationFilePath)) {
            qDebug() << "File moved successfully to" << destinationFilePath;
        } else {
            qDebug() << "Failed to move file:" << filePath;
        }
    }
}
