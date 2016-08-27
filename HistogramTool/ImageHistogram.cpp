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
** FILE NAME: ImageHistogram.cpp
** *****************************************************************************
** REVISION HISTORY:
** 1).Initial draft version.
********************************************************************************
** AUTHOR NAME: Sudhakar NAIDU
*******************************************************************************/

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include "ImageHistogram.h"

/**
 * @brief histogram Gobal function executed in parallel
 * @param colorComp list of pixel color intensity values
 * @return returns histogram data points
 */
QList<uint> histogram(QList<uchar> colorComp)
{
    QList<uint> histogramData;
    for(uint i=0; i<HIST_MAX_VALUE; i++)
    {
        histogramData.append(0);
    }
    foreach (uchar color, colorComp)
    {
        histogramData[(uint)color]++;
    }
   return histogramData;
}

/**
 * @brief ImageHistogram Class constructor initializes object
 * @param img Reference to the input image
 */
ImageHistogram::ImageHistogram(QImage *img):
    image(img)
{
    //nothing to do
}

/**
 * @brief getHistogramData Function to return the histogram data
 * based on image type
 * @return returns histogram data in list
 */
QList<QList<uint>> ImageHistogram::getHistogramData()
{
    if( image != NULL )
    {
        uchar *bits = image->bits();
        QList<QList<uchar>> imagePixels;
        uint b=0;
        //gray scale image
        if( image->format() == QImage::Format_Indexed8)
        {
            QList<uchar> pixels;
            //loop through all pixels
            for( int x = 0; x < image->height(); x++)
            {
                for(int y = 0; y < image->width(); y++)
                {
                    uchar rv = (bits[b + 0]);
                    pixels.append(rv);
                }
            }
            imagePixels.append(pixels);
        }
        else if( image->format() == QImage::Format_RGB32 )
        {
            QList<uchar> redPixels;
            QList<uchar> greenPixels;
            QList<uchar> bluePixels;
            //loop through all pixels
            for( int x = 0; x < image->height(); x++)
            {
                for(int y = 0; y < image->width(); y++)
                {
                    uchar bv = bits[b + 0];
                    bluePixels.append(bv);
                    uchar gv = bits[b + 1];
                    greenPixels.append(gv);
                    uchar rv = bits[b + 2];
                    redPixels.append(rv);
                    //24bits data to be considered
                    b+=4;
                }
            }
            imagePixels.append(redPixels);
            imagePixels.append(greenPixels);
            imagePixels.append(bluePixels);
        }
        //Multi thread concurrent excution in multi core system
        QFuture<QList<uint>> res = QtConcurrent::mapped(imagePixels, histogram );
        res.waitForFinished();
        QList<QList<uint>> result = res.results();
        return result;
    }
    return QList<QList<uint>>();
}
