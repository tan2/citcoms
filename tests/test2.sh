#!/bin/sh
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
#<LicenseText>
#=====================================================================
#
#                             CitcomS.py
#                 ---------------------------------
#
#                              Authors:
#            Eh Tan, Eun-seo Choi, and Pururav Thoutireddy 
#          (c) California Institute of Technology 2002-2005
#
#        By downloading and/or installing this software you have
#       agreed to the CitcomS.py-LICENSE bundled with this software.
#             Free for non-commercial academic research ONLY.
#      This program is distributed WITHOUT ANY WARRANTY whatsoever.
#
#=====================================================================
#
#  Copyright June 2005, by the California Institute of Technology.
#  ALL RIGHTS RESERVED. United States Government Sponsorship Acknowledged.
# 
#  Any commercial use must be negotiated with the Office of Technology
#  Transfer at the California Institute of Technology. This software
#  may be subject to U.S. export control laws and regulations. By
#  accepting this software, the user agrees to comply with all
#  applicable U.S. export laws and regulations, including the
#  International Traffic and Arms Regulations, 22 C.F.R. 120-130 and
#  the Export Administration Regulations, 15 C.F.R. 730-744. User has
#  the responsibility to obtain export licenses, or other export
#  authority as may be required before exporting such information to
#  foreign countries or providing access to foreign nationals.  In no
#  event shall the California Institute of Technology be liable to any
#  party for direct, indirect, special, incidental or consequential
#  damages, including lost profits, arising out of the use of this
#  software and its documentation, even if the California Institute of
#  Technology has been advised of the possibility of such damage.
# 
#  The California Institute of Technology specifically disclaims any
#  warranties, including the implied warranties or merchantability and
#  fitness for a particular purpose. The software and documentation
#  provided hereunder is on an "as is" basis, and the California
#  Institute of Technology has no obligations to provide maintenance,
#  support, updates, enhancements or modifications.
#
#=====================================================================
#</LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

# coupled citcoms test
# 4-proc coarse-grid solver, 1-proc fine-grid solver
# with correction on outflow


FINE=fine
COARSE=coarse
OUTPUT=zzz
TEMPFILE=/tmp/$USER/tmptest2

rm $FINE.* $COARSE.*


coupledcitcoms.py  \
--launcher.nodegen="n%03d" \
--launcher.nodelist=[101-118,120-129,131-170] \
--launcher.nodes=5 \
--layout.coarse=[0-3] \
--layout.fine=[4] \
--coarse=regional \
--coarse.mesher=regional-sphere \
--coarse.datafile=$COARSE \
--coarse.mesher.nprocx=2 \
--coarse.mesher.nprocy=2 \
--coarse.mesher.nprocz=1 \
--coarse.mesher.nodex=9 \
--coarse.mesher.nodey=9 \
--coarse.mesher.nodez=9 \
--coarse.mesher.theta_max=1.795 \
--coarse.mesher.theta_min=1.345 \
--coarse.mesher.fi_max=1.795 \
--coarse.mesher.fi_min=1.345 \
--coarse.mesher.radius_inner=0.55 \
--coarse.mesher.radius_outer=1.0 \
--fine.datafile=$FINE \
--fine.mesher.nodex=17 \
--fine.mesher.nodey=17 \
--fine.mesher.nodez=17 \
--fine.mesher.theta_max=1.616875 \
--fine.mesher.theta_min=1.466875 \
--fine.mesher.fi_max=1.616875 \
--fine.mesher.fi_min=1.466875 \
--fine.mesher.radius_inner=0.709375 \
--fine.mesher.radius_outer=0.859375 \
--fine.bc.toptbc=0 \
--fine.bc.toptbcval=0 \
--fine.bc.bottbc=0 \
--fine.bc.bottbcval=0 \
--fine.vsolver.precond=False \
--fine.vsolver.accuracy=1e-9 \
--fine.vsolver.tole_compressibility=1e-6 \
--fine.vsolver.piterations=8000 \
--fine.vsolver.vlowstep=5000 \
--fine.vsolver.vhighstep=10 \
--steps=1 \
--controller.monitoringFrequency=1 \
> $OUTPUT


echo '1.61688 1.51375 0.765625' > $TEMPFILE
result=Failed
if grep 'X:' $OUTPUT | grep ' 183:' | awk '{print $4 " " $5 " " $6}' \
    | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: boundary.X ... $result.


echo '2755' > $TEMPFILE
result=Failed
if grep 'bid:' $OUTPUT | grep ' 1344:' | awk '{print $4}' \
    | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: bid2gid ... $result.


echo '1' > $TEMPFILE
if grep 'proc:' $OUTPUT | grep ' 954:' | awk '{print $4}' \
    | diff -w - $TEMPFILE; then

    echo '3' > $TEMPFILE
    if grep 'proc:' $OUTPUT | grep ' 955:' | awk '{print $4}' \
	| diff -w - $TEMPFILE; then
    result=Passed
    fi
fi
echo test2: bid2proc ... $result.


echo '1.87341' > $TEMPFILE
result=Failed
if grep 'before boundary' $OUTPUT | cut -c 52- | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: outflow1 ... $result.


echo '-1.12559e-15' > $TEMPFILE
result=Failed
if grep 'after boundary' $OUTPUT | cut -c 70- | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: outflow2 ... $result.


echo '9.978408e+02 9.975862e+02 1.673985e+03 0.000000e+00' > $TEMPFILE
result=Failed
if tail +3 $FINE.velo.0.0 | head -1 | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: imposeBC ... $result.


echo '<stdin>: N = 4913     <-2276.61/1956.99>      <-2275.61/1955.28>      <925.864/17051.2>       <0/1>' > $TEMPFILE
result=Failed
if tail +3 $FINE.velo.0.0 | minmax | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: minmax ... $result.


echo '-6.280208e+02 -3.384822e+02 1.110555e+04 4.940558e-01' > $TEMPFILE
result=Failed
if tail +2120 $FINE.velo.0.0 | head -1 | diff -w - $TEMPFILE; then
    result=Passed
fi
echo test2: content ... $result.


rm $TEMPFILE


# version
# $Id: test2.sh,v 1.5 2005/06/10 02:23:24 leif Exp $

# End of file