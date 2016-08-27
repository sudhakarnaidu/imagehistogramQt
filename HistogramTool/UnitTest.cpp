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
** FILE NAME: UnitTest.cpp
** *****************************************************************************
** REVISION HISTORY:
** 1).Initial draft version.
********************************************************************************
** AUTHOR NAME: Sudhakar NAIDU
*******************************************************************************/
#include <QList>
#include <QDebug>

#include "UnitTest.h"
#include "ImageHistogram.h"

/**
 * @brief UnitTest Constructor initializes the object
 */
UnitTest::UnitTest()
{
    img = new QImage(WIDTH, HEIGHT, QImage::Format_RGB32);
}

/**
 * @brief unitTest1 Function to test the image with same intensity
 * values
 */
void UnitTest::unitTest1()
{
    //Construct image with same intensity values
    for(uint y = 0; y < HEIGHT; y++)
    {
        for(uint x=0; x < WIDTH; x++)
        {
            QColor color(0, 0, 0);
            img->setPixel(x, y, color.rgba());
        }
    }
    //Imagehistogram object
    ImageHistogram imgHistogram(img);
    QList<QList<uint>> result = imgHistogram.getHistogramData();
    uint pixelCount = WIDTH*HEIGHT;
    //only first element has maximum value
    if( result[0][0] == pixelCount &&
        result[1][0] == pixelCount &&
        result[2][0] == pixelCount )
    {
        qDebug()<<"Unit Test 1: Pass";
    }
    else
    {
        qDebug()<<"Unit Test 1: Fail";
    }
}

/**
 * @brief unitTest2 Function to test the image with different intensity
 * values for each pixel
 */
void UnitTest::unitTest2()
{
    bool error = 0;

    //Construct image with different intensity values in a row
    for(int y = 0; y < HEIGHT; y++)
    {
        for(int x=0; x < WIDTH; x++)
        {
            QColor color(x, x, x);
            img->setPixel(x, y, color.rgba());
        }
    }
    ImageHistogram imgHistogram(img);
    QList<QList<uint>> result = imgHistogram.getHistogramData();
    int sum = 0;
    // test all values in result
    for(int index = 0; index < result.size(); index++)
    {
        for(int x=0; x< WIDTH; x++)
        {
            sum += result[index][x];
            //All the values should match; otherwise error
            if( result[index][x] == HEIGHT)
            {
                error = 0;
            }
            else
            {
                error = 1;
                break;
            }
        }
        //break for one error value
        if( error == 1)
        {
            break;
        }
    }
    //if all the values matches and sum of the values should
    //equal to total intensity values
    if( error == 0 && sum == WIDTH*HEIGHT*3)
    {
        qDebug()<<"Unit Test 2: pass";
    }
    else
    {
        qDebug()<<"Unit Test 2: Fail";
    }
}

/**
 * @brief performUnittest Function to perfrom unittest
 */
void UnitTest::performUnittest()
{
    unitTest1();
    unitTest2();
}
