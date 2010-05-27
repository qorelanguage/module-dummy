/* indent-tabs-mode: nil -*- */
/*
  dummy example/sample Qore module

  Copyright (C) 2010 Qore Technologies, all rights reserved

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <qore/Qore.h>
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

QoreStringNode *dummy_module_init();
void dummy_module_ns_init(QoreNamespace *rns, QoreNamespace *qns);
void dummy_module_delete();

// qore module symbols
DLLEXPORT char qore_module_name[] = "dummy";
DLLEXPORT char qore_module_version[] = PACKAGE_VERSION;
DLLEXPORT char qore_module_description[] = "dummy module";
DLLEXPORT char qore_module_author[] = "Petr Vanek";
DLLEXPORT char qore_module_url[] = "http://qore.org";
DLLEXPORT int qore_module_api_major = QORE_MODULE_API_MAJOR;
DLLEXPORT int qore_module_api_minor = QORE_MODULE_API_MINOR;
DLLEXPORT qore_module_init_t qore_module_init = dummy_module_init;
DLLEXPORT qore_module_ns_init_t qore_module_ns_init = dummy_module_ns_init;
DLLEXPORT qore_module_delete_t qore_module_delete = dummy_module_delete;
DLLEXPORT qore_license_t qore_module_license = QL_GPL;


static AbstractQoreNode *f_hello(const QoreListNode *args, ExceptionSink *xsink) {
   return new QoreStringNode("Hello World");
}


QoreNamespace DummyNS("Dummy");

QoreStringNode *dummy_module_init() {
   // string hello()
   builtinFunctions.add2("hello", f_hello, QC_RET_VALUE_ONLY, QDOM_DEFAULT, stringTypeInfo, 0);

   return 0;
}

void dummy_module_ns_init(QoreNamespace *rns, QoreNamespace *qns) {
   qns->addNamespace(DummyNS.copy());
}

void dummy_module_delete() {
   // nothing to do here in this case
}

