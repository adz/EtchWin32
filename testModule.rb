#This is just for development testing. It is not either a regresssion test
#or something that should be run unless you know what you are doing.
begin
	require 'EtchWin32'
	env = EtchWin32::PrinterEnv.new()
	puts env.getPrinterCount()

	i = 0;
	while i < env.getPrinterCount()
		puts env.getPrinter(i).getName()
		i = i + 1
	end

	puts "==========================="

	
	puts "==========================="	
	class TestPrintable < EtchWin32::Printable
		
		def print(ctx)

			regularFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::REGULAR)
			
			#Create the fonts
			regularFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::REGULAR)
			boldFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::BOLD)
			italicFont = ctx.getFont("Arial", 14, EtchWin32::PrintFont::ITALIC)
		
			boldItalicFont = ctx.getFontMultistyle("Arial", 14, [EtchWin32::PrintFont::BOLD, EtchWin32::PrintFont::ITALIC])
			
			nextLine = 0;
			
			#draw the line
			ctx.drawString("Line one (should be regular)", 0, nextLine, regularFont)
			
			#increment by font height
			nextLine = nextLine + regularFont.getHeight()
			
			ctx.drawString("Line two (should be bold)", 0, nextLine, boldFont)
			nextLine = nextLine + boldFont.getHeight()
			
			ctx.drawString("Line three (should be italic)", 0, nextLine, italicFont)
			nextLine = nextLine + italicFont.getHeight()
			
			ctx.drawString("Line four (should be bold & italic)", 0, nextLine, boldItalicFont)
			
			
		end
		
	end
	p3 = TestPrintable.new()
	
	printer = env.getPrinter("CutePDF Writer")
	p3.setPrinter(printer)
	p3.printDocument()
	#defaultPrinter = env.getDefaultPrinter()
	#puts defaultPrinter.getName()
rescue Exception=>ex
	puts "Exception occured: " + ex.message + " (" + ex.class.name + ") "
ensure
	gets
end
if ex
	raise ex
end