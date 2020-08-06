import os

HEADER_TYPES = (".h", ".hpp", ".hxx")
SOURCE_TYPES = (".c", ".cpp", ".cxx")

def make_header(a_directory, a_filename, a_exclude):
	a_exclude.add(a_filename)

	out = open(a_directory + "/" + a_filename, "w", encoding="utf-8")
	out.write("#pragma once\n")
	out.write("\n")
	out.write('#include "SKSE/Impl/PCH.h"\n')
	out.write("\n")

	tmp = list()
	for dirpath, dirnames, filenames in os.walk(a_directory):
		rem = list()
		for dirname in dirnames:
			if dirname in a_exclude:
				rem.append(dirname)
		for todo in rem:
			dirnames.remove(todo)

		for filename in filenames:
			if filename not in a_exclude and filename.endswith(HEADER_TYPES):
				path = os.path.join(dirpath, filename)
				tmp.append(os.path.normpath(path))

	files = list()
	for file in tmp:
		files.append(file.replace("\\", "/"))

	files.sort()
	for file in files:
		out.write('#include "')
		out.write(file)
		out.write('"\n')

def main():
	cur = os.path.dirname(os.path.realpath(__file__)) + "/include"
	os.chdir(cur)

	make_header("SKSE", "SKSE.h", {"Impl"})
	make_header("RE", "Skyrim.h", {"BSCoreTypes.h", "Offsets.h", "Offsets_NiRTTI.h", "Offsets_RTTI.h", "SFTypes.h"})

if __name__ == "__main__":
	main()
