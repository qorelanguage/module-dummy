DUMMY_SOURCES = dummy-module.cpp

lib_LTLIBRARIES = dummy.la
dummy_la_SOURCES = $(DUMMY_SOURCES)
dummy_la_LDFLAGS = -module -avoid-version ${DUMMY_LIBS}

INCLUDES = -I$(top_srcdir)/include

AM_CPPFLAGS=$(QORE_CPPFLAGS)

if COND_PROFILE
AM_CXXFLAGS=-g -pg
else
if COND_DEBUG
AM_CXXFLAGS=-g
endif
endif

install-exec-hook:
	mv $(DESTDIR)$(libdir)/dummy.$(MODULE_SUFFIX) $(DESTDIR)$(libdir)/dummy-api-$(MODULE_API).qmod
	rm -f $(DESTDIR)$(libdir)/dummy.la
