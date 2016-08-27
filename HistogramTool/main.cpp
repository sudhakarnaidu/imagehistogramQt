/*******************************************************************************
** (C) Copyright 2016 by #CompanyName
** All rights reserved
**
** This program is the property of #CompanyName, #Location, #Country,
** and can only be used and copied with the prior written authorisation of
** #Company name.
**
** Any whole or partial copy of this program in either its original form or in a
** modified form must mention this copyright and its owner.
** *****************************************************************************
** PROJECT: Histogram Tool
** *****************************************************************************
** FILE NAME: main.cpp
** *****************************************************************************
** REVISION HISTORY:
** 1).Initial draft version.
********************************************************************************
** AUTHOR NAME: Sudhakar NAIDU
*******************************************************************************/
#include <QCoreApplication>
#include <QImage>
#include <QStringList>
#include <QFuture>
#include <QList>
#include <QtConcurrent/QtConcurrent>
#include "ImageHistogram.h"
#ifdef UNIT_TESTING
#include "UnitTest.h"
#endif

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // get the commandline arguments
    const QStringList args = app.arguments();
    // if invalid number of command line parameters provided
    if( args.size() < 3)
    {
        qDebug()<<"Invalid parameters; Command usage as follows";
        qDebug()<<"Executable_name Image_path output_file_path";
        return -1;
    }

    // load input image
    QImage img;
    if( img.load(args[1]) )
    {
        //Create ImageHistogram object
        ImageHistogram image(&img);
        //Get histogram data
        QList<QList<uint>> result = image.getHistogramData();
        QFile histogramDataFile(args[2]);
        //if unable to create output file
        if(!histogramDataFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug()<<"Unable to create output file";
            return -1;
        }
        // for each color histogram add data to file in one line
        for( int colorIndex = 0; colorIndex < result.size(); colorIndex++  )
        {
            QString histogramData="";
            for(int histIndex=0; histIndex< HIST_MAX_VALUE ; histIndex++)
            {
                histogramData.append(QString::number(result.at(colorIndex).
                                                     at(histIndex)));
                histogramData.append(",");
            }
            histogramData.chop(1);
            histogramDataFile.write(histogramData.toUtf8());
            histogramDataFile.write("\n");
        }
        histogramDataFile.close();
        qDebug()<<"Output Histogram File successfully genenerated";
    }
    else
    {
        qDebug()<<"Unable to load Image file";
        return -1;
    }

#ifdef UNIT_TESTING
    UnitTest unitTest;
    unitTest.performUnittest();
#endif
        return 0;
}
