
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
 catch (...) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, "An unexpected exception occured.");
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
 catch (...) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, "An unexpected exception occured.");
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
 catch (...) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, "An unexpected exception occured.");
 }
}

%exception getFontMultistyle {
 try {
   $action
 }
 catch (PrintingException &e) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, e.getMessage());
 }
 catch (...) {
   static VALUE cpperror = rb_define_class("PrintingException", rb_eStandardError);
   rb_raise(cpperror, "An unexpected exception occured.");
 }
}

%feature("director") Printable; 

%include "std_vector.i"

namespace std {
   //%template(vectorf) vector<PrintFont::FontStyle>;
   //%template(vectorNum) std::vector<PrintContext::NUMBER>;
	%template(Vectori) std::vector<int>;
};


%include "PrinterEnv.h"
%include "Printer.h"
%include "Printable.h"
%include "PrintContext.h"
%include "PrintFont.h"
%include "PageSpec.h"
%include "PrintingException.h"

