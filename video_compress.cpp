#include <iostream>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include "colorize_text.hpp"
using namespace std;


bool isVideoFile(const string &fileName) 
{
    const string videoExtensions[] = {".mp4", ".avi", ".mkv", ".mov", ".flv", ".wmv", ".webm"};
    for (const string &ext : videoExtensions) 
    {
        if (fileName.size() >= ext.size() && fileName.compare(fileName.size() - ext.size(), ext.size(), ext) == 0) 
        {
            return true;
        }
    }
    return false;
}


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
    getline(cin, inputFolder);
    colorized_print("Enter output folder path: ", BLUE, BLACK, 1);
    getline(cin, outputFolder);

    if ((dir = opendir(inputFolder.c_str())) != NULL) 
    {
        colorized_print("Your videos: \n", YELLOW, BLACK, 1);
        while ((ent = readdir(dir)) != NULL) 
        {
            string fileName = ent->d_name;
            string filePath = inputFolder + "/" + fileName;
            if (stat(filePath.c_str(), &st) == 0 && S_ISREG(st.st_mode) && isVideoFile(fileName)) 
            {
                cout << fileName << " (" << st.st_size << " bytes)" << endl;
            }
        }
        closedir(dir);
    } else {
        colorized_print("Couldn't open input directory.\n", RED, BLACK, 1);
        system("pause");
        return 1;
    }

    colorized_print("Enter compression strength (0-51, where 0 is lossless and 51 is the worst quality): ", BLUE, BLACK, 1);
    getline(cin, compressionStrength);

    if ((dir = opendir(inputFolder.c_str())) != NULL) 
    {
        while ((ent = readdir(dir)) != NULL) 
        {
            string fileName = ent->d_name;
            string filePath = inputFolder + "/" + fileName;
            if (stat(filePath.c_str(), &st) == 0 && S_ISREG(st.st_mode) && isVideoFile(fileName)) 
            {
                compressVideo(inputFolder, outputFolder, fileName, compressionStrength);
            }
        }
        closedir(dir);
    } else {
        colorized_print("Could not open input directory.\n", RED, BLACK, 1);
        system("pause");
        return 1;
    }
    colorized_print("\nFinished!\n\n", GREEN, BLACK, 1);
    system("pause");

    return 0;
}
