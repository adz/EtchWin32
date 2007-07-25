
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
			font = ctx.getFont("Arial", 14, EtchWin32::PrintFont::REGULAR)
			pageSpec = ctx.getPageSpec()
			left = pageSpec.getLeftMargin()
			textBottom = pageSpec.getTopMargin() + font.getHeight()
			ctx.drawString("0 x 0", 0, 0, font)
		end
		
	end
	p3 = TestPrintable.new()
	
	labelPrinter = env.getPrinter("CutePDF Writer")
	p3.setPrinter(labelPrinter)
	p3.printDocument()
rescue Exception=>ex
	puts "Exception occured: " + ex.message + " (" + ex.class.name + ") "
ensure
	gets
end
if ex
	raise ex
end