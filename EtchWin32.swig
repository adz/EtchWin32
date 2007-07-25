
%runtime %{
#undef read
#undef write
%}

%module(directors="1") EtchWin32
%{
	#include "stdafx.h"
	#include "PrinterEnv.h"
	#include "Printable.h"
	#include "PrintContext.h"
	#include "PrintFont.h"
	#include "PageSpec.h"
	#include "PrintingException.h"
%}

%exception getPrinter {
 try {
   $action
 }
 catch (PrintingException &e) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, e.getMessage());
 }
}

%exception printDocument {
 try {
   $action
 }
 catch (PrintingException &e) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, e.getMessage());
 }
}

%exception drawString {
 try {
   $action
 }
 catch (PrintingException &e) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, e.getMessage());
 }
}

%feature("director") Printable; 

%include "PrinterEnv.h"
%include "Printer.h"
%include "Printable.h"
%include "PrintContext.h"
%include "PrintFont.h"
%include "PageSpec.h"
%include "PrintingException.h"