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
** FILE NAME: UnitTest.h
** *****************************************************************************
** REVISION HISTORY:
** 1).Initial draft version.
********************************************************************************
** AUTHOR NAME: Sudhakar NAIDU
*******************************************************************************/
#ifndef UNITTEST_H
#define UNITTEST_H

//Forward declaration, no need to include header
class QImage;

/**
 * @brief The UnitTest class to perfrom unit tests
 */
class UnitTest
{

public:
    /**
     * @brief UnitTest Constructor initializes the object
     */
    UnitTest();

    /**
     * @brief performUnittest Function to perfrom unittests
     */
    void performUnittest();
private:

    /**
     * @brief unitTest1 Function to test the image with same intensity
     * values
     */
    void unitTest1();

    /**
     * @brief unitTest2 Function to test the image with different intensity
     * values for each pixel
     */
    void unitTest2();

    /**
     * @brief WIDTH Const member to set image width
     */
    const uint WIDTH = 256;

    /**
     * @brief HEIGHT Const member to set image height
     */
    const uint HEIGHT = 256;

    /**
     * @brief img Refrence to the image
     */
    QImage *img;
};

#endif // UNITTEST_H
