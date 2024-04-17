#include "modi.h"
#include "input.h"
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

bool isFileOpen(const QString& filePath) {
    QFile file(filePath);
    return file.isOpen();
}

bool isFileWritable(const QString& filePath) {
    QFile file(filePath);
    return file.isWritable();
}

void processFile(const QString& filePath, const QByteArray& key) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Не удалось открыть файл:" << filePath;
        getInputDirPath();
    }

    QByteArray data = file.readAll();
    for (int i = 0; i < data.size(); ++i) {
        data[i] = data[i] ^ key[i % key.size()];
    }

    file.close();

    if (file.error() != QFile::NoError) {
        qDebug() << "Входной файл не был закрыт. Отмена обработки.";
        exit(1);
    }

    QString downloadsPath = QDir::homePath() + "/Downloads/tempF";
    QDir().mkpath(downloadsPath);

    QFileInfo fileInfo(filePath);
    QString baseName = fileInfo.baseName();
    QString suffix = fileInfo.completeSuffix();

    int fileCounter = 1;
    while (QFile::exists(downloadsPath + "/" + baseName + QString::number(fileCounter) + "." + suffix)) {
        ++fileCounter;
    }
    QString newFilePath = downloadsPath + "/" + baseName + QString::number(fileCounter) + "." + suffix;

    QFile newFile(newFilePath);
    if (!newFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Не удалось создать новый файл для сохранения:" << newFilePath;
        exit(1);
    }
    newFile.write(data);
    newFile.close();

    qDebug() << "Файл успешно обработан и сохранен как\n" << newFilePath;
    exit(0);

}
