#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->openFileButton,SIGNAL(clicked()),this,SLOT(getFileInfoSlot()));
    ui->openFileButton->setIcon(QIcon(":/new/prefix1/Resources/operatmenu/fangda.png"));

  qDebug()<<"ddddddddddddddddddddd";
  qDebug()<<"ddddddddddddddddddddd";
  qDebug()<<"ddddddddddddddddddddd";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getFileInfoSlot()
   //先获得文件的名称
 {  QString fileName=QFileDialog::getOpenFileName(this,"打开文件",QDir::currentPath());
   // qDebug()<<"fileName is"<<fileName;
    qDebug()<<"hhhhhhhhhhh";
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Please select a textfile");
        return;
    }

        QFile *file=new QFile;//创建一个文件的对象
        file->setFileName(fileName);//设置文件的名称
        bool ok=file->open(QIODevice::ReadOnly);//以只读模式打开文件
        if (ok)
        {
           QTextStream in(file) ;//读入文本流
           ui->textEdit->setText( in.readAll()); //把所有的字符串从文件中读出来，然后包含在textEdit中
           QString str= ui->textEdit->toPlainText();


           QStringList list=str.split(QRegExp("\\s+"),QString::SkipEmptyParts);
           qDebug()<<"list:"<<str;
           qDebug()<<"list size() :"<<list.size();
           ui->lineEdit->setText(QString::number(list.size()));

          file->close();
          delete file;

        }
        else//利用errorstring（）返回错误信息
        {
        QMessageBox::information(this,"Error Message","File Open Error"+file->errorString());
        return;
        }
 }


