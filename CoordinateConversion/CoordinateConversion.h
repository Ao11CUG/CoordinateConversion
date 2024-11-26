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

    // 椭球参数
    const double a = 6378137.0; // 长半轴
    const double e2 = 0.00669437999014; // 第一偏心率的平方

private slots:
    void plotXYGraph();
    void enlarge();
    void reduce();
    void showHelp(); // 添加 showHelp 槽函数

private:
    Ui::CoordinateConversionClass ui;
    QTableWidget* tableWidget;
    QTextEdit* reportTextEdit; // 用于显示生成的报告
    help help;
};
