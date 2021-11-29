import os

HEADER_TYPES = (".h", ".hpp", ".hxx")
SOURCE_TYPES = (".c", ".cpp", ".cxx")
ALL_TYPES = HEADER_TYPES + SOURCE_TYPES

def make_header(a_directory, a_filename, a_exclude):
	a_exclude.add(a_filename)

	with open(a_directory + "/" + a_filename, "w", encoding="utf-8") as out:
		out.write("#pragma once\n")
		out.write("\n")
		out.write('#include "SKSE/Impl/PCH.h"\n')
		out.write("\n")

		tmp = []
		for dirpath, dirnames, filenames in os.walk(a_directory):
			rem = []
			for dirname in dirnames:
				if dirname in a_exclude:
					rem.append(dirname)
			for todo in rem:
				dirnames.remove(todo)

			for filename in filenames:
				if filename not in a_exclude and filename.endswith(HEADER_TYPES):
					path = os.path.join(dirpath, filename)
					tmp.append(os.path.normpath(path))

		files = []
		for file in tmp:
			files.append(file.replace("\\", "/"))

		files.sort()
		for file in files:
			out.write('#include "')
			out.write(file)
			out.write('"\n')

def make_cmake():
	tmp = []
	for directory in { "include", "src" }:
		for dirpath, dirnames, filenames in os.walk(directory):
			for filename in filenames:
				if filename.endswith(ALL_TYPES):
					path = os.path.join(dirpath, filename)
					tmp.append(os.path.normpath(path))

	sources = []
	for file in tmp:
		name = file.replace("\\", "/")
		sources.append(name)
	sources.sort()

	def do_make(a_filename, a_varname, a_files):
		with open("cmake/{}.cmake".format(a_filename), "w", encoding="utf-8") as out:
			out.write("set({}\n".format(a_varname))
			for file in a_files:
				out.write("\t{}\n".format(file))
			out.write(")\n")

	do_make("sourcelist", "SOURCES", sources)

def main():
	root = os.path.split(os.path.dirname(os.path.realpath(__file__)))[0]
	os.chdir(root)
	make_cmake()

	os.chdir(os.path.join(root, "include"))
	make_header("SKSE", "SKSE.h", { "Impl" })
	make_header("RE", "Skyrim.h", { "BSCoreTypes.h", "Offsets.h", "Offsets_NiRTTI.h", "Offsets_RTTI.h", "SFTypes.h" })

if __name__ == "__main__":
	main()
