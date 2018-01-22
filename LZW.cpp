#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <unordered_map>
#include <bitset>

#define MAX_DEF 4096

using namespace std;

bitset<12> convert_int_to_bin(int num)
{
    bitset<12> number (to_string(num));
    return number;
}

void compress(string input, int size, string filename)
{
	unordered_map <string, int> compress_dictionary(MAX_DEF)
	for( unsigned int i = 0; i < 256; i++)
	{
		compress_dictionary[string(1,i)] = i;
	}
	string current_string;
	unsigned int code;
	unsigned int next_code = 256 ;
	ofstream outputFile;
	outputFile.open(filename+'.lzw');
	for (char& c :input)
	{
		current_string = current_string + c;
		if(compress_dictionary.find(current_string) == compress_dictionary.end() )
		{
			if(next_code <= MAX_DEF)
				compress_dictionary.insert(make_pair());
			current_string.erase(current_string.size() - 1);
			outputFile << convert_int_to_bin(compress_dictionary[current_string]);
			current_string = c;

		}
	}
	if(current_string.size())
		outputFile << convert_int_to_bin(compress_dictionary[current_string]);
	outputFile.close();
}

static void show_usage()
{
        cerr << "Usage: \n"
              << "Specify the file that needs to be compressed or decompressed\n"
              <<"lzw -c input    #compress file input\n"
              <<"lzw -d input    #decompress file input\n"
              <<"Compressed data will be found in a file with the same name but with a .lzw extension\n"
              <<"Decompressed data can be found in a file with the same name and a _uncompressed.txt extension\n"
              << endl;
}
int main (int argc, char* argv[]) {
    streampos size;
    char * memblock;

    ifstream file (argv[2], ios::in|ios::binary|ios::ate);
    if (file)
    {
        size = file.tellg();
        memblock = new char[size];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        file.close();
        string input = convert_char_to_string(memblock,size);
        if (string( "-c" ) == argv[1] )
            compress(input,size, argv[2]);
        else
            show_usage();
    }
    else {
    cout << "Unable to open file."<<endl;
    show_usage();
    }
    return 0;
}