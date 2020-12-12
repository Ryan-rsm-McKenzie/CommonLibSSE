import os

HEADER_TYPES = (".h", ".hpp", ".hxx")
SOURCE_TYPES = (".c", ".cpp", ".cxx")
ALL_TYPES = HEADER_TYPES + SOURCE_TYPES

def format(a_directories):
	files = list()
	for directory in a_directories:
		for dirpath, dirnames, filenames in os.walk(directory):
			for filename in filenames:
				if filename.endswith(ALL_TYPES):
					files.append(dirpath + '/' + filename)

	for file in files:
		os.system("clang-format -i -style=file " + file)

def main():
	cur = os.path.dirname(os.path.realpath(__file__))
	os.chdir(cur)
	format(["include"])

if __name__ == "__main__":
	main()
