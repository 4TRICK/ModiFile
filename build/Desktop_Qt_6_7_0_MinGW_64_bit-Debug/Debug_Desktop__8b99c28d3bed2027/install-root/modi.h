#ifndef MODI_H
#define MODI_H

#include <QString>
#include <QByteArray>

bool isFileOpen(const QString& filePath);
bool isFileWritable(const QString& filePath);
void processFile(const QString& filePath, const QByteArray& key);

#endif // MODI_H
