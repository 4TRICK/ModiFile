#ifndef INPUT_H
#define INPUT_H

#include <QString>
#include <QStringList>

QString getInputFormat();
QString getInputDirPath();
QString chooseFile(const QStringList& files);

#endif // INPUT_H
