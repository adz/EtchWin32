========================================================================
    DYNAMIC LINK LIBRARY : EtchWin32 Project Overview
========================================================================

NOTE: This is a fork of http://rubyforge.org/projects/etch/ so I can install it as a gem for mingw

Requirements
------------


This library exposes a number of objects and methods to ruby for the purpose of enabling the 
developer to print without having to write any C code or make calls to the underlying print API. As
of the current release, the library uses get() and set() style accessors and mutators rather than
wrapping them in ruby-centric properties. Ruby accessors might be added in the future although
until further notice, the get() and set() methods will remain for backwards compat.

The developer should be interested in the following classes:

PrinterEnv
----------
	This is the entry point to all printing methods. In order to enumerate or 
	use printers, you must first create an instance of PrinterEnv.
	
	Methods
	-------
	int getPrinterCount(): Returns the number of printers installed on this machine.
	Printer getPrinter(unsigned int index): Return the printer at the given index. Throws a 
		PrintingException if index is greater than the number of printers
	Printer getPrinter(String name): Return the printer of the given name. Throws a 
		PrintingException if no printer is found of the given name.
	Printer getDefaultPrinter(): Return the default system printer.

Printer
-------
	The printer. Currently it is just a wrapper around the printer name, but in future it will
	have configuration options and the like.
	
	Methods
	-------
	String getName(): Return the name of the given printer.

Printable
---------
	A printable document. This class must be subclassed in order to function correctly. Implementors
	must override print(PrintContext * ctx). The actual operations of a print process are defined
	with callbacks on the PrintContext (see below).
	
	Methods
	-------
	void setPrinter(Printer printer): Set the printer. This must be called before printDocument().
	void printDocument(): Print the document.
	void print(PrintContext ctx): a NO-OP until overridden. Callbacks to ctx from the implementing
		class define the print.

PageSpec
--------
	A definition of the margin data of the document in question. This class may or may not be reliable
	depending on whether the underlying print drivers have the dimensions of the document and margins
	set correctly.
	
	Methods
	-------
	int getTopMargin()
	int getBottomMargin()
	int getLeftMargin()
	int getRightMargin()

PrintContext
------------
	The object which provides meta-data and drawing access to the printer. An instance of PrintContext will
	be passed to the Printable.print() method. Callbacks from this method define how the document is printed.

	Methods
	-------
	void drawString(String toDraw, float x, float y, PrintFont * font): draw the provided characters in the 
		provided font at the location with upper left corner starting at x, y.
	PageSpec getPageSpec(): get the page meta-data (see PageSpec above).
	PrintFont getFont(String fontName, float size, PrintFont::FontStyle style): Get the font with the given
		name, size and style. (See PrintFont::FontStyle enumeration)

PrintingException
-----------------
	Indicates any error occuring in the print library.
	
	Methods
	-------
	String getMessage(): get the specifics of the error message.
	
PrintFont
---------
	Represents a system font. An instance of PrintFont must be passed to PrintContext.drawString() in order
	to print on the document.
	
	Methods
	-------
	String getName(): Get the sytem name of the font.
	float getSize(): Get the size of the font in pixels.
	FontStyle getStyle(): Get the style of the font. (See PrintFont::FontStyle enumeration)
	float getHeight(): get the height of the font in pixels
	
PrintFont::FontStyle
--------------------
	This is an enumeration representing the supporting styles that can be used for printing. 
	
	The possible values are: BOLD, ITALIC, REGULAR, STRIKEOUT, UNDERLINE
	
========================================================================
Common Problems and FAQs
========================================================================
- I am receiving an error that says "`require': no such file to load -- EtchWin32 (LoadError)"

	It looks like the EtchWin32 library has not been installed. Make sure that you have installed the 
	gem. It should be available from http://rubyforge.org/projects/etch/. 
	
	
- I have specified a network printer called "\\my_machine\my_printer" and it isn't found. Why?

	It could be at least one of two problems. Firstly, the printer needs to be shared and then installed on the machine
	on which the code is running. That doesn't mean the printer needs to be attached physically to that 
	machine, but it does mean if you pull up your list of printers, the printer should show up. Secondly,
	be aware the '\' is a ruby escape character and so the string of the printer would actually be
	"\\\\my_machine\\my_printer".
	
========================================================================
Known Bugs and Coming Features
========================================================================
- You cannot currently mix font styles, for example, there is no way to print a bold and underline at the 
same time. This will be fixed in the next version with an overloaded version of PrintContext.getFont().
