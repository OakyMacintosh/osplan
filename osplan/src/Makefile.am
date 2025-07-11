bin_PROGRAMS = osplan
osplan_SOURCES = osplan.c args.c imagegen.c xgcc_shell.c
osplan_CPPFLAGS = -I$(top_srcdir)/osplan/src
osplan_LDADD =

noinst_HEADERS = args.h osplan.h imagegen.h xgcc_shell.h
osplan_LDADD = ../../components/tcc/libtcc.a
osplan_CPPFLAGS += -I../../components/tcc
