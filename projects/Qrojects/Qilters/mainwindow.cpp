#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
cv::Mat inpImg, outImg;
QString fileName;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//Function containing implementations of all Qilters(filters)
void MainWindow::processImage()
{
    inpImg = imread(ui->inputImgEdit->text().toStdString());

    if(ui->medianButton->isChecked())
        cv::medianBlur(inpImg, outImg, 5);

    else if(ui->gaussianButton->isChecked())
        cv::GaussianBlur(inpImg, outImg, Size(5,5), 1.0, 1.0);

    else if (ui->meanButton->isChecked())
        cv::boxFilter(inpImg, outImg, -1, Size(3,3), Point(-1,-1), true);

    else if(ui->blacknWhiteButton->isChecked())
    {
        cv::cvtColor(inpImg, outImg, CV_RGB2GRAY);
        cv::threshold(outImg, outImg, 80, 255, 1);
    }

    //Negative of image using Look up table
    else if(ui->negativeButton->isChecked())
    {
            QVector<uchar> LUT(256, 0);
            for(int i = 0; i < 256; i++)
                LUT[i] = (uchar)(255 - i);
            outImg = inpImg.clone();
            cv::cvtColor(outImg, outImg, cv::COLOR_RGB2GRAY);
            for(int j = 0; j < outImg.rows; j++){
                for(int k = 0; k < outImg.cols; k++)
                    outImg.at<uchar>(j,k) = LUT[outImg.at<uchar>(j,k)];
            }


    }

    //*********using colorMaps************
    else if(ui->rainbowButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_RAINBOW);
    }

    else if(ui->autumnButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_AUTUMN);
    }

    else if(ui->hotButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_HOT);
    }

    else if(ui->springButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_SPRING);
    }

    else if(ui->coolButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_COOL);
    }

    else if(ui->oceanButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_OCEAN);
    }

    else if(ui->hsvButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_HSV);
    }

    else if(ui->winterButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_WINTER);
    }

    else if(ui->summerButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_SUMMER);
    }

    else if(ui->pinkButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_PINK);
    }

    else if(ui->boneButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_BONE);
    }

    else if(ui->jetButton->isChecked())
    {
        cv::applyColorMap(inpImg, outImg, cv::COLORMAP_JET);
    }
    //*********************************************

    //**********Using Pseudo coloring**************
    else if(ui->bloodButton->isChecked())
    {
        Mat img;
        //Convert input image to grayscale first
        cv::cvtColor(inpImg, img, CV_BGR2GRAY);
        Mat empty = cv::Mat::zeros(img.size(), CV_8UC1);

            // Create a vector containing the channels of the new colored image
            std::vector<Mat> channels;

            channels.push_back(empty);
            channels.push_back(empty);
            channels.push_back(img);

            // Construct a new 3-channel image of the same size and depth i.e. outImg
            cv::merge(channels, outImg);
    }

    else if(ui->azureButton->isChecked())
    {
        Mat img;
        //Convert input image to grayscale first
        cv::cvtColor(inpImg, img, CV_BGR2GRAY);
        Mat empty = cv::Mat::zeros(img.size(), CV_8UC1);

            // Create a vector containing the channels of the new colored image
            std::vector<Mat> channels;

            channels.push_back(img);
            channels.push_back(empty);
            channels.push_back(empty);

            // Construct a new 3-channel image of the same size and depth i.e. outImg
            cv::merge(channels, outImg);
    }

    else if(ui->lemonButton->isChecked())
    {
        Mat img;
        //Convert input image to grayscale first
        cv::cvtColor(inpImg, img, CV_BGR2GRAY);
        Mat empty = cv::Mat::zeros(img.size(), CV_8UC1);

            // Create a vector containing the channels of the new colored image
            std::vector<Mat> channels;

            channels.push_back(empty);
            channels.push_back(img);
            channels.push_back(img);

            // Construct a new 3-channel image of the same size and depth i.e. outImg
            cv::merge(channels, outImg);
    }

    else if(ui->tulipButton->isChecked())
    {
        Mat img;
        //Convert input image to grayscale first
        cv::cvtColor(inpImg, img, CV_BGR2GRAY);
        Mat empty = cv::Mat::zeros(img.size(), CV_8UC1);

            // Create a vector containing the channels of the new colored image
            std::vector<Mat> channels;

            channels.push_back(img);
            channels.push_back(empty);
            channels.push_back(img);

            // Construct a new 3-channel image of the same size and depth i.e. outImg
            cv::merge(channels, outImg);
    }

    else if(ui->mintButton->isChecked())
    {
        Mat img;
        //Convert input image to grayscale first
        cv::cvtColor(inpImg, img, CV_BGR2GRAY);
        Mat empty = cv::Mat::zeros(img.size(), CV_8UC1);

            // Create a vector containing the channels of the new colored image
            std::vector<Mat> channels;

            channels.push_back(img);
            channels.push_back(img);
            channels.push_back(empty);

            // Construct a new 3-channel image of the same size and depth i.e. outImg
            cv::merge(channels, outImg);
    }

    else if(ui->emeraldButton->isChecked())
    {
        Mat img;
        //Convert input image to grayscale first
        cv::cvtColor(inpImg, img, CV_BGR2GRAY);
        Mat empty = cv::Mat::zeros(img.size(), CV_8UC1);

            // Create a vector containing the channels of the new colored image
            std::vector<Mat> channels;

            channels.push_back(empty);
            channels.push_back(img);
            channels.push_back(empty);

            // Construct a new 3-channel image of the same size and depth i.e. outImg
            cv::merge(channels, outImg);
    }
    //******************************************

}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//Browse button to select input image
void MainWindow::on_inputImgButton_pressed()
{
    fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Input Image",
                                                    QDir::currentPath(),
                                                    "Images(*.jpg *.png *.bmp)");
    if(QFile::exists(fileName))
    {
        ui ->inputImgEdit->setText(fileName);
    }
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//Browse button to save and select destination and name of output image
void MainWindow::on_outputImgButton_pressed()
{
    if(!fileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this,
                                                        "Select Output Image",
                                                        QDir::currentPath(),
                                                        "*.jpg *.png *.bmp");

        ui ->outputImgEdit->setText(fileName);
        processImage();
        imwrite(fileName.toStdString(), outImg);

        //To show images after user has saved the output image
        if(ui->displayCheckBox->isChecked())
        {
            imshow("Input Image", inpImg);
            imshow("Output Image", outImg);
            waitKey(0); //Close image windows by clicking any key
            destroyAllWindows();
        }
    }

    else
    {   //Error message when there is no input image
        QMessageBox msgError;
        msgError.setText("Please select Input image first!");
        msgError.exec();
    }
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//Implementation details of close(X) button
void MainWindow:: closeEvent(QCloseEvent *event)
{
    //Warning message when user click X button
    int result = QMessageBox::warning (this,
                                       "Exit",
                                       "Are you sure you want to close this program?",
                                       QMessageBox::Yes,
                                       QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        saveSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//To load previous settings(selection)
void MainWindow::loadSettings()
{
    QSettings settings("Aditya",
                       "Hello_OpenCv_Qt",
                       this);
    ui->inputImgEdit->setText(settings.value("inputImgEdit","").toString());
    ui->outputImgEdit->setText(settings.value("outputImgEdit","").toString());
    ui->coolButton->setChecked(settings.value("coolButton",true).toBool());
    //ui->gaussianButton->setChecked(settings.value("gaussianButton",false).toBool());
    ui->displayCheckBox->setChecked(settings.value("checkBox",false).toBool());

}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//To save previos settings(selection)
void MainWindow::saveSettings()
{
    QSettings settings("Aditya",
                       "Qilters",
                       this);
    settings.setValue("inputImgEdit",ui->inputImgEdit->text());
    settings.setValue("outputImgEdit",ui->outputImgEdit->text());
    settings.setValue("coolButton",ui->coolButton->isChecked());
    //settings.setValue("gaussianButton",ui->gaussianButton->isChecked());
    settings.setValue("displayCheckBox",ui->displayCheckBox->isChecked());
}

//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//Defination of Apply button
void MainWindow::on_applyButton_pressed()
{
//    Mat inpImg, outImg;
    if(!fileName.isEmpty())
    {
        processImage();

        imshow("Input Image", inpImg);
        imshow("Output Image", outImg);
        waitKey(0); ////Close image windows by clicking any key
        destroyAllWindows();
    }
    else
    {   //Error message when there is no input image
        QMessageBox msgError;
        msgError.setText("Please select Input image first!");
        msgError.exec();
    }
}
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
