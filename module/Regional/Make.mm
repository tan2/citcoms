# -*- Makefile -*-
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
#                               Michael A.G. Aivazis
#                        California Institute of Technology
#                        (C) 1998-2003  All Rights Reserved
#
# <LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#

include local.def
TYPE=Regional

PROJECT = CitcomS
PACKAGE = $(TYPE)module
include std-pythonmodule.def

PROJ_CXX_SRCLIB = $(BLD_LIBDIR)/lib$(PROJECT)$(TYPE).$(EXT_LIB) 
PROJ_CXX_INCLUDES = ../../lib/Common ../../lib/$(TYPE)
#PROJ_CXX_INCLUDES = $(BLD_INCDIR)/$(PROJECT)/$(TYPE)

PROJ_SRCS = \
    bindings.cc \
    exceptions.cc \
    misc.cc \
    output_bindings.cc

# version
# $Id: Make.mm,v 1.5 2003/05/21 21:28:00 tan2 Exp $

# End of file
