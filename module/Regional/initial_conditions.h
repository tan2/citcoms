// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//<LicenseText>
//=====================================================================
//
//                             CitcomS.py
//                 ---------------------------------
//
//                              Authors:
//            Eh Tan, Eun-seo Choi, and Pururav Thoutireddy 
//          (c) California Institute of Technology 2002-2005
//
//        By downloading and/or installing this software you have
//       agreed to the CitcomS.py-LICENSE bundled with this software.
//             Free for non-commercial academic research ONLY.
//      This program is distributed WITHOUT ANY WARRANTY whatsoever.
//
//=====================================================================
//
//  Copyright June 2005, by the California Institute of Technology.
//  ALL RIGHTS RESERVED. United States Government Sponsorship Acknowledged.
// 
//  Any commercial use must be negotiated with the Office of Technology
//  Transfer at the California Institute of Technology. This software
//  may be subject to U.S. export control laws and regulations. By
//  accepting this software, the user agrees to comply with all
//  applicable U.S. export laws and regulations, including the
//  International Traffic and Arms Regulations, 22 C.F.R. 120-130 and
//  the Export Administration Regulations, 15 C.F.R. 730-744. User has
//  the responsibility to obtain export licenses, or other export
//  authority as may be required before exporting such information to
//  foreign countries or providing access to foreign nationals.  In no
//  event shall the California Institute of Technology be liable to any
//  party for direct, indirect, special, incidental or consequential
//  damages, including lost profits, arising out of the use of this
//  software and its documentation, even if the California Institute of
//  Technology has been advised of the possibility of such damage.
// 
//  The California Institute of Technology specifically disclaims any
//  warranties, including the implied warranties or merchantability and
//  fitness for a particular purpose. The software and documentation
//  provided hereunder is on an "as is" basis, and the California
//  Institute of Technology has no obligations to provide maintenance,
//  support, updates, enhancements or modifications.
//
//=====================================================================
//</LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyCitcom_initial_conditions_h)
#define pyCitcom_initial_conditions_h


extern char pyCitcom_ic_constructTemperature__name__[];
extern char pyCitcom_ic_constructTemperature__doc__[];
extern "C"
PyObject * pyCitcom_ic_constructTemperature(PyObject *, PyObject *);


extern char pyCitcom_ic_restartTemperature__name__[];
extern char pyCitcom_ic_restartTemperature__doc__[];
extern "C"
PyObject * pyCitcom_ic_restartTemperature(PyObject *, PyObject *);


extern char pyCitcom_ic_initPressure__name__[];
extern char pyCitcom_ic_initPressure__doc__[];
extern "C"
PyObject * pyCitcom_ic_initPressure(PyObject *, PyObject *);


extern char pyCitcom_ic_initVelocity__name__[];
extern char pyCitcom_ic_initVelocity__doc__[];
extern "C"
PyObject * pyCitcom_ic_initVelocity(PyObject *, PyObject *);


extern char pyCitcom_ic_initViscosity__name__[];
extern char pyCitcom_ic_initViscosity__doc__[];
extern "C"
PyObject * pyCitcom_ic_initViscosity(PyObject *, PyObject *);

#endif

// version
// $Id: initial_conditions.h,v 1.3 2005/06/10 02:23:19 leif Exp $

// End of file
