import os

HEADER_TYPES = (".h", ".hpp")
SOURCE_TYPES = (".c", ".cpp")

def make_mega_header():
	oldDir = os.getcwd()
	os.chdir("include")

	out = open("RE/Skyrim.h", "w", encoding="utf-8")
	out.write("#pragma once\n")
	out.write("\n")
	out.write('#include "' + os.path.normpath("SKSE/Impl/PCH.h") + '"\n')
	out.write("\n")

	files = list()
	for dirpath, dirnames, filenames in os.walk("RE"):
		for filename in filenames:
			if (filename.endswith(HEADER_TYPES)):
				path = os.path.join(dirpath, filename)
				files.append(os.path.normpath(path))

	files.sort()
	for file in files:
		out.write('#include "')
		out.write(file)
		out.write('"\n')

	os.chdir(oldDir)

def make_headers():
	out = open("headerlist.cmake", "w", encoding="utf-8")
	out.write("set(headers ${headers}\n")

	files = list()
	for dirpath, dirnames, filenames in os.walk("include"):
		for filename in filenames:
			if (filename.endswith(HEADER_TYPES)):
				path = os.path.join(dirpath, filename)
				files.append(os.path.normpath(path))

	files.sort()
	for file in files:
		out.write("\t")
		out.write(file)
		out.write("\n")

	out.write(")\n")

def make_src():
	out = open("sourcelist.cmake", "w", encoding="utf-8")
	out.write("set(sources ${sources}\n")

	files = list()
	for dirpath, dirnames, filenames in os.walk("src"):
		for filename in filenames:
			if (filename.endswith(SOURCE_TYPES)):
				path = os.path.join(dirpath, filename)
				files.append(os.path.normpath(path))

	files.sort()
	for file in files:
		out.write("\t")
		out.write(file)
		out.write("\n")

	out.write(")\n")

def main():
	cur = os.path.dirname(os.path.realpath(__file__))
	os.chdir(cur)

	make_mega_header()
	make_headers()
	make_src()

if __name__ == "__main__":
	main()
