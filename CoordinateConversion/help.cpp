#include "help.h"

help::help(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    textEdit = findChild<QTextEdit*>("textEdit");
    if (textEdit) {
        textEdit->setReadOnly(true);

        textEdit->setText(
            "作者：向庆澳\n"
            "学校：中国地质大学\n"
            "学院：地理与信息工程学院\n"
            "提示：\n"
            "1.查看点位图时请多次点击放大按钮；\n"
            "2.若需要保存文本报告，请在生成报告后，点击保存文件按钮保存完整的报告；"
        );
    }

    setWindowTitle(tr("Help"));
}

help::~help()
{}
