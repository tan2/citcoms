/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *<LicenseText>
 *=====================================================================
 *
 *                              CitcomS
 *                 ---------------------------------
 *
 *                              Authors:
 *           Louis Moresi, Shijie Zhong, Lijie Han, Eh Tan,
 *           Clint Conrad, Michael Gurnis, and Eun-seo Choi
 *          (c) California Institute of Technology 1994-2005
 *
 *        By downloading and/or installing this software you have
 *       agreed to the CitcomS.py-LICENSE bundled with this software.
 *             Free for non-commercial academic research ONLY.
 *      This program is distributed WITHOUT ANY WARRANTY whatsoever.
 *
 *=====================================================================
 *
 *  Copyright June 2005, by the California Institute of Technology.
 *  ALL RIGHTS RESERVED. United States Government Sponsorship Acknowledged.
 * 
 *  Any commercial use must be negotiated with the Office of Technology
 *  Transfer at the California Institute of Technology. This software
 *  may be subject to U.S. export control laws and regulations. By
 *  accepting this software, the user agrees to comply with all
 *  applicable U.S. export laws and regulations, including the
 *  International Traffic and Arms Regulations, 22 C.F.R. 120-130 and
 *  the Export Administration Regulations, 15 C.F.R. 730-744. User has
 *  the responsibility to obtain export licenses, or other export
 *  authority as may be required before exporting such information to
 *  foreign countries or providing access to foreign nationals.  In no
 *  event shall the California Institute of Technology be liable to any
 *  party for direct, indirect, special, incidental or consequential
 *  damages, including lost profits, arising out of the use of this
 *  software and its documentation, even if the California Institute of
 *  Technology has been advised of the possibility of such damage.
 * 
 *  The California Institute of Technology specifically disclaims any
 *  warranties, including the implied warranties or merchantability and
 *  fitness for a particular purpose. The software and documentation
 *  provided hereunder is on an "as is" basis, and the California
 *  Institute of Technology has no obligations to provide maintenance,
 *  support, updates, enhancements or modifications.
 *
 *=====================================================================
 *</LicenseText>
 * 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

// static const int cap_connections11[14][7] =
static const int cap_connections[14][7] =
    {   {0, 0, 0, 0, 0, 0, 0},
        {0, 4,11,10, 2, 7,12},
        {0, 4,12, 1, 3, 5,11},
        {0, 5,12, 2, 6, 4, 9},
        {0, 7, 2, 1, 5,10, 3},
        {0, 7, 3, 4, 6, 8, 2},
        {0, 8, 3, 5, 9, 7,12},
        {0,10, 5, 4, 8, 1, 6},
        {0,10, 6, 7, 9,11, 5},
        {0,11, 6, 8,12,10, 3},
        {0, 1, 8, 7,11, 4, 9},
        {0, 1, 9,10,12, 2, 8},
        {0, 2, 9,11, 3, 1, 6},
        {0, 0, 0, 0, 0, 0, 0}   };

// static const int cap_connections22[50][9] =
//     {   {0, 0, 0, 0, 0, 0, 0, 0, 0},
// 	{0,13, 2,37, 3,25, 4,14,39},
// 	{0, 1,41,39, 4,37,43, 3, 0},
// 	{0,14, 4, 1, 5,13, 6, 0, 2},
// 	{0, 3,43, 2, 6, 1,45, 5,41},
// 	{0,14, 6, 3, 7, 0, 8,16, 4},
// 	{0, 5,45, 4, 8, 3,47, 7,43},
// 	{0,16, 8, 5, 9,14,10,18, 6},
// 	{0, 7,47, 6,10, 5, 0, 9,45},
// 	{0,18,10, 7,11,16,12,20, 8},
// 	{0, 9,47, 8,12, 7,48,11, 0},
// 	{0,20,12, 9,22,18,24, 0,10},
// 	{0,11,48,10,24, 9,36,22,47},
// 	{0,25,14, 1,15,37,16,26, 3},
// 	{0,13, 5, 3,16, 1, 7,15, 0},
// 	{0,26,16,13,17,25,18, 0,14},
// 	{0,15, 7,14,18,13, 9,17, 5},
// 	{0,26,18,15,19, 0,20,28,16},
// 	{0,17, 9,16,20,15,11,19, 7},
// 	{0,28,20,17,21,26,22,30,18},
// 	{0,19,11,18,22,17, 0,21, 9},
// 	{0,30,22,19,23,28,24,32,20},
// 	{0,21,11,20,24,19,12,23, 0},
// 	{0,32,24,21,34,30,36, 0,22},
// 	{0,23,12,22,36,21,48,34,11},
// 	{0,37,26,13,27, 1,28,38,15},
// 	{0,25,17,15,28,13,19,27, 0},
// 	{0,38,28,25,29,37,30, 0,26},
// 	{0,27,19,26,30,25,21,29,17},
// 	{0,38,30,27,31, 0,32,40,28},
// 	{0,29,21,28,32,27,23,31,19},
// 	{0,40,32,29,33,38,34,42,30},
// 	{0,31,23,30,34,29, 0,33,21},
// 	{0,42,34,31,35,40,36,44,32},
// 	{0,33,23,32,36,31,24,35, 0},
// 	{0,44,36,33,46,42,48, 0,34},
// 	{0,35,24,34,48,33,12,46,23},
// 	{0, 1,38,25,39,13,40, 2,27},
// 	{0,37,29,27,40,25,31,39, 0},
// 	{0, 2,40,37,41, 1,42, 0,38},
// 	{0,39,31,38,42,37,33,41,29},
// 	{0, 2,42,39,43, 0,44, 4,40},
// 	{0,41,33,40,44,39,35,43,31},
// 	{0, 4,44,41,45, 2,46, 6,42},
// 	{0,43,35,42,46,41, 0,45,33},
// 	{0, 6,46,43,47, 4,48, 8,44},
// 	{0,45,35,44,48,43,36,47, 0},
// 	{0, 8,48,45,10, 6,12, 0,46},
// 	{0,47,36,46,12,45,24,10,35},
// 	{0, 0, 0, 0, 0, 0, 0, 0, 0}   };

      /* give case # (1-6) for given # of caps per proc */ 
static const int cases[14] = 
      {0,1,2,3,4,0,5,0,0,0,0,0,6,0};

      /* give global cap id for a given local cap and a case */ 
static const struct comm {
     int links[12]; }  incases1[7] =
         { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
           { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12},
           { 1, 2, 3, 6, 4, 5, 7, 8, 9,12,10,11},
           { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12},
           { 1, 2, 3,12, 4, 5, 6, 7, 8, 9,10,11},
           { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12},
           { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12} };

      /* give surface proc id for a given global cap and a case */ 
static const struct comm  
                       incases2[7] =
         { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
           { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11},
           { 0, 0, 1, 2, 2, 1, 3, 3, 4, 5, 5, 4},
           { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
           { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 0},
           { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

static const struct sph{
     int xy[2]; }  incases3[7] =
         { { 0, 0},
	   { 2, 6},
	   { 2, 3},
	   { 2, 2},
	   { 1, 3},
	   { 1, 2},
	   { 1, 1}};
