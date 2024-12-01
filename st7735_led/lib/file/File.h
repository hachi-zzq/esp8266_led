#ifndef FILE_H
#define FILE_H

#include <LittleFS.h> // SPIFFS 文件系统

void listFiles(){
    // 初始化 SPIFFS
  if (!LittleFS.begin()) {
    Serial.println("SPIFFS init ");
    return;
  }

    // 列出文件
  Serial.println("文件系统中的文件：");
  Dir dir = LittleFS.openDir("/");
  while (dir.next()) {
    Serial.println(dir.fileName());
  }
}
void deleteFile(){

const char* filePath = "/test.txt";

  // 列出文件
  Serial.println("文件系统中的文件：");
  Dir dir = LittleFS.openDir("/");
  while (dir.next()) {
    Serial.println(dir.fileName());
  }

   if (LittleFS.exists(filePath)) {
    Serial.printf("文件 %s 存在，尝试删除...\n", filePath);

    // 删除文件
    if (LittleFS.remove(filePath)) {
      Serial.println("文件删除成功！");
    } else {
      Serial.println("文件删除失败！");
    }
  } else {
    Serial.printf("文件 %s 不存在！\n", filePath);
  }
}

void openfile(){

  // 打开 GIF 文件
  File gifFile = SPIFFS.open("/test.gif", "r");
  if (!gifFile) {
    Serial.println("not open GIF");
    return;
  }

}



#endif // FILE_H