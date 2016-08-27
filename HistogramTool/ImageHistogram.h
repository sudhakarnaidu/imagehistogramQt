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
** FILE NAME: ImageHistogram.h
** *****************************************************************************
** REVISION HISTORY:
** 1).Initial draft version.
********************************************************************************
** AUTHOR NAME: Sudhakar NAIDU
*******************************************************************************/
#ifndef IMAGEHISTOGRAM_H
#define IMAGEHISTOGRAM_H

#include<QList>
#include<QImage>

#define HIST_MAX_VALUE 256

/**
 * @brief The ImageHistogram class To generate the histogram data
 */
class ImageHistogram
{
    /**
     * @brief image Reference to the input image
     */
    QImage *image;
public:
    /**
     * @brief ImageHistogram Class constructor initializes object
     * @param img Reference to the input image
     */
    explicit ImageHistogram(QImage *img=NULL);

    /**
     * @brief getHistogramData Function to return the histogram data
     * based on image type
     * @return returns histogram data in list
     */
    QList<QList<uint>> getHistogramData();
};

#endif // IMAGEHISTOGRAM_H
