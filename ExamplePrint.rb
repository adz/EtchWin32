#This is an example of using the Etch library to print styled 
#text to a document.

#You must require the library
require 'EtchWin32'

#Create an instance of PrintEnv. This is the entry point to all printing operations.
env = EtchWin32::PrinterEnv.new()

#Print a list of all the printers
i = 0;
while i < env.getPrinterCount()
	puts env.getPrinter(i).getName()
	i = i + 1
end


printer = env.getDefaultPrinter() #Get the system default printer
#printer = env.getPrinter('CutePDF Writer') #Get a printer by name

puts "Got printer \"#{printer.getName()}\""

#The definition of the Printable object. This will generally be defined in another file.
class TestPrintable < EtchWin32::Printable
	
	def print(ctx)
		
		#Create the fonts
		regularFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::REGULAR)
		boldFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::BOLD)
		italicFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::ITALIC)
		nextLine = 0;
		
		#draw the line
		ctx.drawString("Line one (should be regular)", 0, nextLine, regularFont)
		
		#increment by font height
		nextLine = nextLine + regularFont.getHeight()
		
		ctx.drawString("Line two (should be bold)", 0, nextLine, boldFont)
		nextLine = nextLine + boldFont.getHeight()
		
		ctx.drawString("Line three (should be italic)", 0, nextLine, italicFont)
	end
	
end

printable = TestPrintable.new() #Create an instance of your Printable
printable.setPrinter(printer) #don't forget to set the printer
printable.printDocument() #print away!

