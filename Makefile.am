AUTOMAKE_OPTIONS = foreign

SUBDIRS = src

EXTRA_DIST = COPYING ChangeLog AUTHORS README \
	RELEASE-NOTES \
	test/dummy-test.q \
	docs/dummy-module-doc.html \
	dummy-yaml-module.spec

ACLOCAL_AMFLAGS=-I m4

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck
