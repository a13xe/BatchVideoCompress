:video_camera: BatchVideoCompress
==================================================================================================================================================================================================================

This project provides a simple C++ console application for batch compressing video files using FFmpeg. Users can specify input and output directories, select the compression strength, and the program will compress all video files in the input directory, saving them to the output directory.

:toolbox: Requirements
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Before running this program, you must have FFmpeg installed on your system. 
Follow the installation instructions below for your operating system.

<!-- 
WINDOWS FFMPEG INSTALLATION
============================================================================================
-->
<details>
  <summary> :large_blue_circle: Installing FFmpeg on Windows </summary>
  <br>
  
`✅ Step 1.` Download FFmpeg: [direct download link](https://github.com/BtbN/FFmpeg-Builds/releases/download/latest/ffmpeg-master-latest-win64-gpl.zip).

`✅ Step 2.` Extract the downloaded ZIP file to desired location on your PC, such as `C:\Program Files\FFmpeg`

`✅ Step 3.` Press 'Win + R' and type:
```
SystemPropertiesAdvanced
```
   - Click 'Environment Variables...' button.
   - Under 'System variables', find and select 'Path', then click 'Edit'.
   - Click 'New' and add the path to the FFmpeg `bin` directory, e.g. `C:\Program File\FFmpeg\bin`
   - Click 'OK' to close all dialogs.

`✅ Step 4.` To verify the installation open CMD and type
```
ffmpeg -version
```
   
</details>

<!-- 
LINUX FFMPEG INSTALLATION
============================================================================================
-->
<details>
  <summary> :large_blue_circle: Installing FFmpeg on Linux </summary>
  <br>
  
`✅ Step 1.` Open your terminal and run:
```
sudo apt update
sudo apt install ffmpeg
```
`✅ Step 2.` Verify the installation:
```
ffmpeg -version
```

</details>

:joystick: Usage
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

`✅ Step 0.` If you are on Windows you can use the [prebuild]() version

`✅ Step 1.` Clone this repo:
```
git clone https://github.com/a13xe/BatchVideoCompress
```
   
`✅ Step 2.` Compile the C++ code:
```
cd BatchVideoCompress
g++ video_compress.cpp -o video_compress
```

`✅ Step 3.` Run the compiled program from the command line
```
./videoCompressor
```

`✅ Step 4.` Follow the on-screen prompts:

