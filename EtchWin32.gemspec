require 'rubygems'

FileUtils.mkdir_p('tmp/lib')
FileUtils.copy('Release/EtchWin32.dll', 'tmp/lib/')
FileUtils.cd('tmp')
SPEC = Gem::Specification.new do |s|
	s.name = "Etch"
	s.version = "0.1.2"
				
	s.author = "Daniel R Somerfield"
	s.email = "dans@outsidein.org"
	s.platform = Gem::Platform::WIN32
	s.summary = "A Win32 Printing Library"
	candidates = Dir.glob("{bin,docs,lib,tests}/**/*")
	s.files = candidates.delete_if do |item|
		item.include?(".svn") || item.include?("rdoc")
	end
	s.require_path = "lib"
end

if $0 == __FILE__
	Gem::manage_gems
	Gem::Builder.new(SPEC).build
end