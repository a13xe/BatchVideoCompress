#include <iostream>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include "colorize_text.hpp"
using namespace std;


void compressVideo(const string &inputPath, const string &outputPath, const string &fileName, const string &compressionStrength) 
{
    string command = "ffmpeg -i \"" + inputPath + "/" + fileName + "\" -vcodec h264 -crf " + compressionStrength + " \"" + outputPath + "/" + fileName + "\"";
    system(command.c_str());
}


int main() 
{
    DIR *dir;
    struct stat st;
    struct dirent *ent;
    string inputFolder, outputFolder, compressionStrength;

    system("cls");
    colorized_print("Enter input folder path: ", BLUE, BLACK, 1);
    cin >> inputFolder;
    colorized_print("Enter output folder path: ", BLUE, BLACK, 1);
    cin >> outputFolder;

    if ((dir = opendir(inputFolder.c_str())) != NULL) 
    {
        colorized_print("Your videos: \n", YELLOW, BLACK, 1);
        while ((ent = readdir(dir)) != NULL) 
        {
            string filePath = inputFolder + "/" + ent->d_name;
            if (stat(filePath.c_str(), &st) == 0 && S_ISREG(st.st_mode)) 
            {
                cout << ent->d_name << " (" << st.st_size << " bytes)" << endl;
            }
        }
        closedir(dir);
    } else {
        colorized_print("Could't open input directory.\n", RED, BLACK, 1);
        system("pause");
        return 1;
    }

    colorized_print("Enter compression strength (0-51, where 0 is lossless and 51 is the worst quality): ", BLUE, BLACK, 1);
    cin >> compressionStrength;

    if ((dir = opendir(inputFolder.c_str())) != NULL) 
    {
        while ((ent = readdir(dir)) != NULL) 
        {
            string fileName = ent->d_name;
            compressVideo(inputFolder, outputFolder, fileName, compressionStrength);
        }
        closedir(dir);
    } else {
        colorized_print("Could not open input directory.\n", RED, BLACK, 1);
        system("pause");
        return 1;
    }
    colorized_print("\nFinnished!\n\n", GREEN, BLACK, 1);
    system("pause");

    return 0;
}
