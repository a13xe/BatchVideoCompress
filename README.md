
:gear: Requirements
-------------------------------------------------------------------------------------------------

Before running this program, you must have FFmpeg installed on your system. 
Follow the installation instructions below for your operating system.

<!-- ============================================================================================
WINDOWS FFMPEG INSTALLATION
============================================================================================ -->
<table>
<td>
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
</table>

<!-- ============================================================================================
LINUX FFMPEG INSTALLATION
============================================================================================ -->
<table>
<td>
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
</table>



:joystick: Usage
-------------------------------------------------------------------------------------------------



`✅ Step 1.` Use the [prebuild version](https://github.com/a13xe/BatchVideoCompress/releases/download/v1.0.0/video_compress.exe) and proceed to step 3.

`✅ Step 2.` Compile and run:
```
git clone https://github.com/a13xe/BatchVideoCompress
cd BatchVideoCompress
g++ video_compress.cpp -o video_compress
./video_compress
```

`✅ Step 3.` Follow the on-screen prompts:

![Screeenshotto](https://github.com/a13xe/BatchVideoCompress/assets/77492646/696338c5-8840-4bb0-a081-c9ea494c1e42)
