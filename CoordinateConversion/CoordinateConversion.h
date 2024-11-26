#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoordinateConversion.h"
#include <QTableWidget>
#include <QTabWidget>
#include <QGraphicsScene>
#include <QWidget>
#include <QPainter>
#include <QTextStream>
#include <QTextEdit>
#include <QGraphicsView>
#include "help.h"

class CoordinateConversion : public QMainWindow
{
    Q_OBJECT

public:
    CoordinateConversion(QWidget* parent = nullptr);
    ~CoordinateConversion();

    QString fileName;
    void openFile();
    void saveFile();
    void loadTextFileToTable(const QString& fileName);
    QString convertDegreeToDMS(double coordinate);
    void convertBLHtoXYZ();
    void convertXYZtoBLH();
    void generateReport(const QString& text);

    // �������
    const double a = 6378137.0; // ������
    const double e2 = 0.00669437999014; // ��һƫ���ʵ�ƽ��

private slots:
    void plotXYGraph();
    void enlarge();
    void reduce();
    void showHelp(); // ��� showHelp �ۺ���

private:
    Ui::CoordinateConversionClass ui;
    QTableWidget* tableWidget;
    QTextEdit* reportTextEdit; // ������ʾ���ɵı���
    help help;
};
