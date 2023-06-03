#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

int main() {
    std::fstream file1;
    std::string fileBuffer;
    std::string fileArray[154];
    fileBuffer = "#!/bin/bash\n\n";
    
    for(int i = 0; i < 154; i++) {
        fileArray[i] = std::to_string(i + 1);
    }

    for(int i = 0; i < 154; i++) {
        fileBuffer += "ffmpeg -i " + fileArray[i] + ".mp4 ";
        fileBuffer += "-b:a 192k -vn ../mp3/192/" + fileArray[i] + ".mp3\n";
    }

    file1.open("mp4ToMp3.sh", std::ios_base::out);
    file1.write(fileBuffer.c_str(), fileBuffer.size());
    file1.close();
    
    return 0;
}