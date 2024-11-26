#include "CoordinateConversion.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QPen>

CoordinateConversion::CoordinateConversion(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    setWindowIcon(QIcon(":/CoordinateConversion/res/coordinate.png"));

    connect(ui.openFile, &QAction::triggered, this, &CoordinateConversion::openFile);
    connect(ui.saveFile, &QAction::triggered, this, &CoordinateConversion::saveFile);
    connect(ui.BLHtoXYZ, &QAction::triggered, this, &CoordinateConversion::convertBLHtoXYZ);
    connect(ui.XYZtoBLH, &QAction::triggered, this, &CoordinateConversion::convertXYZtoBLH);
    connect(ui.spotsPicture, &QAction::triggered, this, &CoordinateConversion::plotXYGraph);
    connect(ui.enlarge, &QAction::triggered, this, &CoordinateConversion::enlarge);
    connect(ui.reduce, &QAction::triggered, this, &CoordinateConversion::reduce);
    connect(ui.helpAction, &QAction::triggered, this, &CoordinateConversion::showHelp);

    tableWidget = new QTableWidget(ui.tab1);
    tableWidget->setColumnCount(7); // 更新为包含XYZ列
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "B" << "L" << "H" << "X" << "Y" << "Z");
    ui.tab1->layout()->addWidget(tableWidget);

    reportTextEdit = new QTextEdit(ui.tab3); // 创建 QTextEdit 控件用于显示报告
    reportTextEdit->setReadOnly(true); // 设置为只读模式
    ui.tab3->layout()->addWidget(reportTextEdit); // 将 QTextEdit 添加到 tab3

    ui.tabWidget->setCurrentIndex(0);
}

CoordinateConversion::~CoordinateConversion()
{}

void CoordinateConversion::openFile() {
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("txt (*.txt);;All (*)"));
    if (!fileName.isEmpty()) {
        loadTextFileToTable(fileName);
    }
}

void CoordinateConversion::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("txt (*.txt);;all (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }

        QTextStream out(&file);

        // 保存 tab1（tableWidget）的内容
        out << "=== data ===\n";
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            QString name = tableWidget->item(row, 0)->text();
            QString b = tableWidget->item(row, 1)->text();
            QString l = tableWidget->item(row, 2)->text();
            QString h = tableWidget->item(row, 3)->text();
            QString x = tableWidget->item(row, 4)->text();
            QString y = tableWidget->item(row, 5)->text();
            QString z = tableWidget->item(row, 6)->text();
            out << name << "," << b << "," << l << "," << h << "," << x << "," << y << "," << z << "\n";
        }
        out << "\n";

        // 保存 tab3（reportTextEdit）的内容
        out << "=== report ===\n";
        out << reportTextEdit->toPlainText() << "\n";

        file.close();
    }
}

void CoordinateConversion::loadTextFileToTable(const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 4) { // 假设有4个部分（名称，B，L，H）
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);

            QString name = parts.at(0);
            QString b = parts.at(1);
            QString l = parts.at(2);
            QString h = parts.at(3);

            QString b_dms = convertDegreeToDMS(b.toDouble());
            QString l_dms = convertDegreeToDMS(l.toDouble());

            QTableWidgetItem* itemName = new QTableWidgetItem(name);
            QTableWidgetItem* itemB = new QTableWidgetItem(b_dms);
            QTableWidgetItem* itemL = new QTableWidgetItem(l_dms);
            QTableWidgetItem* itemH = new QTableWidgetItem(h);

            // 保存原始度数值作为数据
            itemB->setData(Qt::UserRole, b.toDouble());
            itemL->setData(Qt::UserRole, l.toDouble());

            tableWidget->setItem(row, 0, itemName);
            tableWidget->setItem(row, 1, itemB);
            tableWidget->setItem(row, 2, itemL);
            tableWidget->setItem(row, 3, itemH);
        }
    }

    file.close();
}

QString CoordinateConversion::convertDegreeToDMS(double decimalDegree) {
    int deg = static_cast<int>(decimalDegree);
    double minDouble = (decimalDegree - deg) * 60;
    int min = static_cast<int>(minDouble);
    double secDouble = (minDouble - min) * 60;
    int sec = static_cast<int>(secDouble);
    return QString("%1\u00B0 %2' %3\"").arg(deg).arg(min).arg(sec);
}

void CoordinateConversion::convertBLHtoXYZ() {
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        bool okB, okL, okH;
        double B = tableWidget->item(row, 1)->data(Qt::UserRole).toDouble(&okB);
        double L = tableWidget->item(row, 2)->data(Qt::UserRole).toDouble(&okL);
        double H = tableWidget->item(row, 3)->text().toDouble(&okH);

        if (!okB || !okL || !okH) {
            continue;
        }

        double B_rad = qDegreesToRadians(B);
        double L_rad = qDegreesToRadians(L);

        double N = a / sqrt(1 - e2 * pow(sin(B_rad), 2));
        double X = (N + H) * cos(B_rad) * cos(L_rad);
        double Y = (N + H) * cos(B_rad) * sin(L_rad);
        double Z = (N * (1 - e2) + H) * sin(B_rad);

        QTableWidgetItem* itemX = new QTableWidgetItem(QString::number(X, 'f', 6));
        QTableWidgetItem* itemY = new QTableWidgetItem(QString::number(Y, 'f', 6));
        QTableWidgetItem* itemZ = new QTableWidgetItem(QString::number(Z, 'f', 6));

        tableWidget->setItem(row, 4, itemX);
        tableWidget->setItem(row, 5, itemY);
        tableWidget->setItem(row, 6, itemZ);

        generateReport("BLH to XYZ:\n" + QString("Name: %1\nB: %2\nL: %3\nH: %4\nX: %5\nY: %6\nZ: %7\n")
            .arg(tableWidget->item(row, 0)->text())
            .arg(tableWidget->item(row, 1)->text())
            .arg(tableWidget->item(row, 2)->text())
            .arg(tableWidget->item(row, 3)->text())
            .arg(tableWidget->item(row, 4)->text())
            .arg(tableWidget->item(row, 5)->text())
            .arg(tableWidget->item(row, 6)->text()));
    }
}

void CoordinateConversion::convertXYZtoBLH() {
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        bool okX, okY, okZ;
        double X = tableWidget->item(row, 4)->text().toDouble(&okX);
        double Y = tableWidget->item(row, 5)->text().toDouble(&okY);
        double Z = tableWidget->item(row, 6)->text().toDouble(&okZ);

        if (!okX || !okY || !okZ) {
            continue;
        }

        double L = atan2(Y, X);
        double p = sqrt(X * X + Y * Y);
        double B0 = atan2(Z, p * (1 - e2));
        double N, B, H;

        do {
            B = B0;
            N = a / sqrt(1 - e2 * sin(B) * sin(B));
            H = p / cos(B) - N;
            B0 = atan2(Z + N * e2 * sin(B), p);
        } while (fabs(B - B0) > 1e-9);

        double B_deg = qRadiansToDegrees(B);
        double L_deg = qRadiansToDegrees(L);

        QTableWidgetItem* itemB = new QTableWidgetItem(convertDegreeToDMS(B_deg));
        QTableWidgetItem* itemL = new QTableWidgetItem(convertDegreeToDMS(L_deg));
        QTableWidgetItem* itemH = new QTableWidgetItem(QString::number(H, 'f', 3));

        tableWidget->setItem(row, 1, itemB);
        tableWidget->setItem(row, 2, itemL);
        tableWidget->setItem(row, 3, itemH);

        generateReport("XYZ to BLH:\n" + QString("Name: %1\nX: %2\nY: %3\nZ: %4\nB: %5\nL: %6\nH: %7\n")
            .arg(tableWidget->item(row, 0)->text())
            .arg(tableWidget->item(row, 4)->text())
            .arg(tableWidget->item(row, 5)->text())
            .arg(tableWidget->item(row, 6)->text())
            .arg(tableWidget->item(row, 1)->text())
            .arg(tableWidget->item(row, 2)->text())
            .arg(tableWidget->item(row, 3)->text()));
    }
}

void CoordinateConversion::plotXYGraph() {
    QGraphicsView* view = ui.tab2->findChild<QGraphicsView*>("graphView");
    QGraphicsScene* scene;

    if (view) {
        // 清空现有场景
        scene = view->scene();
        scene->clear();
    }
    else {
        // 创建新的 QGraphicsScene 和 QGraphicsView
        scene = new QGraphicsScene(this);
        view = new QGraphicsView(scene);
        view->setObjectName("graphView"); // 设置对象名称
        ui.tab2->layout()->addWidget(view);
    }

    double maxX = 0;
    double maxY = 0;
    double scale = 0.00001; // 调整缩放因子，根据实际需求调整

    // 获取表格中的X和Y值，假设在表格中的列索引为4和5（第5和第6列）
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QTableWidgetItem* itemX = tableWidget->item(row, 4);
        QTableWidgetItem* itemY = tableWidget->item(row, 5);

        if (!itemX || !itemY) {
            continue;
        }

        double xValue = itemX->text().toDouble();
        double yValue = itemY->text().toDouble();

        // 计算缩放因子，使得数据适应坐标轴范围
        maxX = qMax(maxX, qAbs(xValue));
        maxY = qMax(maxY, qAbs(yValue));
    }

    // 绘制坐标轴
    scene->addLine(0, -maxY * scale, 0, maxY * scale, QPen(Qt::black)); // y轴
    scene->addLine(-maxX * scale, 0, maxX * scale, 0, QPen(Qt::black)); // x轴

    // 添加刻度
    double tickSpacingX = maxX / 5.0; // X轴刻度间距
    double tickSpacingY = maxY / 5.0; // Y轴刻度间距

    // 绘制X轴刻度
    for (double x = -maxX; x <= maxX; x += tickSpacingX) {
        scene->addLine(x * scale, -2.5 * scale, x * scale, 2.5 * scale, QPen(Qt::black));
    }

    // 绘制Y轴刻度
    for (double y = -maxY; y <= maxY; y += tickSpacingY) {
        scene->addLine(-2.5 * scale, -y * scale, 2.5 * scale, -y * scale, QPen(Qt::black));
    }

    // 绘制数据点
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QTableWidgetItem* itemX = tableWidget->item(row, 4);
        QTableWidgetItem* itemY = tableWidget->item(row, 5);

        if (!itemX || !itemY) {
            continue;
        }

        double xValue = itemX->text().toDouble();
        double yValue = itemY->text().toDouble();

        // 映射点的坐标到场景坐标
        QPointF point(xValue * scale, -yValue * scale); // 注意y轴是负值，因为场景坐标原点在左上角

        // 绘制点
        double pointSize = 0.25; // 调整点的大小
        scene->addEllipse(point.x() - pointSize / 2, point.y() - pointSize / 2, pointSize, pointSize, QPen(Qt::blue), QBrush(Qt::blue));
    }

    // 添加轴标签
    QGraphicsTextItem* labelX = scene->addText("X"); // X轴标签
    labelX->setPos(maxX * scale + 5, 0); // 设置X轴标签位置

    QGraphicsTextItem* labelY = scene->addText("Y"); // Y轴标签
    labelY->setPos(0, -maxY * scale - 15); // 设置Y轴标签位置
}

void CoordinateConversion::enlarge() {
    QGraphicsView* view = findChild<QGraphicsView*>("graphView");
    if (view) {
        view->scale(1.2, 1.2); // 放大比例，可以调整
    }
}

void CoordinateConversion::reduce() {
    QGraphicsView* view = findChild<QGraphicsView*>("graphView");
    if (view) {
        view->scale(0.8, 0.8); // 缩小比例，可以调整
    }
}

void CoordinateConversion::generateReport(const QString& text) {
    reportTextEdit->append(text);
}

void CoordinateConversion::showHelp() {
    help.show();
}