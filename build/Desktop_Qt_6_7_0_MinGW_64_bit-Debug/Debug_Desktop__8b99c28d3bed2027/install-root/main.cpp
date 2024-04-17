#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QStringList>
#include "input.h"
#include "modi.h"
#include <clocale>
#include <windows.h>

int main(int argc, char *argv[]) {
    // Устанавливаем кодировку для вывода в консоль
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    QCoreApplication a(argc, argv);

    QString format;
    QString dirPath;

    // Запрашиваем формат файлов
    format = getInputFormat();

    // Формируем фильтр для поиска файлов указанного формата
    QStringList filters;
    filters << "*" + format;

    // Запрашиваем путь к каталогу для поиска файлов
    while (dirPath.isEmpty() || !QDir(dirPath).exists()) {
        dirPath = getInputDirPath();
        if (!QDir(dirPath).exists()) {
            qDebug() << "Указанный каталог не существует. Пожалуйста, укажите существующий каталог.";
        }
    }

    QDir directory(dirPath);
    QStringList files = directory.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);

    // Проверяем, найдены ли файлы с указанным форматом
    if (files.isEmpty()) {
        qDebug() << "В указанном каталоге не найдены файлы с указанным форматом.";
        return 0;
    }

    // Выводим найденные файлы на экран
    qDebug() << "Найдены файлы с указанным форматом:";
    for (int i = 0; i < files.size(); ++i) {
        qDebug() << i + 1 << ":" << files[i];
    }

    QString chosenFile;
    // Запрашиваем у пользователя выбор файла для обработки
    chosenFile = chooseFile(files);

    QString chosenFilePath = directory.absoluteFilePath(chosenFile);
    // Обрабатываем выбранный файл
    processFile(chosenFilePath, QByteArray("\x12\x34\x56\x78\x9A\xBC\xDE\xF0")); // Пример ключа

    return a.exec();
}
