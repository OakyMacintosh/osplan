bin_PROGRAMS = osplan

osplan_SOURCES = \
  main.c \
  xgcc_shell.c \
  utils.c

if USE_XGCC
osplan_CPPFLAGS += -DUSE_XGCC_SHELL
osplan_LDADD += $(XGCC_BIN)
endif
