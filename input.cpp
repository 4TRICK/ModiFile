#include "input.h"
#include "modi.h"
#include <QTextStream>
#include <QDebug>
#include <QDir>

QString getInputFormat() {
    qDebug() << "Пожалуйста, укажите формат файлов, которые вы хотите обработать (.txt, .bin, .pro):";
    QString format;
    QTextStream input(stdin);
    format = input.readLine().trimmed();
    return format;
}

QString getInputDirPath() {
    qDebug() << "Пожалуйста, укажите путь к каталогу для поиска файлов:";
    QString dirPath;
    QTextStream input(stdin);
    dirPath = input.readLine().trimmed();

    // Проверяем существование указанного каталога
    while (!QDir(dirPath).exists()) {
        qDebug() << "Указанный каталог не существует. Пожалуйста, укажите существующий каталог:";
        dirPath = input.readLine().trimmed();
    }

    return dirPath;
}

QString chooseFile(const QStringList& files) {
    QString choiceStr;
    QTextStream input(stdin);

    while (true) {
        qDebug() << "Пожалуйста, выберите файл для обработки, указав его номер:";
        choiceStr = input.readLine().trimmed();
        bool ok;
        int choice = choiceStr.toInt(&ok);
        if (ok && choice > 0 && choice <= files.size()) {
            return files[choice - 1];
        } else {
            qDebug() << "Неверный ввод. Попробуйте еще раз.";
        }
    }

    // Этот return никогда не будет достигнут, просто для корректности компиляции
    return QString();
}
void processChosenFile(const QString& filePath, const QByteArray& key) {
    QFile checkFile(filePath);
    if (isFileOpen(filePath)) {
        qDebug() << "\"Error 53\" Файл уже открыт другим процессом. Выберите другой файл.";
        return;
    }

    if (!checkFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Не удалось открыть файл для записи. Выберите другой файл.";
        return;
    }
    checkFile.close();

    processFile(filePath, key);
}
